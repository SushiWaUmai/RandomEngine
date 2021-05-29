#include "entity.h"
#include <iostream>
#include <memory>

namespace exedra {

	namespace gui { class SceneManager; }

	namespace ecs {
		class Scene {
			friend class gui::SceneManager;

		public:
			static Scene* current;
			Entity root;

			Scene();
			Entity* CreateEntity();
		private:
		};
	}
}