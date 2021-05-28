#include "modeldrawer.h"

namespace exedra {
	namespace ecs {
		void ModelDrawer::Draw() {

			transform.lock()->ApplyShader();
			for (uint32_t i = 0; i < model->meshes.size(); i++) {
				model->meshes[i].Draw();
			}
		}

		void ModelDrawer::SetModel(const std::shared_ptr<resources::Model> _model) {
			model = _model;
		}
	}
}