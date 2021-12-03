#define WIN32_LEAN_AND_MEAN
#include "D3DFrameWork.h"

#

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	D3DFrameWork myFramework;
	myFramework.Initialize(hInstance);
	myFramework.GameLoop();
	myFramework.ReleaseD3D();
	return 0;
}


