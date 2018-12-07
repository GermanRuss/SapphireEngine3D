#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

i32 AtomicIncrement(i32 volatile *value);
i32 AtomicDecrement(i32 volatile *value);
i32 AtomicAdd(i32 volatile *addend, i32 value);
i32 AtomicSubtract(i32 volatile *addend, i32 value);
bool CompareAndExchange(i32 volatile *dest, i32 exchange, i32 comperand);
bool CompareAndExchange64(i64 volatile *dest, i64 exchange, i64 comperand);
void MemoryBarrier();

SE_NAMESPACE_END
//=============================================================================