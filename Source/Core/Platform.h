#pragma once

// DOC: https://sourceforge.net/p/predef/wiki/Home/

// Compiler
#define SE_COMPILER_MSVC           0
#define SE_COMPILER_CLANG          0
#define SE_COMPILER_GNUC           0
#define SE_COMPILER_INTEL          0
#define SE_COMPILER_MINGW          0

// CPU
#define SE_CPU_ARM                 0
#define SE_CPU_JIT                 0
#define SE_CPU_MIPS                0
#define SE_CPU_PPC                 0
#define SE_CPU_RISCV               0
#define SE_CPU_X86                 0

// Architecture
#define SE_ARCH_32BIT              0
#define SE_ARCH_64BIT              0

// Endianess
#define SE_CPU_ENDIAN_BIG          0
#define SE_CPU_ENDIAN_LITTLE       0

// Platform
#define SE_PLATFORM_ANDROID        0
#define SE_PLATFORM_EMSCRIPTEN     0
#define SE_PLATFORM_LINUX          0
#define SE_PLATFORM_WINDOWS        0
#define SE_PLATFORM_UWP            0 // Universal Windows platform

// Debug
#define SE_DEBUG                   0

// OpenGL version
#define SE_GL_DESKTOP              0
#define SE_GL_ES                   0

// SIMD
#define SE_SIMD_SSE2               0
#define SE_SIMD_NEON               0
#define SE_SIMD_VMX                0

//=============================================================================
// Compiler
//=============================================================================
#if defined(__clang__)
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
#elif defined(_MSC_VER) && (_MSC_VER >= 1900) // Check after Clang and Intel, since we could be building with either within VS
#	undef  SE_COMPILER_MSVC
#	define SE_COMPILER_MSVC _MSC_VER
#else
#	error "Unknown compiler"
#endif

//=============================================================================
// CPU
//=============================================================================
#if defined(__arm__) || defined(_M_ARM) || defined(__arm64__) || defined(__aarch64__)
#	undef  SE_CPU_ARM
#	define SE_CPU_ARM 1
#	define SE_CACHE_LINE_SIZE 64
#elif defined(__MIPSEL__) || defined(__mips_isa_rev) || defined(__mips64)
#	undef  SE_CPU_MIPS
#	define SE_CPU_MIPS 1
#	define SE_CACHE_LINE_SIZE 64
#elif defined(_M_PPC) || defined(__powerpc__) || defined(__powerpc64__)
#	undef  SE_CPU_PPC
#	define SE_CPU_PPC 1
#	define SE_CACHE_LINE_SIZE 128
#elif defined(__riscv) || defined(__riscv__) || defined(RISCVEL)
#	undef  SE_CPU_RISCV
#	define SE_CPU_RISCV 1
#	define SE_CACHE_LINE_SIZE 64
#elif defined(__i386__) || defined(_M_IX86) || defined(_M_X64) ||  defined(__x86_64__)
#	undef  SE_CPU_X86
#	define SE_CPU_X86 1
#	define SE_CACHE_LINE_SIZE 64
#else // PNaCl doesn't have CPU defined.
#	undef  SE_CPU_JIT
#	define SE_CPU_JIT 1
#	define SE_CACHE_LINE_SIZE 64
#endif

//=============================================================================
// Architecture
//=============================================================================
#if defined(__x86_64__)    || \
	defined(_M_X64)        || \
	defined(__aarch64__)   || \
	defined(__64BIT__)     || \
	defined(__mips64)      || \
	defined(__powerpc64__) || \
	defined(__ppc64__)     || \
	defined(__LP64__)
#	undef  SE_ARCH_64BIT
#	define SE_ARCH_64BIT 64
#else
#	undef  SE_ARCH_32BIT
#	define SE_ARCH_32BIT 32
#endif

//=============================================================================
// Endianess
//=============================================================================
#if SE_CPU_PPC
#	undef  SE_CPU_ENDIAN_BIG
#	define SE_CPU_ENDIAN_BIG 1
#else
#	undef  SE_CPU_ENDIAN_LITTLE
#	define SE_CPU_ENDIAN_LITTLE 1
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
// DEBUG MODE
//=============================================================================
// Win32 compilers use _DEBUG for specifying debug builds.
// for MinGW, we set DEBUG
#if defined(_DEBUG) || defined(DEBUG)
#	undef  SE_DEBUG
#	define SE_DEBUG 1
#endif

//=============================================================================
// OPENGL VERSION
//=============================================================================
#if SE_PLATFORM_LINUX || SE_PLATFORM_WINDOWS
#	undef  SE_GL_DESKTOP
#	define SE_GL_DESKTOP 1
#else
#	undef  SE_GL_ES
#	define SE_GL_ES 1
#endif

//=============================================================================
// SIMD
//=============================================================================
#if defined(__SSE2__) || defined(__i386__) || defined(__amd64__) || defined(_M_IX86) || defined(__x86_64__) || defined(_M_X64)
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