#pragma once

//=============================================================================
// основное пространство имен
//=============================================================================
#define SE_NAMESPACE               se
#define SE_NAMESPACE_BEGIN         namespace SE_NAMESPACE {
#define SE_NAMESPACE_END           }

//=============================================================================
// внутреннее пространство имен, недоступное пользователю
//=============================================================================
#define SE_NAMESPACE_PRIVATE       sePrivate
#define SE_NAMESPACE_PRIVATE_BEGIN namespace SE_NAMESPACE_PRIVATE {
#define SE_NAMESPACE_PRIVATE_END   }

//=============================================================================
// SE_VOID_MACROS
//=============================================================================
#define SE_VOID_MACROS(_x) { false ? (void)(_x) : (void)0; }

//=============================================================================
// SE_STRINGIZE
//=============================================================================
#define SE_STRINGIZE( _n )   SE_STRINGIZE_2( _n )
#define SE_STRINGIZE_2( _n ) #_n

//=============================================================================
// Макрос TODO
//=============================================================================
#if SE_COMPILER_MSVC
#	define TODO(_msg) __pragma(message(__FILE__ "(" SE_STRINGIZE(__LINE__) ") : TODO: " _msg))
#else
#	define TODO(_msg) SE_VOID_MACROS(_msg)
#endif

//=============================================================================
// SE_FORCE_INLINE
//=============================================================================
#if SE_COMPILER_CLANG
#	if __has_attribute(always_inline)
#		define SE_FORCE_INLINE inline __attribute__((__always_inline__))
#	else
#		define SE_FORCE_INLINE inline
#	endif
#elif SE_COMPILER_GNUC
#	define SE_FORCE_INLINE inline __attribute__( (__always_inline__) )
#elif SE_COMPILER_MSVC
#	define SE_FORCE_INLINE __forceinline
#else
#	define SE_FORCE_INLINE inline
#endif

//=============================================================================
// SE_UNUSED
//=============================================================================
#define SE_UNUSED(_arg) SE_VOID_MACROS(_arg)

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
// Debug mode
#elif defined(_DEBUG)
#	define Assert(expression) assert(expression)
#else
#	define Assert(_expr) SE_VOID_MACROS(_expr)
#endif