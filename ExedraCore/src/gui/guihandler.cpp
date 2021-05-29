#include <GLFW/glfw3.h>
#include "guihandler.h"
#include "src/resources/shader.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "src/logging/log.h"
#include "dockspacewindow.h"
#include "camerawindow.h"
#include "mainmenubar.h"
#include "scenemanager.h"
#include "src/graphics/window.h"

namespace exedra {
	namespace gui {
		void GuiHandler::Init(GLFWwindow* _window) {

			LOG_CORE_TRACE("Initializing ImGUI Renderer..");

#if defined(IMGUI_IMPL_OPENGL_ES2)
			// GL ES 2.0 + GLSL 100
			glslVersion = "#version 100";
#elif defined(__APPLE__)
			// GL 3.2 + GLSL 150
			glslVersion = "#version 150";
#else
			glslVersion = "#version 460";
#endif

			IMGUI_CHECKVERSION();
			ImGui::CreateContext();

			io = &ImGui::GetIO();


			// ContexFlags
			io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
			io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
			io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
			//io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;


			SetUserFontScaling(true);

			// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
			ImGuiStyle& style = ImGui::GetStyle();
			if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				style.WindowRounding = 0.0f;
				style.Colors[ImGuiCol_WindowBg].w = 1.0f;
			}

			LOG_CORE_TRACE("Adding ImGui Windows...");
			// Create dock spce when docking is enabled
			if (io->ConfigFlags & ImGuiConfigFlags_DockingEnable) {
				AddWindow(std::make_shared<DockspaceWindow>());
			}
			AddWindow(std::make_shared<MainMenuBar>());
			AddWindow(std::make_shared<SceneManager>());

			ImGui_ImplGlfw_InitForOpenGL(_window, true);
			ImGui_ImplOpenGL3_Init(glslVersion.c_str());

			LOG_CORE_TRACE("ImGui Renderer initialized successfully.");

			float dpiScale = ImGui::GetPlatformIO().Monitors[0].DpiScale;
			style.ScaleAllSizes(dpiScale);
			io->FontGlobalScale = dpiScale;

			LOG_CORE_TRACE("DPI adjusted to scale: {0}", dpiScale);
		}

		void GuiHandler::Draw() {
			// Unuse shader
			resources::Shader::UnuseShader();

			// Main ImGui Loop
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			for (uint32_t i = 0; i < allWindows.size(); i++) {
				allWindows[i]->DrawImGui();
			}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			// Update and Render additional Platform Windows
			if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				GLFWwindow* backup_current_context = glfwGetCurrentContext();
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
				glfwMakeContextCurrent(backup_current_context);
			}
		}

		void GuiHandler::AddWindow(const std::shared_ptr<ImGuiWindow> _imguiWindow) {
			allWindows.push_back(_imguiWindow);
		}

		void GuiHandler::RemoveWindow(const std::shared_ptr<ImGuiWindow> _imguiWindow) {
			LOG_CORE_WARN("ImGUi Window not removed");
		}

		GuiHandler::~GuiHandler() {
			// Cleanup
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();

			LOG_CORE_TRACE("GUI Handler Destroyed.");
		}
	}
}
