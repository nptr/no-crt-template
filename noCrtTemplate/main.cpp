#include "application.h"
#include "tests.h"

#include <Windows.h>

void __stdcall WinMainCRTStartup()
{
	TestRoutine();

	WinMain(GetModuleHandle(0), NULL, NULL, SW_SHOWDEFAULT);
	ExitProcess(0);
}