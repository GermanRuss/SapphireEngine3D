﻿#pragma once

//=============================================================================
// позволяет не сдвигать код автоформатированием
//=============================================================================
#define SE_NAMESPACE_BEGIN   namespace se {
#define SE_NAMESPACE_END     }

//=============================================================================
// SE_STRINGIZE
//=============================================================================
#define SE_STRINGIZE_2( n ) #n
#define SE_STRINGIZE( n ) SE_STRINGIZE_2( n )

//=============================================================================
// Макрос TODO
//=============================================================================
#if SE_COMPILER_MSVC
#	define TODO(msg) __pragma(message(__FILE__ "(" SE_STRINGIZE(__LINE__) ") : TODO: " msg))
#else
#	define TODO( msg ) ((void)0)
#endif

//=============================================================================
// SE_FORCE_INLINE
//=============================================================================
#if SE_COMPILER_MSVC
#	define SE_FORCE_INLINE __forceinline
#elif SE_COMPILER_CLANG
#	if defined(__clang___)
#		if __has_attribute(always_inline)
#			define SE_FORCE_INLINE __attribute__((always_inline)) __inline__
#		else
#			define SE_FORCE_INLINE inline
#		endif
#	endif
#elif SE_COMPILER_GNUC
#	define SE_FORCE_INLINE __attribute__((always_inline)) __inline__
#else
#	define SE_FORCE_INLINE inline
#endif

//=============================================================================
// NORETURN
//=============================================================================
#if SE_COMPILER_MSVC && (SE_COMPILER_MSVC <= 1800)
#	define NORETURN    __declspec(noreturn)
#elif SE_COMPILER_GNUC
#	define NORETURN    __attribute__((noreturn))
#else
#	define NORETURN    [[noreturn]]
#endif

//=============================================================================
// SE_BREAKPOINT
//=============================================================================
#if SE_PLATFORM_LINUX
#	define SE_BREAKPOINT() raise(SIGTRAP)
#elif defined(__ppc__) || defined(__powerpc__)
#	define SE_BREAKPOINT() asm {trap}
#elif SE_COMPILER_GNUC
#	if defined(__i386__) || defined(__x86_64__)
#		define SE_BREAKPOINT() __asm__ __volatile__("int $3\n\t")
#	else
#		define SE_BREAKPOINT() ((void)0)
#	endif
#   define SE_UNREACHABLE() __builtin_unreachable()
#elif SE_COMPILER_MSVC
	extern void __cdecl __debugbreak(void);
#	define SE_BREAKPOINT() __debugbreak()
#	define SE_UNREACHABLE() __assume(false)
#else
#	define SE_BREAKPOINT() ((void)0)
#	define SE_UNREACHABLE()((void)0)
#endif

//=============================================================================
// Assert
//=============================================================================
// How to use:
// Assert(expr);
// AssertMsg(expr, "message");
//-----------------------------------------------------------------------------
// Debug mode under Visual Studio
#if defined(_DEBUG) && SE_COMPILER_MSVC
#	define Assert(expr) static_cast<void>((!!(expr)) || (_CrtDbgBreak(), _ASSERT(expr), false))
#	define AssertMsg(expr, msg) \
			static_cast<void>((!!(expr)) \
			|| (1 != _CrtDbgReportW(_CRT_ASSERT, _CRT_WIDE(__FILE__), __LINE__, nullptr, L"%s", msg)) \
			|| (_CrtDbgBreak(), false))
// Debug mode
#elif defined(_DEBUG)
#	include <assert.h>
#	define Assert(expression) assert(expression)
#	define AssertMsg(expression, message)          \
            do {                                   \
                if (!(expression)) {               \
                    assert(message && expression); \
                    SE_BREAKPOINT();               \
                }                                  \
            } while(false)
#else
#	define Assert(expr) ((void)0)
#	define AssertMsg(expr, msg) ((void)0)
#endif

//=============================================================================
// Put this in the declarations for a class to be uncopyable and unassignable.
//=============================================================================
#define DISALLOW_COPY_AND_ASSIGN(TypeName)         \
    TypeName(const TypeName&) = delete;            \
    TypeName& operator=(const TypeName&) = delete

#define DISALLOW_COPY_MOVE_AND_ASSIGN(TypeName)    \
    TypeName(const TypeName&) = delete;            \
    TypeName& operator=(const TypeName&) = delete; \
    TypeName(const TypeName&&) = delete;           \
    TypeName& operator=(const TypeName&&) = delete;