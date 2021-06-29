#pragma once
#include <entt/entt.hpp>

namespace exedra {
	namespace ecs {
		class ComponentSystem {
		public:
			virtual void Start();
			virtual void Update(entt::registry& _registry);
		};
	}
}