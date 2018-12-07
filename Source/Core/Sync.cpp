// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Sync.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
Semaphore::Semaphore(int init_count, int max_count)
{
	m_id = ::CreateSemaphore(nullptr, init_count, max_count, nullptr);
}
//-----------------------------------------------------------------------------
Semaphore::~Semaphore()
{
	::CloseHandle(m_id);
}
//-----------------------------------------------------------------------------
void Semaphore::Signal()
{
	::ReleaseSemaphore(m_id, 1, nullptr);
}
//-----------------------------------------------------------------------------
void Semaphore::Wait()
{
	::WaitForSingleObject(m_id, INFINITE);
}
//-----------------------------------------------------------------------------
bool Semaphore::Poll()
{
	return WAIT_OBJECT_0 == ::WaitForSingleObject(m_id, 0);
}
//-----------------------------------------------------------------------------
Event::Event(bool manual_reset)
{
	m_id = ::CreateEvent(nullptr, manual_reset, FALSE, nullptr);
}
//-----------------------------------------------------------------------------
Event::~Event()
{
	::CloseHandle(m_id);
}
//-----------------------------------------------------------------------------
void Event::Reset()
{
	::ResetEvent(m_id);
}
//-----------------------------------------------------------------------------
void Event::Trigger()
{
	::SetEvent(m_id);
}
//-----------------------------------------------------------------------------
void Event::WaitTimeout(u32 timeout_ms)
{
	::WaitForSingleObject(m_id, timeout_ms);
}
//-----------------------------------------------------------------------------
void Event::Wait()
{
	::WaitForSingleObject(m_id, INFINITE);
}
//-----------------------------------------------------------------------------
bool Event::Poll()
{
	return WAIT_OBJECT_0 == ::WaitForSingleObject(m_id, 0);
}
//-----------------------------------------------------------------------------
SpinMutex::SpinMutex() : m_id(0) {}
//-----------------------------------------------------------------------------
SpinMutex::~SpinMutex() = default;
//-----------------------------------------------------------------------------
void SpinMutex::Lock()
{
	for (;;) {
		if (m_id == 0 && _interlockedbittestandset(&m_id, 0) == 0) break;
		_mm_pause();
	}
}
//-----------------------------------------------------------------------------
void SpinMutex::Unlock()
{
	_interlockedbittestandreset(&m_id, 0);
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================