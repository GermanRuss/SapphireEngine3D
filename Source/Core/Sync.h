#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

#if defined _WIN32
typedef void *SemaphoreHandle;
typedef void *MutexHandle;
typedef void *EventHandle;
typedef volatile long SpinMutexHandle;
#elif defined __linux__
struct SemaphoreHandle
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	i32 count;
};
typedef pthread_mutex_t MutexHandle;
struct EventHandle
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	bool signaled;
	bool manual_reset;
};
typedef volatile i32 SpinMutexHandle;
#endif


class Semaphore
{
public:
	Semaphore(int init_count, int max_count);
	~Semaphore();

	void Signal();

	void Wait();
	bool Poll();

private:
	SemaphoreHandle m_id;
};


class Event
{
public:
	explicit Event(bool manual_reset);
	~Event();

	void Reset();

	void Trigger();

	void Wait();
	void WaitTimeout(u32 timeout_ms);
	bool Poll();

private:
	EventHandle m_id;
};


class SpinMutex
{
public:
	explicit SpinMutex();
	~SpinMutex();

	void Lock();
	void Unlock();

private:
	alignas(64) SpinMutexHandle m_id;
};

class SpinLock
{
public:
	explicit SpinLock(SpinMutex &mutex) : m_mutex(mutex)
	{
		mutex.Lock();
	}
	~SpinLock() { m_mutex.Unlock(); }

	SpinLock(const SpinLock&) = delete;
	void operator=(const SpinLock&) = delete;

private:
	SpinMutex &m_mutex;
};

SE_NAMESPACE_END
//=============================================================================