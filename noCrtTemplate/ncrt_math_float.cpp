
extern "C"
{
	int _fltused;

#ifdef _M_IX86

	// float to int64 cast
	// on /arch:IA32
	// on /arch:SSE
	// on /arch:SSE2 with /d2noftol3 compiler switch
	__declspec(naked) void _ftol2()
	{
		__asm
		{
			fistp qword ptr[esp - 8]
			mov   edx, [esp - 4]
			mov   eax, [esp - 8]
			ret
		}
	}

	// float to int64 cast on /arch:IA32
	__declspec(naked) void _ftol2_sse()
	{
		__asm
		{
			fistp dword ptr[esp - 4]
			mov   eax, [esp - 4]
			ret
		}
	}

	// float to uint32 cast on / arch:SSE2
	__declspec(naked) void _ftoui3()
	{

	}

	// float to int64 cast on / arch:SSE2
	__declspec(naked) void _ftol3()
	{
		
	}

	// float to uint64 cast on / arch:SSE2
	__declspec(naked) void _ftoul3()
	{

	}

	// int64 to float cast on / arch:SSE2
	__declspec(naked) void _ltod3()
	{

	}

	// uint64 to float cast on / arch:SSE2
	__declspec(naked) void _ultod3()
	{

	}

#endif
}