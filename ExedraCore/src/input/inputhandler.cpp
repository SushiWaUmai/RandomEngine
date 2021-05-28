#include <iostream>
#include "src/graphics/window.h"
#include "src/logging/log.h"
#include "inputhandler.h"

namespace exedra {
	namespace input {
		void InputHandler::Init() {
			io = &ImGui::GetIO();
		}

		// Set Cursor Mode (GLFW_CURSOR_DISABLED, GLFW_CURSOR_HIDDEN, GLFW_CURSOR_NORMAL)
		void InputHandler::SetCursorInput(int _mode) {
			glfwSetInputMode(*graphics::Window::current, GLFW_CURSOR, _mode);
		}
	}
}