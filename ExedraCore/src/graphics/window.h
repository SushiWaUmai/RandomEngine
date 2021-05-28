#pragma once
#include <GLFW/glfw3.h>
#include "src/input/inputhandler.h"
#include "src/graphics/renderer.h"
#include "src/gui/guihandler.h"
#include "src/events/event.h"
#include "src/core.h"

namespace exedra {
	namespace graphics {
		class EXD_API Window {
		public:
			static Window* current;

			Window() = default;
			~Window();
			
			void Init(int _width, int _height, const std::string& _title);
			void CreateGLFWwindow();
			void InitRenderer();

			void Update();
			bool ShouldClose() const;
			void ResizeFramebuffer(int _width, int _height);
			void FocusWindow(int _focused);
			void MaximizeWindow(int _maximized);

			inline int GetWidth() const { return width; }
			inline int GetHeight() const { return height; }
			inline std::string GetTitle()& { return title; }
			inline input::InputHandler& GetInput() { return inputHandler; }
			inline gui::GuiHandler& GetImGui() { return imguiHandler; }
			inline graphics::Renderer& GetRenderer() { return renderer; }

			static Window* GetWindow(GLFWwindow* _window);

			operator GLFWwindow* ();
			
		private:
			GLFWwindow* window;
			graphics::Renderer renderer;
			gui::GuiHandler imguiHandler;
			input::InputHandler inputHandler;
			int width;
			int height;
			std::string title;

			static void window_frambuffersize_callback(GLFWwindow* _window, int _width, int _height);
			static void window_focus_callback(GLFWwindow* _window, int _focused);
			static void window_maximize_callback(GLFWwindow* _window, int _maximized);
		};
	}
}