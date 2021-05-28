#pragma once
#include <glm/glm.hpp>

namespace exedra {
	namespace gui { class CameraWindow; }

	namespace graphics {
		class Camera {
		public:
			friend class gui::CameraWindow;

			static Camera* current;

			Camera();
			Camera(float _fov, float _moveSpeed, float _mouseSensitivity);
			Camera(float _fov, float _moveSpeed, float _mouseSensitivity, float _nearClipPlane, float _farClipPlane);
			void Init(float _fov, float _moveSpeed, float _mouseSensitivity);
			void Init(float _fov, float _moveSpeed, float _mouseSensitivity, float _nearClipPlane, float _farClipPlane);
			void Update();

			inline glm::mat4 GetViewMatrix() const { return ViewMatrix; }
			inline glm::mat4 GetProjectionMatrix() const { return ProjectionMatrix; }
			inline glm::mat4 GetViewProjectionMatrix() const { return ProjectionMatrix * ViewMatrix; }

			float screenRatio;

		private:
			float moveSpeed;
			float mouseSensitivity;
			float fov;
			float nearClipPlane;
			float farClipPlane;

			glm::vec4 position;
			glm::vec2 rotation;

			glm::mat4 ViewMatrix;
			glm::mat4 ProjectionMatrix;
		};
	}
}