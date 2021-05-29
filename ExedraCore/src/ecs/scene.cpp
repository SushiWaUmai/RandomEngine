#include "scene.h"

namespace exedra {
	namespace ecs {
		Scene* Scene::current;

		Scene::Scene() {
			current = this;
			root.Init("Scene Root");
		}

		Entity* Scene::CreateEntity() {
			//std::shared_ptr<Entity> result = std::make_shared<Entity>();
			Entity* result = new Entity();
			root.AddChild(result);
			//entities.push_back(result);
			return result;
		}
	}
}