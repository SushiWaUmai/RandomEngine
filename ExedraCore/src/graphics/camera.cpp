#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include "window.h"
#include "src/utils/time.h"
#include <cmath>

namespace exedra {
	namespace graphics {

		Camera* Camera::current;

		Camera::Camera() {
			current = this;
			position = glm::vec4(0);
			rotation = glm::vec2(0);
		}

		Camera::Camera(float _fov, float _moveSpeed, float _mouseSensitivity) {
			Init(_fov, _moveSpeed, _mouseSensitivity);
		}

		Camera::Camera(float _fov, float _moveSpeed, float _mouseSensitivity, float _nearClipPlane, float _farClipPlane) {
			Init(_fov, _moveSpeed, _mouseSensitivity);
		}

		void Camera::Init(float _fov, float _moveSpeed, float _mouseSensitivity) {
			Init(_fov, _moveSpeed, _mouseSensitivity, 0.1f, 100.0f);
		}

		void Camera::Init(float _fov, float _moveSpeed, float _mouseSensitivity, float _nearClipPlane, float _farClipPlane) {
			fov = _fov;
			moveSpeed = _moveSpeed;
			mouseSensitivity = _mouseSensitivity;
			nearClipPlane = _nearClipPlane;
			farClipPlane = _farClipPlane;
		}

		void Camera::Update() {

			glm::mat4 cameraMatrix = glm::mat4(1);
			cameraMatrix = glm::rotate(cameraMatrix, rotation.x, { 1, 0, 0 });
			cameraMatrix = glm::rotate(cameraMatrix, rotation.y, { 0, 1, 0 });

			glm::vec3 lookDirection = glm::vec4(0, 0, 1, 0) * cameraMatrix;

			// Input
			graphics::Window* window = graphics::Window::current;
			if(window->GetInput().GetMouseButton(GLFW_MOUSE_BUTTON_RIGHT))
			{
				float dt = utils::Time::GetDeltaTime();

				if (window->GetInput().GetKey(GLFW_KEY_A)) {
					position += glm::vec4(1, 0, 0, 0) * dt * moveSpeed * cameraMatrix;
				}
				else if (window->GetInput().GetKey(GLFW_KEY_D)) {
					position += glm::vec4(-1, 0, 0, 0) * dt * moveSpeed * cameraMatrix;
				}
				if (window->GetInput().GetKey(GLFW_KEY_W)) {
					position += glm::vec4(0, 0, 1, 0) * dt * moveSpeed * cameraMatrix;
				}
				else if (window->GetInput().GetKey(GLFW_KEY_S)) {
					position += glm::vec4(0, 0, -1, 0) * dt * moveSpeed * cameraMatrix;
				}
				if (window->GetInput().GetKey(GLFW_KEY_E)) {
					position += glm::vec4(0, 1, 0, 0) * dt * moveSpeed * cameraMatrix;
				}
				else if (window->GetInput().GetKey(GLFW_KEY_Q)) {
					position += glm::vec4(0, -1, 0, 0) * dt * moveSpeed * cameraMatrix;
				}

				rotation += glm::vec2(-window->GetInput().MouseDeltaY(), window->GetInput().MouseDeltaX()) * mouseSensitivity / 1000.0f;
			}

			glm::vec3 pos = { position.x, position.y, position.z };
			ViewMatrix = glm::lookAt(pos, lookDirection + pos, { 0, 1, 0 });

			ProjectionMatrix = glm::perspective(glm::radians(fov), screenRatio, nearClipPlane, farClipPlane);
		}
	}
}