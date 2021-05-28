#pragma once
#include <string>
#include <imgui.h>
#include <GLFW/glfw3.h>
#include "src/events/eventdispatcher.h"
#include "imguiwindow.h"
#include "dockspacewindow.h"
#include <memory>
#include <vector>

namespace exedra {
	namespace gui {
		class GuiHandler {
		public:
			GuiHandler() = default;
			~GuiHandler();
			void Init(GLFWwindow* _window);
			void Draw();
			void AddWindow(const std::shared_ptr<ImGuiWindow> _imguiWindow);
			void RemoveWindow(const std::shared_ptr<ImGuiWindow> _imguiWindow);
			inline void SetUserFontScaling(bool set) const { io->FontAllowUserScaling = set; }

		private:
			ImGuiIO* io;
			std::string glslVersion;
			std::vector<std::shared_ptr<ImGuiWindow>> allWindows;
		};
	}
}
