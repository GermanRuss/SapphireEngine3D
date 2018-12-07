#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

#ifdef _WIN32
typedef u32 ThreadID;
#else
typedef pthread_t ThreadID;
#endif

void SetThreadName(ThreadID threadId, const char *threadName);
void Sleep(u32 milliseconds);
void Yield();
u32 GetCPUsCount();
ThreadID GetCurrentThreadID();
u64 GetThreadAffinityMask();

SE_NAMESPACE_END
//=============================================================================