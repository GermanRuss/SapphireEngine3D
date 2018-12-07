#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;
typedef unsigned int uint;

#if SE_PLATFORM_WINDOWS
typedef long long i64;
typedef unsigned long long u64;
#else
#	if SE_ARCH_64BIT
typedef long i64;
typedef unsigned long u64;
#	else
typedef long long i64;
typedef unsigned long long u64;
#	endif
#endif

#if SE_ARCH_64BIT
typedef u64 uintptr;
#else
typedef u32 uintptr;
#endif

static_assert(sizeof(uintptr) == sizeof(void*), "Incorrect size of uintptr");
static_assert(sizeof(i64) == 8, "Incorrect size of i64");
static_assert(sizeof(i32) == 4, "Incorrect size of i32");
static_assert(sizeof(i16) == 2, "Incorrect size of i16");
static_assert(sizeof(i8) == 1, "Incorrect size of i8");

SE_NAMESPACE_END
//=============================================================================