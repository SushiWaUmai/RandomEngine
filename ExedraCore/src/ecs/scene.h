#include "entity.h"
#include <iostream>
#include <memory>

namespace exedra {
	namespace ecs {
		class Scene {
		public:
			static Scene* current;

			Scene();
			std::shared_ptr<Entity> CreateEntity();
		private:
			std::vector<std::shared_ptr<Entity>> entities;

		};
	}
}