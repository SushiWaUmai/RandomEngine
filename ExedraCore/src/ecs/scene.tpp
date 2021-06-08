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
	}
}