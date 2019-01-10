#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

class Log
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; }
private:
	static std::shared_ptr<spdlog::logger> s_coreLogger;
	static std::shared_ptr<spdlog::logger> s_clientLogger;
};

SE_NAMESPACE_END
//=============================================================================

// Core log macros
#define SE_CORE_TRACE(...) SE_NAMESPACE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...) SE_NAMESPACE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...) SE_NAMESPACE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...) SE_NAMESPACE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...) SE_NAMESPACE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SE_TRACE(...) SE_NAMESPACE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...) SE_NAMESPACE::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...) SE_NAMESPACE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_ERROR(...) SE_NAMESPACE::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_FATAL(...) SE_NAMESPACE::Log::GetClientLogger()->fatal(__VA_ARGS__) 