#pragma once
#include <glm/glm.hpp>

namespace exedra {
	namespace ecs {
		struct Transform {
			Transform() {
				transformMatrix = glm::mat4(1.0f);
			}
			Transform(glm::mat4 _matrix) {
				transformMatrix = _matrix;
			}

			glm::mat4 transformMatrix;
		};
	}
}