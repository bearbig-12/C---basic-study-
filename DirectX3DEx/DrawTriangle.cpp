#include "DrawTriangle.h"



void DrawTriangle::Initialize(HINSTANCE hInstance, int width, int height)
{
}

void DrawTriangle::Destroy()
{
}

void DrawTriangle::Render()
{
}

void DrawTriangle::InitTriangle()
{
	VERTEX vertices[]
	{
		{ 0.0f,   0.0f, 0.0f, {1.0f,0.0f,0.0f,1.0f}},
		{ 0.45f, -0.5f, 0.0f, {0.0f,1.0f,0.0f,1.0f}},
		{-0.45f, -0.5f, 0.0f, {0.0f,0.0f,1.0f,1.0f}}
	};

	// 버텍스 버퍼
	CD3D11_BUFFER_DESC bd(
		sizeof(VERTEX) * 3,
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
	/*D3D11_INPUT_ELEMENT_DESC ied[]
	{
		{"POSITION", 0,  },
		{}
	}*/


		// 파이프라인 조립

		// VS
		// PS
}
