#pragma once
#include <entt/entt.hpp>

namespace exedra {

	namespace gui { class SceneManager; }

	namespace ecs {
		class Scene {
			friend class gui::SceneManager;
		public:
			static Scene* current;

			Scene();
			entt::entity AddEntity();
			void RemoveEntity(entt::entity _id);
			bool EntityIsValid(entt::entity _id) const;
			template<typename T, typename... Args> T& AddComponent(entt::entity _id, Args &&... args);
			template<typename T> T& GetComponent(entt::entity _id);
		private:
			entt::registry entityRegistry;
		};
	}
}

#include "scene.tpp"