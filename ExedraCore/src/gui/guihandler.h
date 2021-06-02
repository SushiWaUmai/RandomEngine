#pragma once
#include <string>
#include <imgui.h>
#include <GLFW/glfw3.h>
#include "src/events/eventdispatcher.h"
#include "imguiwindow.h"
#include "dockspacewindow.h"
#include <memory>
#include <vector>
#include <glm/glm.hpp>

namespace exedra {
	namespace gui {
		class GuiHandler {
		public:
			GuiHandler() = default;
			~GuiHandler();
			void Init(GLFWwindow* _window);
			void Draw();
			void AddWindow(ImGuiWindow* _imguiWindow);
			void RemoveWindow(ImGuiWindow* _imguiWindow);
			inline void SetUserFontScaling(bool set) const { io->FontAllowUserScaling = set; }

			void Clear();
			void SetClearColor(glm::vec4 _rgba);

		private:
			glm::vec4 clearColor;
			ImGuiIO* io;
			std::string glslVersion;
			std::vector<ImGuiWindow*> allWindows;
		};
	}
}
