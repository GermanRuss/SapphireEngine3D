#pragma once

#include "Core/Base.h"

//=============================================================================
#if SE_COMPILER_MSVC
#	pragma warning(push, 3) // Set warning levels to a quieter level for the STL
#endif

#include <cstdint>

//#define GLEW_STATIC
//#include <glew/GL/glew.h>

#if SE_COMPILER_MSVC && SE_PLATFORM_WINDOWS
#	define SDL_MAIN_HANDLED
#endif
#include <SDL2/SDL.h>

#include "Core/Logger.h"

#if SE_COMPILER_MSVC
#	pragma warning(pop)     // Restore warning levels for our code
#endif
//=============================================================================