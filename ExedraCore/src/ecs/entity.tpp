#include "entity.h"
#include "src/logging/log.h"
#include "scene.h"

namespace exedra {
	namespace ecs {
		template<typename T, typename... Args>
		T& Entity::AddComponent(Args &&... args) {
			return Scene::current->AddComponent<T>(entityID, std::forward<Args>(args)...);
		}

		template<typename T>
		T& Entity::GetComponent() {
			return Scene::current->GetComponent<T>(entityID);
		}

		template<typename T>
		bool Entity::HasComponent() {
			return Scene::current->HasComponent<T>(entityID);
		}


		template<typename T>
		void Entity::RemoveComponent() {
			Scene::current->RemoveComponent<T>(entityID);
		}
	}
}