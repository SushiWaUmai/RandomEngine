#include <iostream>
#include "exedra.h"
#include "debug.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace exedra {
	namespace logging {

		std::shared_ptr<spdlog::logger> Debug::coreLogger;
		std::shared_ptr<spdlog::logger> Debug::clientLogger;

		void Debug::Init() {

			coreLogger = spdlog::stdout_color_mt("CORE");
			clientLogger = spdlog::stdout_color_mt("CLIENT");

			coreLogger->set_level(spdlog::level::trace);
			clientLogger->set_level(spdlog::level::trace);

			LOG_CORE_TRACE("Logging System Initlized.");
		}

		void Debug::GLFWInit() {
			glfwSetErrorCallback(GLFWErrorMessage);

			LOG_CORE_TRACE("GLFW Error Callback Initialized");
		}

		void Debug::OpenGLInit() {

			glDebugMessageCallback(OpenGLLogMessage, nullptr);
				
			LOG_CORE_TRACE("OpenGL Debug Message Callback Initialized");
		}

		void Debug::OpenGLLogMessage(uint32_t _source, uint32_t _type, uint32_t _id, uint32_t _severity, int32_t _length, const char* _message, const void* _userParam) {
			switch (_severity) {
			case GL_DEBUG_SEVERITY_HIGH:
				LOG_CORE_ERROR("[OpenGL DEBUG HIGH] ({0}) {1}", _id, _message);
				break;
			case GL_DEBUG_SEVERITY_MEDIUM:
				LOG_CORE_WARN("[OpenGL DEBUG MEDIUM] ({0}) {1}", _id, _message);
				break;
			case GL_DEBUG_SEVERITY_LOW:
				LOG_CORE_INFO("[OpenGL DEBUG LOW] ({0}) {1}", _id, _message);
				break;
			case GL_DEBUG_SEVERITY_NOTIFICATION:
				LOG_CORE_TRACE("[OpenGL Debug NOTIFICATION] ({0}) {1}", _id, _message);
			}
		}

		void Debug::GLFWErrorMessage(int _error, const char* _description) {
			LOG_CORE_ERROR("[GLFW ERROR {0}] {1}", _error, _description);
		}
	}
}
