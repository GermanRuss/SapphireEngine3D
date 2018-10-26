#pragma once

// DOC https://sourceforge.net/p/predef/wiki/Home/

// Compiler
#define SE_COMPILER_MSVC           0
#define SE_COMPILER_CLANG          0
#define SE_COMPILER_GNUC           0
#define SE_COMPILER_INTEL          0
#define SE_COMPILER_MINGW          0

// Architecture
#define SE_ARCHITECTURE_X64        0
#define SE_ARCHITECTURE_X86        0
#define SE_ARCHITECTURE_A64        0
#define SE_ARCHITECTURE_ARM        0
#define SE_ARCHITECTURE_SPU        0
#define SE_ARCHITECTURE_PPC        0

// Platform
#define SE_PLATFORM_ANDROID        0
#define SE_PLATFORM_EMSCRIPTEN     0
#define SE_PLATFORM_LINUX          0
#define SE_PLATFORM_WINDOWS        0
#define SE_PLATFORM_UWP            0 // Universal Windows platform

// SIMD
#define SE_SIMD_SSE2               0
#define SE_SIMD_NEON               0
#define SE_SIMD_VMX                0

//=============================================================================
// Compiler
//=============================================================================
#if defined(_MSC_VER)
#	undef  SE_COMPILER_MSVC
#	define SE_COMPILER_MSVC _MSC_VER
#	if (SE_COMPILER_MSVC < 1800)
#		error "Current version Visual Studio not support!!"
#	endif
#elif defined(__clang__)
#	undef  SE_COMPILER_CLANG
#	define SE_COMPILER_CLANG __clang_version__
#elif defined(__GNUC__) // Check after Clang, as Clang defines this too
#	undef  SE_COMPILER_GNUC
#	define SE_COMPILER_GNUC (((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
#elif defined(__INTEL_COMPILER)
#	undef  SE_COMPILER_INTEL
#	define SE_COMPILER_INTEL __INTEL_COMPILER
#elif defined(__MINGW32__) || defined(__MINGW64__)
#	undef  SE_COMPILER_MINGW
#	define SE_COMPILER_MINGW 1
#else
#	error "Unknown compiler"
#endif

//=============================================================================
// Architecture
//=============================================================================
#if defined(__x86_64__) || defined(_M_X64)
#	undef  SE_ARCHITECTURE_X64
#	define SE_ARCHITECTURE_X64 1
#elif defined(__i386__) || defined(_M_IX86)
#	undef  SE_ARCHITECTURE_X86
#	define SE_ARCHITECTURE_X86 1
#elif defined(__arm64__) || defined(__aarch64__)
#	undef  SE_ARCHITECTURE_A64
#	define SE_ARCHITECTURE_A64 1
#elif defined(__arm__) || defined(_M_ARM)
#	undef  SE_ARCHITECTURE_ARM
#	define SE_ARCHITECTURE_ARM 1
#elif defined(__SPU__)
#	undef  SE_ARCHITECTURE_SPU
#	define SE_ARCHITECTURE_SPU 1
#elif defined(__ppc__) || defined(_M_PPC) || defined(__CELLOS_LV2__)
#	undef  SE_ARCHITECTURE_PPC
#	define SE_ARCHITECTURE_PPC 1
#else
#	error "Unknown architecture"
#endif

//=============================================================================
// Platform
//=============================================================================
#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY != WINAPI_FAMILY_DESKTOP_APP)
#	undef  SE_PLATFORM_UWP
#	define SE_PLATFORM_UWP 1
#elif defined(_WIN32) || defined(_WIN64)
#	define WINVER 0x0601
#	define _WIN32_WINNT 0x0601
#	undef  SE_PLATFORM_WINDOWS
#	define SE_PLATFORM_WINDOWS _WIN32_WINNT
#elif defined(__ANDROID__)
#	undef  SE_PLATFORM_ANDROID
#	define SE_PLATFORM_ANDROID __ANDROID_API__
#elif  defined(linux) || defined(__linux) || defined(__linux__)
#	undef  SE_PLATFORM_LINUX
#	define SE_PLATFORM_LINUX 1
#elif defined(__EMSCRIPTEN__)
#	undef  SE_PLATFORM_EMSCRIPTEN
#	define SE_PLATFORM_EMSCRIPTEN 1
#endif

//=============================================================================
// SIMD
//=============================================================================
#if defined(__SSE2__) || defined(__i386__) || defined(_M_IX86) || defined(__x86_64__) || defined(_M_X64)
#	undef  SE_SIMD_SSE2
#	define SE_SIMD_SSE2 1
#endif
#if defined(__arm__) || defined(_M_ARM) || defined(__ARM_NEON__)
#	undef  SE_SIMD_NEON
#	define SE_SIMD_NEON 1
#endif
#if defined(_M_PPC) || defined(__CELLOS_LV2__)
#	undef  SE_SIMD_VMX
#	define SE_SIMD_VMX 1
#endif