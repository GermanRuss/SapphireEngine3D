#pragma once

#include "Base.h"

//=============================================================================
#if SE_COMPILER_MSVC
#	pragma warning(push, 3) // Set warning levels to a quieter level for the STL
//#	pragma warning(disable: 0000)
#endif

#include <cstdint>
#include <cstdlib>
#if !SE_PLATFORM_WINDOWS
#	include <cstring>
#	include <malloc.h>
#endif

#if defined(_DEBUG) && SE_COMPILER_MSVC
#	include <crtdbg.h>
#elif defined(_DEBUG)
#	include <cassert>
#endif

#if SE_PLATFORM_WINDOWS
#	include <intrin.h>
#endif

#if SE_COMPILER_MSVC
#	pragma warning(pop)     // Restore warning levels for our code
#endif
//=============================================================================