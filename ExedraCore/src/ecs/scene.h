#pragma once
#include <entt/entt.hpp>
#include <vector>
#include "entity.h"
#include "componentsystem.h"
#include "drawer.h"
#include "transform.h"
#include <memory>

namespace exedra {

	namespace gui { class SceneManager; }

	namespace ecs {
		class Scene {
			friend class gui::SceneManager;
		public:
			static Scene* current;

			Scene();
			void Init();
			Entity AddEntity();
			void RemoveEntity(Entity _id);
			bool EntityIsValid(entt::entity _id) const;
			template<typename T, typename... Args> T& AddComponent(entt::entity _id, Args &&... args);
			void Update();
			template<typename T> T& GetComponent(entt::entity _id);
			template<typename T> bool HasComponent(entt::entity _id);
			template<typename T> void RemoveComponent(entt::entity _id);
		private:
			std::vector<std::unique_ptr<ComponentSystem>> componentSystems;
			entt::registry entityRegistry;
		};
	}
}

#include "scene.tpp"