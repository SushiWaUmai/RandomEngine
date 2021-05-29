#include "scenemanager.h"
#include <imgui.h>

namespace exedra {
	namespace gui {
		void SceneManager::DrawImGui() {
			using namespace ecs;

			if(ImGui::Begin("Scene Manager")) {

				DrawEntityTree(&Scene::current->root);
				ImGui::End();
			}
		}

		void SceneManager::DrawEntityTree(ecs::Entity* _entity) {
			using namespace ecs;

			if (_entity->GetParent() != nullptr) {
				ImGui::Text(_entity->name.c_str());
				return;
			}
			if (ImGui::TreeNode(_entity->name.c_str())) {

				for (Entity* e : _entity->children) {
					DrawEntityTree(e);
				}

				ImGui::TreePop();
			}
		}
	}
}