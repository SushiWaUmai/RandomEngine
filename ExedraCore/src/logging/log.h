#pragma once
#include "debug.h"


#define LOG_CORE_TRACE(...)			exedra::logging::Debug::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_DEBUG(...)			exedra::logging::Debug::GetCoreLogger()->debug(__VA_ARGS__)
#define LOG_CORE_INFO(...)			exedra::logging::Debug::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)			exedra::logging::Debug::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)			exedra::logging::Debug::GetCoreLogger()->error(__VA_ARGS__); LOG_DEBUGBREAK()
#define LOG_CORE_CRITICAL(...)		exedra::logging::Debug::GetCoreLogger()->critical(__VA_ARGS__); LOG_DEBUGBREAK()

#define LOG_CLIENT_TRACE(...)		exedra::logging::Debug::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_CLIENT_DEBUG(...)		exedra::logging::Debug::GetClientLogger()->debug(__VA_ARGS__)
#define LOG_CLIENT_INFO(...)		exedra::logging::Debug::GetClientLogger()->info(__VA_ARGS__)
#define LOG_CLIENT_WARN(...)		exedra::logging::Debug::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_CLIENT_ERROR(...)		exedra::logging::Debug::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CLIENT_CRITICAL(...)	exedra::logging::Debug::GetClientLogger()->critical(__VA_ARGS__); LOG_DEBUGBREAK()

#if defined(RE_PLATFORM_WINDOWS)
	#define LOG_DEBUGBREAK() __debugbreak()
#elif defined(RE_PLATFORM_LINUX)
	#include <signal.h>
	#define HZ_DEBUGBREAK() Raise(SIGTRAP)
#else
	#error "Platform doesn't support debugbreak yet!"
#endif

#define LOG_ASSERT(check, msg)	{ if(!check) { LOG_CORE_ERROR("Assertion Failed: File {0}, line {1}: {2}", __FILE__, __LINE__, msg); } }