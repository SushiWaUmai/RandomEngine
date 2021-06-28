#include "scene.h"

namespace exedra {
	namespace ecs {
		template <typename T, typename... Args>
		T& Scene::AddComponent(entt::entity _id, Args &&... args) {
			return entityRegistry.emplace<T>(_id, std::forward<Args>(args)...);
		}

		template<typename T>
		T& Scene::GetComponent(entt::entity _id) {
			return entityRegistry.get<T>(_id);
		}

		template<typename T>
		bool Scene::HasComponent(entt::entity _id) {
			return entityRegistry.has<T>(_id);
		}

		template<typename T>
		void Scene::RemoveComponent(entt::entity _id) {
			entityRegistry.remove<T>(_id);
		}
	}
}