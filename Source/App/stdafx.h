#pragma once

#include "Core/Base.h"

//=============================================================================
#ifdef SE_COMPILER_MSVC
#	pragma warning(push, 3) // Set warning levels to a quieter level for the STL
#endif

#include <cstdint>

#define GLEW_STATIC
#include <glew/GL/glew.h>

#include <GLFW/include/GLFW/glfw3.h>

#include "Core/Logger.h"

#ifdef SE_COMPILER_MSVC
#	pragma warning(pop)     // Restore warning levels for our code
#endif
//=============================================================================