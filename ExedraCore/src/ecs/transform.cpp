#include "transform.h"
#include "src/resources/shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include "src/logging/log.h"
#include "src/graphics/window.h"
#include "src/gui/transformwindow.h"

namespace exedra {
	namespace ecs {
		void Transform::Init() {
			Reset();
			scale = glm::vec3(1);

			using namespace gui;
			using namespace graphics;

			std::shared_ptr<TransformWindow> window = std::make_shared<TransformWindow>();
			window->Init(*this);
			Window::current->GetImGui().AddWindow(window);
		}

		void Transform::Init(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) {
			SetTransform(_position, _rotation, _scale);
		}

		void Transform::Reset() {
			using namespace glm;

			transform = mat4(1);
			position = vec3(0);
			rotation = vec3(0);
			scale = vec3(0);
		}

		void Transform::SetTransform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) {
			Reset();

			Translate(_position);
			Rotate(_rotation);
			Scale(_scale);
		}

		void Transform::ApplyShader() {
			resources::Shader::current->SetUniformMatrix("ModelMatrix", transform);
		}

		void Transform::Translate(glm::vec3 _position) {
			position += _position;
			transform = glm::translate(transform, _position);
		}

		void Transform::Rotate(glm::vec3 _rotation) {
			rotation += _rotation;
			transform = glm::rotate(transform, _rotation.x, { 1, 0, 0 });
			transform = glm::rotate(transform, _rotation.y, { 0, 1, 0 });
			transform = glm::rotate(transform, _rotation.z, { 0, 0, 1 });
		}

		void Transform::Scale(glm::vec3 _scale) {
			scale += _scale;
			transform = glm::scale(transform, _scale);
		}
	}
}