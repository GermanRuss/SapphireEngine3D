// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Thread.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
static_assert(sizeof(ThreadID) == sizeof(::GetCurrentThreadId()), "Not matching");
//-----------------------------------------------------------------------------
void Sleep(u32 milliseconds) 
{ 
	::Sleep(milliseconds);
}
//-----------------------------------------------------------------------------
void Yield() 
{ 
	SE_NAMESPACE::Sleep(0);
}
//-----------------------------------------------------------------------------
u32 GetCPUsCount()
{
	SYSTEM_INFO sys_info;
	GetSystemInfo(&sys_info);

	u32 num = sys_info.dwNumberOfProcessors;
	num = num > 0 ? num : 1;

	return num;
}
//-----------------------------------------------------------------------------
ThreadID GetCurrentThreadID() 
{
	return ::GetCurrentThreadId(); 
}
//-----------------------------------------------------------------------------
u64 GetThreadAffinityMask()
{
	DWORD_PTR affinity_mask = ::SetThreadAffinityMask(::GetCurrentThread(), ~(DWORD_PTR)0);
	::SetThreadAffinityMask(::GetCurrentThread(), affinity_mask);
	return affinity_mask;
}
//-----------------------------------------------------------------------------
static const DWORD MS_VC_EXCEPTION = 0x406D1388;
//-----------------------------------------------------------------------------
#pragma pack(push,8)
typedef struct tagTHREADNAME_INFO
{
	DWORD type;
	LPCSTR name;
	DWORD thread_id;
	DWORD flags;
} THREADNAME_INFO;
#pragma pack(pop)
//-----------------------------------------------------------------------------
void SetThreadName(ThreadID thread_id, const char *thread_name)
{
	THREADNAME_INFO info;
	info.type = 0x1000;
	info.name = thread_name;
	info.thread_id = thread_id;
	info.flags = 0;

	__try
	{
		RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================