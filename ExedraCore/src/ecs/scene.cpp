#include "scene.h"

namespace exedra {
	namespace ecs {
		Scene* Scene::current;

		Scene::Scene() {
			current = this;
			root.Init("Scene Root");
		}

		Entity* Scene::CreateEntity() {
			Entity* result = new Entity();
			root.AddChild(result);
			return result;
		}
	}
}