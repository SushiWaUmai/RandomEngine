#pragma once
#include <entt/entt.hpp>

namespace exedra {
	namespace ecs {
		class Entity {
		public:
			Entity() = default;
			Entity(entt::entity _id);

			operator entt::entity ();

			template<typename T, typename... Args> T AddComponent(Args &&... args);
			template<typename T> T GetComponent();
		private:
			entt::entity entityID;
		};
	}
}

#include "entity.tpp"