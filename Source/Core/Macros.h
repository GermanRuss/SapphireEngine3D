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
#	define TODO( _msg ) ((void)0)
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
// NORETURN
//=============================================================================
#if SE_COMPILER_GNUC
#	define NORETURN    __attribute__((noreturn))
#elif SE_COMPILER_MSVC && (SE_COMPILER_MSVC <= 1800)
#	define NORETURN    __declspec(noreturn)
#else
#	define NORETURN    [[noreturn]]
#endif


//=============================================================================
// SE_UNUSED
//=============================================================================
#define SE_UNUSED(_arg) ((void)_arg)

//=============================================================================
// SE_COUNT_OF
//=============================================================================
// http://cnicholson.net/2011/01/stupid-c-tricks-a-better-sizeof_array/
template<typename T, size_t N>
char(&SIZEOF_ARRAY_REQUIRES_ARRAY_ARGUMENT_SE_COUNTOF(const T(&)[N]))[N];

#define SE_COUNT_OF(_x) sizeof(SIZEOF_ARRAY_REQUIRES_ARRAY_ARGUMENT_SE_COUNTOF(_x) )

//=============================================================================
// SE_BREAKPOINT
//=============================================================================
#if SE_PLATFORM_LINUX
#	define SE_BREAKPOINT() raise(SIGTRAP)
#elif defined(__ppc__) || defined(__powerpc__)
#	define SE_BREAKPOINT() asm {trap}
#elif SE_COMPILER_GNUC && (defined(__i386__) || defined(__x86_64__))
#	define SE_BREAKPOINT() __asm__ __volatile__("int $3\n\t")
#elif SE_COMPILER_MSVC
extern void __cdecl __debugbreak(void);
#	define SE_BREAKPOINT() __debugbreak()
#else
#	define SE_BREAKPOINT() ((void)0)
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