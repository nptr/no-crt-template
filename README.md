This is a simple visual studio C++ project for windows that doesn't use a CRT. No dependency on msvcrt, msvcrtXXX etc.
You are on your own, no C and C++ libraries, just the very basic language constructs and Windows.

Configured for x86 with SSE2 still enabled(!) and should build right out of the box. Produces a 6kb executeable.

Implemented after the great example at the [Handmade Hero forum](https://hero.handmade.network/forums/code-discussion/t/94-guide_-_how_to_avoid_c_c++_runtime_on_windows).

* no RTTI
* no C++ exceptions
* no SEH exceptions
* rounding float/double casting
* ...