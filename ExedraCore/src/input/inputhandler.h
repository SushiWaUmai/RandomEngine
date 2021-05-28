#pragma once
#include <imgui.h>

namespace exedra {
	namespace input {
		class InputHandler {
		public:
			void Init();
			void SetCursorInput(int _mode);
			inline bool GetKey(uint32_t _keycode) const { return io->KeysDown[_keycode]; }
			inline bool GetMouseButton(uint32_t _button) const { return io->MouseDown[_button]; }
			inline bool GetMouseButtonDown(uint32_t _button) const { return io->MouseClicked[_button]; }
			inline float MouseX() const { return io->MousePos.x; }
			inline float MouseY() const { return io->MousePos.y; }
			inline float MouseDeltaX() const { return io->MouseDelta.x; }
			inline float MouseDeltaY() const { return io->MouseDelta.y; }
		private:
			ImGuiIO* io;
		};
	}
}