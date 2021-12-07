#include "DrawTriangle.h"



void DrawTriangle::Initialize(HINSTANCE hInstance, int width, int height)
{
	D3DFramework::Initialize(hInstance, width, height);

	InitPipeline();
	InitTriangle();
}

void DrawTriangle::Destroy()
{
	
	mspVertexBuffer.Reset();
	mspInputLayout.Reset();
	mspPixelShader.Reset();
	mspVertexShader.Reset();

	D3DFramework::Destroy();
}

void DrawTriangle::Render()
{
	UINT offset = 0;
	UINT stride = sizeof(VERTEX);
	mspDeviceContext->IASetVertexBuffers(
		0, 1, mspVertexBuffer.GetAddressOf(), &stride, &offset
	);

	mspDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	//mspDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_);

	mspDeviceContext->Draw(4,0);
	//mspDeviceContext->Draw(4, 0);
	//
}

void DrawTriangle::InitTriangle()
{
	VERTEX vertices[]
	{
		{-0.45f, 0.5f, 0.0f, {0.0f,0.0f,1.0f,1.0f}},
		{ 0.45f, 0.5f, 0.0f, {1.0f,1.0f,0.0f,1.0f}},
		{ -0.45f, -0.5f, 0.0f, {0.0f,1.0f,0.0f,1.0f}},
		{ 0.45f,  -0.5f, 0.0f, {1.0f,0.0f,0.0f,1.0f}}
	
	};

	// 버텍스 버퍼
	CD3D11_BUFFER_DESC bd(
		sizeof(vertices),
		D3D11_BIND_VERTEX_BUFFER,
		D3D11_USAGE_DYNAMIC,			// GPU 읽기, CPU 쓰기
		D3D11_CPU_ACCESS_WRITE
	);
	mspDevice->CreateBuffer(			//그래픽카드가 관리
		&bd, nullptr,
		mspVertexBuffer.ReleaseAndGetAddressOf()
	);

	// 그래픽 카드 버퍼에 데이터를 저장
	D3D11_MAPPED_SUBRESOURCE ms;

	mspDeviceContext->Map(
		mspVertexBuffer.Get(),
		0,
		D3D11_MAP_WRITE_DISCARD,
		0,
		&ms
	);
	memcpy(ms.pData, vertices, sizeof(vertices));
	mspDeviceContext->Unmap(
		mspVertexBuffer.Get(), 0);

}

void DrawTriangle::InitPipeline()
{
	//셰이더 컴파일
	Microsoft::WRL::ComPtr<ID3DBlob> spVS;
	Microsoft::WRL::ComPtr<ID3DBlob> spPS;

	//버텍스 셰이더
	D3DCompileFromFile(
		L"VertexShader.hlsl",
		nullptr,
		nullptr,
		"main",
		"vs_4_0_level_9_3",
		0, 0,
		spVS.GetAddressOf(),
		nullptr
	);

	//픽셀 셰이더
	D3DCompileFromFile(
		L"PixelShader.hlsl",
		nullptr,
		nullptr,
		"main",
		"ps_4_0_level_9_3",
		0, 0,
		spPS.GetAddressOf(),
		nullptr
	);

	//버텍스 셰이더
	mspDevice->CreateVertexShader(
		spVS->GetBufferPointer(),
		spVS->GetBufferSize(),
		nullptr,
		mspVertexShader.ReleaseAndGetAddressOf()
	);

	//픽셀 셰이더
	mspDevice->CreatePixelShader(
		spPS->GetBufferPointer(),
		spPS->GetBufferSize(),
		nullptr,
		mspPixelShader.ReleaseAndGetAddressOf()
	);

	// IA
	D3D11_INPUT_ELEMENT_DESC ied[]
	{
		{"POSITION", 0,  DXGI_FORMAT_R32G32B32_FLOAT,
			0,	// Slot number
			0,	// Offset
			D3D11_INPUT_PER_VERTEX_DATA, // Slot Classification
			0
		},

		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT,
			0,
			12,
			D3D11_INPUT_PER_VERTEX_DATA,
			0
		}
	};

	mspDevice->CreateInputLayout(
		ied,
		2,
		spVS->GetBufferPointer(),
		spVS->GetBufferSize(),
		mspInputLayout.ReleaseAndGetAddressOf()
	);

		// 파이프라인 조립
		// IA
		// VS
		// PS
	mspDeviceContext->IASetInputLayout(mspInputLayout.Get());
	mspDeviceContext->VSSetShader(mspVertexShader.Get(), nullptr, 0);
	mspDeviceContext->PSSetShader(mspPixelShader.Get(), nullptr, 0);
}
