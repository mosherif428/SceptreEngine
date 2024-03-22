#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "Engine.h"
#include <memory>

namespace SceptreEngine
{
	class SCEPTRE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define SC_CORE_TRACE(...)       ::SceptreEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SC_CORE_INFO(...)        ::SceptreEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SC_CORE_WARN(...)        ::SceptreEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SC_CORE_ERROR(...)       ::SceptreEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SC_CORE_CRITICAL(...)    ::SceptreEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define SC_TRACE(...)    ::SceptreEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SC_INFO(...)     ::SceptreEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SC_WARN(...)     ::SceptreEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SC_ERROR(...)    ::SceptreEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SC_CRITICAL(...) ::SceptreEngine::Log::GetClientLogger()->critical(__VA_ARGS__)