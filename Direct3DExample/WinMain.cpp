#define WIN32_LEAN_AND_MEAN
<<<<<<< HEAD
#include "D3DFramework.h"

=======
#include "D3DFrameWork.h"

#
>>>>>>> 1bcc16f5921a1098ffafa30392582ff2043fae5f

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
<<<<<<< HEAD
	D3DFramework myFramework;
	myFramework.Initialize(hInstance);
	myFramework.GameLoop();
	myFramework.Destroy();
	return 0;
}
=======
	D3DFrameWork myFramework;
	myFramework.Initialize(hInstance);
	myFramework.GameLoop();
	myFramework.ReleaseD3D();
	return 0;
}


>>>>>>> 1bcc16f5921a1098ffafa30392582ff2043fae5f
