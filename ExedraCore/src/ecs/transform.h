#pragma once
#include <glm/glm.hpp>
#include "component.h"

namespace exedra {

	namespace gui { class TransformWindow; }

	namespace ecs {
		class Transform : public Component {
			friend class gui::TransformWindow;
		public:
			using Component::Component;
			void Init() override;
			void Init(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
			void Reset();
			void SetTransform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);

			void ApplyShader();
			void Translate(glm::vec3 _position);
			void Rotate(glm::vec3 _rotation);
			void Scale(glm::vec3 _scale);

		private:
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;

			glm::mat4 transform;

			inline void UpdateTransform() { SetTransform(position, rotation, scale); }
		};
	}
}