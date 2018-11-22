#pragma once

#include "Core/Base.h"

//=============================================================================
#ifdef SE_COMPILER_MSVC
#	pragma warning(push, 3) // Set warning levels to a quieter level for the STL
#	pragma warning(disable: 4548)
#endif


#include <cstdint>

#ifdef SE_COMPILER_MSVC
#	pragma warning(pop) // Restore warning levels for our code
#endif
//=============================================================================