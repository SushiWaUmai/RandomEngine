#include "scenemanager.h"
#include <imgui.h>

namespace exedra {
	namespace gui {

		void SceneManager::DrawImGui() {
			using namespace ecs;

			CheckForFocus();

			if(ImGui::Begin("Scene Manager", &isOpen)) {
				DrawEntityTree(&Scene::current->root);
				ImGui::End();
			}

			CheckForClose();
		}

		void SceneManager::DrawEntityTree(ecs::Entity* _entity) {
			using namespace ecs;

			if (_entity->children.size() == 0) {
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