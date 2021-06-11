#pragma once
#include "transform.h"

namespace exedra {
	namespace ecs {
		class CameraComponent {
			CameraComponent() = default;
			CameraComponent(float _fov, float _nearClipPlane, float _farClipPlane) {
				fov = _fov;
				nearClipPlane = _nearClipPlane;
				farClipPlane = _farClipPlane;
			}

			glm::mat4 GetViewMatrix(const Transform& _transform) const {
				glm::vec3 lookDirection = glm::vec4(0, 0, 1, 0) * glm::toMat4(_transform.rotation);
				return glm::lookAt(_transform.position, lookDirection + _transform.position, { 0, 1, 0 });
			}

			glm::mat4 GetProjectionMatrix() const {
				return glm::perspective(glm::radians(fov), screenRatio, nearClipPlane, farClipPlane);
			}

			glm::mat4 GetViewProjectionMatrix(const Transform& _transform) const {
				return GetProjectionMatrix() * GetViewMatrix(_transform);
			}

			static float screenRatio;

		private:
			float fov;
			float nearClipPlane;
			float farClipPlane;
		};
	}
}