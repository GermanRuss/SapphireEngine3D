// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Atomic.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
i32 AtomicIncrement(i32 volatile *value)
{
#if SE_PLATFORM_WINDOWS
	return _InterlockedIncrement((volatile long*)value);
#endif
}
//-----------------------------------------------------------------------------
i32 AtomicDecrement(i32 volatile *value)
{
#if SE_PLATFORM_WINDOWS
	return _InterlockedDecrement((volatile long*)value);
#endif
}
//-----------------------------------------------------------------------------
i32 AtomicAdd(i32 volatile *addend, i32 value)
{
#if SE_PLATFORM_WINDOWS
	return _InterlockedExchangeAdd((volatile long*)addend, value);
#endif
}
//-----------------------------------------------------------------------------
i32 AtomicSubtract(i32 volatile *addend, i32 value)
{
#if SE_PLATFORM_WINDOWS
	return _InterlockedExchangeAdd((volatile long*)addend, -value);
#endif
}
//-----------------------------------------------------------------------------
bool CompareAndExchange(i32 volatile *dest, i32 exchange, i32 comperand)
{
#if SE_PLATFORM_WINDOWS
	return _InterlockedCompareExchange((volatile long*)dest, exchange, comperand) == comperand;
#endif
}
//-----------------------------------------------------------------------------
bool CompareAndExchange64(i64 volatile *dest, i64 exchange, i64 comperand)
{
#if SE_PLATFORM_WINDOWS
	return _InterlockedCompareExchange64(dest, exchange, comperand) == comperand;
#endif
}
//-----------------------------------------------------------------------------
void MemoryBarrier()
{
#ifdef _M_AMD64
	__faststorefence();
#elif defined _IA64_
	__mf();
#else
	int Barrier;
	__asm {
		xchg Barrier, eax
	}
#endif
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================