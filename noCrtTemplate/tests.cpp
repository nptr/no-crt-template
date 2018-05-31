#include <Windows.h>
#include <stdint.h>

#define MYASSERT(cond) ((cond) ? (void)0 : DebugBreak())

void TestRoutine()
{
	// compiler will emit a memset call here
	// ncrt_memory.cpp
	char largeArray[8192] = {};

	// check 64-bit signed operators implemented in
	// ncrt_math64.cpp
	int64_t s = 5;
	s += s;
	MYASSERT(s == 10);
	s -= 1ll;
	MYASSERT(s == 9);
	s *= s;
	MYASSERT(s == 81);
	s /= 9ll;
	MYASSERT(s == 9);
	s %= 8ll;
	MYASSERT(s == 1);
	s <<= 33;
	MYASSERT(s == 8589934592);
	s >>= 33;
	MYASSERT(s == 1);

	// check 64-bit unsigned operators
	// ncrt_math64.cpp
	uint64_t u = 5;
	u += u;
	MYASSERT(u == 10);
	u -= 1ll;
	MYASSERT(u == 9);
	u *= u;
	MYASSERT(u == 81);
	u /= 9ll;
	MYASSERT(u == 9);
	u %= 8ll;
	MYASSERT(u == 1);
	u <<= 33;
	MYASSERT(u == 8589934592);
	u >>= 33;
	MYASSERT(u == 1);

	float f = 10.0;
	int32_t i32		= (int32_t)f;
	uint32_t ui32	= (uint32_t)f;	// _ftoui3
	int64_t i64		= (int64_t)f;	// _ftol3 @ SSE2, _ftol2 @ SSE
	uint64_t ui64	= (uint64_t)f;	// _ftoul3

	f = (float)i32;		
	f = (float)ui32;
	f = (float)i64;		// _ltod3
	f = (float)ui64;	// _ultod3
}