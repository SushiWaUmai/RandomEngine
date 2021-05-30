#include <imgui.h>
#include "dockspacewindow.h"

namespace exedra {
	namespace gui {
		void DockspaceWindow::DrawImGui() {
			ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		}
	}
}