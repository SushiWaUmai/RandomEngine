#include "mainmenubar.h"
#include <imgui.h>
#include <nfd.h>
#include "src/logging/log.h"
#include "src/resources/model.h"
#include "src/utils/fileloader.h"

namespace exedra {
	namespace gui {
		void MainMenuBar::DrawImGui() {

            ImGui::ShowDemoWindow();

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
                ImGui::EndMainMenuBar();
            }
		}
	}
}