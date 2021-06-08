#include "mainmenubar.h"
#include <imgui.h>
#include <nfd.h>
#include "src/logging/log.h"
#include "src/resources/model.h"
#include "src/utils/fileloader.h"
#include "src/graphics/window.h"
#include "src/gui/scenemanager.h"

namespace exedra {
	namespace gui {
		void MainMenuBar::DrawImGui() {

            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::BeginMenu("Open", "CTRL+O")) {
                        if (ImGui::MenuItem("3D Model")) {
                            utils::FileLoader::Load3dObject();
                        }
                        ImGui::EndMenu();
                    }
                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Edit")) {
                    if(ImGui::MenuItem("Nothing in here yet!")) {}
                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Window")) {

                    if (ImGui::BeginMenu("Focus")) {
                        if (ImGui::MenuItem("Scene Manager")) {
                            //SceneManager::GetMainWindow().FocusWindow();
                        }

                        ImGui::EndMenu();
                    }

                    if (ImGui::BeginMenu("Create")) {
                        if (ImGui::MenuItem("Scene Manager")) {
                            //graphics::Window::current->GetImGui().AddWindow(new SceneManager());
                        }

                        ImGui::EndMenu();
                    }

                    ImGui::EndMenu();
                }

                ImGui::EndMainMenuBar();
            }
		}
	}
}