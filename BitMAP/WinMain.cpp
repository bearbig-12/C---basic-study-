#include <Windows.h>
#include "BitmapExample.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	int ret{ 0 };
	try
	{
		BitmapExample myFrameWork;
		if (SUCCEEDED(myFrameWork.Initialize(hInstance)))
		{
			ret = myFrameWork.GameLoop();
		}

	}
	catch (com_exception& e)
	{
		static wchar_t wstr[128]{};
		size_t len;
		mbstowcs_s(&len, wstr, e.what(), 128);	// �ƽ�Ű�ڵ带 �����ڵ��

		D2DFramWork::ShowErrorMsg(wstr);
	}

	

	return ret;
}
