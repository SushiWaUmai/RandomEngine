#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

namespace exedra {
	namespace ecs {
		struct TransformComponent {
			TransformComponent() = default;
			TransformComponent(const TransformComponent&) = default;

			glm::mat4 GetTransformMatrix() const {
				return glm::translate(glm::mat4(1.0f), position) * glm::toMat4(rotation) * glm::scale(glm::mat4(1.0f), scale);
			}

			glm::vec3 position = { 0.0f, 0.0f, 0.0f };
			glm::quat rotation = { 0.0f, 0.0f, 0.0f, 1.0f };
			glm::vec3 scale = { 1.0f, 1.0f, 1.0f };
		};
	}
}