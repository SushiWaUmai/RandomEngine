#pragma once
#include "imguiwindow.h"

namespace exedra {
	namespace gui {
		class MainMenuBar : public ImGuiWindow {
		public:
			void DrawImGui() override;
		};
	}
}