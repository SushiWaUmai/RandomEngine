#include "scene.h"
#include "drawer.h"

namespace exedra {
	namespace ecs {
		Scene* Scene::current;

		Scene::Scene() {
			current = this;

			drawerSystem = std::make_unique<DrawerSystem>();
			//std::unique_ptr<System> drawer = std::make_unique<DrawerSystem>();
			//systems.push_back(std::move(drawer));
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

		void Scene::Update() {
			//for (uint32_t i = 0; i < systems.size(); i++) {
			//	systems[i]->Update(entityRegistry);
			//}
		}

		void Scene::UpdateDrawer() {
			drawerSystem->Update(entityRegistry);
		}
	}
}