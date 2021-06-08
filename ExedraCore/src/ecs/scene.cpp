#include "scene.h"

namespace exedra {
	namespace ecs {
		Scene* Scene::current;

		Scene::Scene() {
			current = this;
		}

		Entity Scene::AddEntity() {
			return entityRegistry.create();
		}

		void Scene::RemoveEntity(Entity _id) {
			entityRegistry.destroy(_id);
		}

		bool Scene::EntityIsValid(entt::entity _id) const {
			return entityRegistry.valid(_id);
		}
	}
}