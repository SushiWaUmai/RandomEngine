#pragma once
#include "imguiwindow.h"
#include <vector>

namespace exedra {
	namespace gui {
		template<typename T>
		class ClosableWindow : public ImGuiWindow {
		public:
			ClosableWindow();
			inline void FocusWindow() { focus = true; }
			static T GetMainWindow();
		protected:
			void CheckForFocus();
			void CheckForClose();
			void CloseWindow();

			bool isOpen = true;
			bool focus = false;

			static std::vector<T*> allWindows;
		};
	}
}
#include "closablewindow.tpp"