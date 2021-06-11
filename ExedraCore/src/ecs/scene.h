#pragma once
#include <entt/entt.hpp>
#include <vector>
#include "entity.h"
#include "system.h"
#include "transform.h"
#include "drawer.h"

namespace exedra {

	namespace gui { class SceneManager; }

	namespace ecs {
		class Scene {
			friend class gui::SceneManager;
		public:
			static Scene* current;

			Scene();
			Entity AddEntity();
			void RemoveEntity(Entity _id);
			bool EntityIsValid(entt::entity _id) const;
			template<typename T, typename... Args> T& AddComponent(entt::entity _id, Args &&... args);
			template<typename T> T& GetComponent(entt::entity _id);
		private:
			entt::registry entityRegistry;
		};
	}
}

#include "scene.tpp"