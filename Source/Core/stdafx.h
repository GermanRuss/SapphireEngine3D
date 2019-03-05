#pragma once

#include "Base.h"

//=============================================================================
#if SE_COMPILER_MSVC
#	pragma warning(push, 1) // Set warning levels to a quieter level for the STL
#	pragma warning(disable: 4265)
#	pragma warning(disable: 4548)
#	pragma warning(disable: 4640)
#endif

#include <cstdint>

#if SE_DEBUG && SE_COMPILER_MSVC
#	include <crtdbg.h>
#elif SE_DEBUG
#	include <cassert>
#endif

#if SE_COMPILER_MSVC
#	pragma warning(pop)     // Restore warning levels for our code
#endif
//=============================================================================