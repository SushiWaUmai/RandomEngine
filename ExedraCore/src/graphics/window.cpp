#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "window.h"
#include "src/input/inputhandler.h"
#include "src/logging/log.h"
#include "src/events/event.h"

namespace exedra {
	namespace graphics {

		Window *Window::current;

		Window::~Window() {
			glfwDestroyWindow(window);
			LOG_CORE_TRACE("GLFW Window Destroyed.");
		}

		// Init attributes
		void Window::Init(int _width, int _height, const std::string& _title) {

			width = _width;
			height = _height;
			title = _title;

#if defined(IMGUI_IMPL_OPENGL_ES2)
			// GL ES 2.0 + GLSL 100
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
			glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
			// GL 3.2 + GLSL 150
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
			glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
			glfwWindowHint(GLFW_SCALE_TO_MONITOR, GL_TRUE);
			//glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);

			current = this;
			Camera::current->screenRatio = (float)_width / _height;

		}

		// Initializes the GLFW window and the input handler
		void Window::CreateGLFWwindow() {

			LOG_CORE_TRACE("Creating GLFW Window...");

			window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
			if (!window) {
				LOG_CORE_ERROR("Failed to create GLFW window");
				LOG_CORE_TRACE("Terminating GLFW...");
				glfwTerminate();
			}


			glfwMakeContextCurrent(window);
			LOG_CORE_TRACE("GLFW window successfully created.");

			glfwSetFramebufferSizeCallback(window, window_frambuffersize_callback);
			glfwSetWindowFocusCallback(window, window_focus_callback);
			glfwSetWindowMaximizeCallback(window, window_maximize_callback);

			glfwSetWindowUserPointer(window, static_cast<void*>(this));
		}

		void Window::InitRenderer() {
			renderer.Init(window);
			imguiHandler.Init(window);
			inputHandler.Init();
		}

		void Window::Update() {
			renderer.Draw();
			imguiHandler.Draw();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		bool Window::ShouldClose() const {
			return glfwWindowShouldClose(window);
		}

		Window* Window::GetWindow(GLFWwindow* _window) {
			return static_cast<Window*>(glfwGetWindowUserPointer(_window));
		}

		Window::operator GLFWwindow* () {
			return window;
		}

		// Callbacks
		void Window::window_frambuffersize_callback(GLFWwindow* _window, int _width, int _height) {
			graphics::Window* handler = graphics::Window::GetWindow(_window);
			handler->ResizeFramebuffer(_width, _height);
			Camera::current->screenRatio = (float)_width / _height;
		}

		void Window::ResizeFramebuffer(int _width, int _height) {
			width = _width;
			height = _height;

			glViewport(0, 0, width, height);
			//Update();
		}

		void Window::window_focus_callback(GLFWwindow* _window, int _focused) {
			graphics::Window* handler = graphics::Window::GetWindow(_window);
			handler->FocusWindow(_focused);
		}

		void Window::FocusWindow(int _focused) {
			if (_focused) {
				LOG_CORE_TRACE("Window \"{0}\" was set to current.", title);
				current = this;
			}
		}

		void Window::window_maximize_callback(GLFWwindow* _window, int _maximized) {
			graphics::Window* handler = graphics::Window::GetWindow(_window);
			handler->MaximizeWindow(_maximized);
		}

		void Window::MaximizeWindow(int _maximized) {
			LOG_CORE_TRACE("Window \"{0}\" was {1}.", title, _maximized ? "maximized" : "minimized");
		}
	}
}