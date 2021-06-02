#include "closablewindow.h"
#include <imgui.h>
#include "src/logging/log.h"
#include "src/graphics/window.h"

namespace exedra {
	namespace gui {
		template<typename T>
		std::vector<T*> ClosableWindow<T>::allWindows;

		template<typename T>
		ClosableWindow<T>::ClosableWindow() {
			allWindows.push_back((T*)this);
		}

		template<typename T>
		void ClosableWindow<T>::CheckForFocus() {
			if (focus) {
				ImGui::SetNextWindowFocus();
				focus = false;
				isOpen = true;
			}
		}

		template<typename T>
		void ClosableWindow<T>::CheckForClose() {
			if (!isOpen) {
				CloseWindow();
			}
		}

		template<typename T>
		void ClosableWindow<T>::CloseWindow() {
			if (allWindows.size() > 1) {
				graphics::Window::current->GetImGui().RemoveWindow(this);
			}
		}

		template<typename T>
		T ClosableWindow<T>::GetMainWindow() {
			return allWindows[0];
		}
	}
}