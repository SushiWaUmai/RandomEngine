#pragma once
#include "imguiwindow.h"

namespace exedra {
	namespace gui {
		class DockspaceWindow : public ImGuiWindow {
		public:
			void DrawImGui() override;
		};
	}
}