#include "closablewindow.h"
#include <imgui.h>
#include "src/logging/log.h"

namespace exedra {
	namespace gui {
		void ClosableWindow::CheckForFocus() {
			if (focus) {
				ImGui::SetNextWindowFocus();
				focus = false;
				isOpen = true;
			}
		}
		void ClosableWindow::CheckForClose() {
			if (!isOpen) {
				LOG_CORE_TRACE("ImGui Window was closed.");
			}
		}
	}
}