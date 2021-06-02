#include "scene.h"

namespace exedra {
	namespace ecs {
		Scene* Scene::current;

		Scene::Scene() {
			current = this;
		}

		entt::entity Scene::AddEntity() {
			return entityRegistry.create();
		}

		void Scene::RemoveEntity(entt::entity _id) {
			entityRegistry.destroy(_id);
		}

		bool Scene::EntityIsValid(entt::entity _id) const {
			return entityRegistry.valid(_id);
		}
	}
}