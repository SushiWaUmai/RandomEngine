#include "cameramovement.h"
#include "transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include "src/graphics/window.h"
#include <glfw/glfw3.h>
#include "src/utils/time.h"

namespace exedra {
	namespace ecs {
		void CameraMovementSystem::Start() {

		}

		void CameraMovementSystem::Update(entt::registry& _registry) {

			auto view = _registry.view<CameraMovementComponent, TransformComponent>();
			view.each([](CameraMovementComponent& camMovement, TransformComponent& camTransform) {

				glm::mat4 camRotationMatrix = glm::toMat4(camTransform.rotation);
				// Input
				graphics::Window* window = graphics::Window::current;
				if (window->GetInput().GetMouseButton(GLFW_MOUSE_BUTTON_RIGHT))
				{
					float dt = utils::Time::GetDeltaTime();
					glm::vec4 addVector(0.0f);

					if (window->GetInput().GetKey(GLFW_KEY_D))
						addVector += glm::vec4(1, 0, 0, 0) * camRotationMatrix;
					else if (window->GetInput().GetKey(GLFW_KEY_A))
						addVector += glm::vec4(-1, 0, 0, 0) * camRotationMatrix;
					if (window->GetInput().GetKey(GLFW_KEY_W))
						addVector += glm::vec4(0, 0, 1, 0) * camRotationMatrix;
					else if (window->GetInput().GetKey(GLFW_KEY_S))
						addVector += glm::vec4(0, 0, -1, 0) * camRotationMatrix;
					if (window->GetInput().GetKey(GLFW_KEY_E))
						addVector += glm::vec4(0, 1, 0, 0) * camRotationMatrix;
					else if (window->GetInput().GetKey(GLFW_KEY_Q))
						addVector += glm::vec4(0, -1, 0, 0) * camRotationMatrix;

					camTransform.position += glm::vec3(addVector.x, addVector.y, addVector.z) * dt * camMovement.moveSpeed;

					camMovement.mouseInput += glm::vec2(window->GetInput().MouseDeltaY(), -window->GetInput().MouseDeltaX()) * camMovement.mouseSensitivity / 1000.0f;

					//LOG_CORE_DEBUG("Mouse Input: ({0}, {1})", camMovement.mouseInput.x, camMovement.mouseInput.y);
					glm::quat pitch = glm::quat(glm::vec3(camMovement.mouseInput.x, 0, 0));
					glm::quat yaw = glm::quat(glm::vec3(0, camMovement.mouseInput.y, 0));
					camTransform.rotation = pitch * yaw;
					//camTransform.rotation = glm::quat(glm::vec3(/*camMovement.mouseInput.x*/0, camMovement.mouseInput.y, 0));
					//camTransform.rotation = glm::quat(euler + glm::vec3(-window->GetInput().MouseDeltaY(), window->GetInput().MouseDeltaX(), 0) * camMovement.mouseSensitivity / 1000.0f);
				}
			});
		}
	}
}