#pragma once

#include "DebugOutput.h"
#include "FormatString.h"

//=============================================================================
SE_NAMESPACE_BEGIN

template<bool>
void ThrowIf(std::string &&)
{
}

template<>
inline void ThrowIf<true>(std::string &&msg)
{
	throw std::runtime_error(std::move(msg));
}

template<bool bThrowException, typename... ArgsType>
void LogError(const char *Function, const char *FullFilePath, int Line, const ArgsType&... Args)
{
	std::string FileName(FullFilePath);
	auto LastSlashPos = FileName.find_last_of("/\\");
	if (LastSlashPos != std::string::npos)
		FileName.erase(0, LastSlashPos + 1);
	auto Msg = FormatString(Args...);
	if (DebugMessageCallback != nullptr)
	{
		DebugMessageCallback(bThrowException ? DebugMessageSeverity::FatalError : DebugMessageSeverity::Error, Msg.c_str(), Function, FileName.c_str(), Line);
	}
	else
	{
		// No callback set - output to cerr
		std::cerr << "Sapphire Engine: " << (bThrowException ? "Fatal Error" : "Error") << " in " << Function << "() (" << FileName << ", " << Line << "): " << Msg << '\n';
	}
	ThrowIf<bThrowException>(std::move(Msg));
}

SE_NAMESPACE_END
//=============================================================================

#define LOG_ERROR(...) \
	do{ \
		SE_NAMESPACE::LogError<false>(__FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__); \
	}while(false)


#define LOG_ERROR_ONCE(...)                 \
	do{                                     \
		static bool IsFirstTime = true;     \
		if(IsFirstTime)                     \
		{                                   \
			LOG_ERROR(##__VA_ARGS__);       \
			IsFirstTime = false;            \
		}                                   \
	}while(false)


#define LOG_ERROR_AND_THROW(...)\
	do{                                     \
		SE_NAMESPACE::LogError<true>(__FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__);\
	}while(false)


#define LOG_DEBUG_MESSAGE(Severity, ...)\
do{                                                     \
    auto _msg = SE_NAMESPACE::FormatString( __VA_ARGS__ );\
    if(SE_NAMESPACE::DebugMessageCallback != nullptr) SE_NAMESPACE::DebugMessageCallback( Severity, _msg.c_str(), nullptr, nullptr, 0 );\
}while(false)

#define LOG_ERROR_MESSAGE(...)    LOG_DEBUG_MESSAGE(SE_NAMESPACE::DebugMessageSeverity::Error,   ##__VA_ARGS__)
#define LOG_WARNING_MESSAGE(...)  LOG_DEBUG_MESSAGE(SE_NAMESPACE::DebugMessageSeverity::Warning, ##__VA_ARGS__)
#define LOG_INFO_MESSAGE(...)     LOG_DEBUG_MESSAGE(SE_NAMESPACE::DebugMessageSeverity::Info,    ##__VA_ARGS__)


#define LOG_DEBUG_MESSAGE_ONCE(Severity, ...)\
do{                                                \
    static bool IsFirstTime = true;                \
    if(IsFirstTime)                                \
    {                                              \
        LOG_DEBUG_MESSAGE(Severity, ##__VA_ARGS__);\
        IsFirstTime = false;                       \
    }                                              \
}while(false)

#define LOG_ERROR_MESSAGE_ONCE(...)    LOG_DEBUG_MESSAGE_ONCE(SE_NAMESPACE::DebugMessageSeverity::Error,   ##__VA_ARGS__)
#define LOG_WARNING_MESSAGE_ONCE(...)  LOG_DEBUG_MESSAGE_ONCE(SE_NAMESPACE::DebugMessageSeverity::Warning, ##__VA_ARGS__)
#define LOG_INFO_MESSAGE_ONCE(...)     LOG_DEBUG_MESSAGE_ONCE(SE_NAMESPACE::DebugMessageSeverity::Info,    ##__VA_ARGS__)


#define CHECK(Expr, Severity, ...)\
do{                               \
    if( !(Expr) )                 \
    {                             \
        LOG_DEBUG_MESSAGE(Severity, ##__VA_ARGS__);\
    }                             \
}while(false)

#define CHECK_ERR(Expr, ...)  CHECK(Expr, SE_NAMESPACE::DebugMessageSeverity::Error,   ##__VA_ARGS__)
#define CHECK_WARN(Expr, ...) CHECK(Expr, SE_NAMESPACE::DebugMessageSeverity::Warning, ##__VA_ARGS__)
#define CHECK_INFO(Expr, ...) CHECK(Expr, SE_NAMESPACE::DebugMessageSeverity::Info,    ##__VA_ARGS__)

#define CHECK_THROW(Expr, ...)\
do{                               \
    if( !(Expr) )                 \
    {                             \
        LOG_ERROR_AND_THROW(##__VA_ARGS__);\
    }                             \
}while(false)