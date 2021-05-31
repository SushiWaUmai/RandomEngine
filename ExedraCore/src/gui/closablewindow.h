#pragma once
#include "imguiwindow.h"

namespace exedra {
	namespace gui {
		class ClosableWindow : public ImGuiWindow {
		public:
			inline void FocusWindow() { focus = true; }
		protected:
			void CheckForFocus();
			void CheckForClose();

			bool isOpen = true;
			bool focus;
		};
	}
}