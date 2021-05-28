#include "scene.h"

namespace exedra {
	namespace ecs {
		Scene* Scene::current;

		Scene::Scene() {
			current = this;
		}

		std::shared_ptr<Entity> Scene::CreateEntity() {
			std::shared_ptr<Entity> result = std::make_shared<Entity>();
			entities.push_back(result);
			return result;
		}
	}
}