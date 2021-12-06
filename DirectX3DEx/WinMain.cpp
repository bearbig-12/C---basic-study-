#define WIN32_LEAN_AND_MEAN
#include "D3DFramework.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{

	D3DFramework myFramework;
	myFramework.Initialize(hInstance);
	myFramework.GameLoop();
	myFramework.Destroy();
	return 0;
}



