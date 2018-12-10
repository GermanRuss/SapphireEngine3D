#pragma once

#include "DefaultAllocator.h"
#include "DelegateList.h"
#include "Str.h"

//=============================================================================
SE_NAMESPACE_BEGIN

class Path;

class LogProxy
{
	friend class Log;
public:
	LogProxy(Log &log, const char *system, IAllocator &allocator);
	~LogProxy();

	LogProxy& operator <<(const char *message);
	LogProxy& operator <<(float message);
	LogProxy& operator <<(i32 message);
	LogProxy& operator <<(u32 message);
	LogProxy& operator <<(u64 message);
	LogProxy& operator <<(const String &path);
	LogProxy& operator <<(const Path &path);
	LogProxy& Substring(const char *str, int start, int length);

private:
	LogProxy(const LogProxy&);
	void operator = (const LogProxy&);

	IAllocator &m_allocator;
	String m_system;
	String m_message;
	Log &m_log;
};




SE_NAMESPACE_END
//=============================================================================

#define SE_LOG_INFO(x) 
#define SE_LOG_WARNING(x) 
#define SE_LOG_ERROR(x) 
#define SE_LOG_FATAL(x) 