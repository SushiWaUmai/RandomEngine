#pragma once
#include "componentsystem.h"
#include <entt/entt.hpp>
#include <glm/glm.hpp>

namespace exedra {
	namespace ecs {
		struct CameraMovementComponent {
			float mouseSensitivity = 1;
			float moveSpeed = 5;
		};

		class CameraMovementSystem : public ComponentSystem {
		public:
			void Start() override;
			void Update(entt::registry& _registry) override;
		};
	}
}