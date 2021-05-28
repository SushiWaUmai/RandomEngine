#pragma once
#include <iostream>
#include "src/core.h"

#include <chrono>
#include <spdlog/stopwatch.h>
#include <spdlog/spdlog.h>

namespace exedra {
	namespace logging {

		class EXD_API Debug {

		public:
			static void Init();
			static void OpenGLInit();
			static void GLFWInit();
			inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return coreLogger; }
			inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return clientLogger; }

		private:
			static void OpenGLLogMessage(uint32_t source, uint32_t type, uint32_t id, uint32_t severity, int32_t length, const char* message, const void* userParam);
			static void GLFWErrorMessage(int _error, const char* _description);
			static std::shared_ptr<spdlog::logger> coreLogger;
			static std::shared_ptr<spdlog::logger> clientLogger;
		};
	}
}