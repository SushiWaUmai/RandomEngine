#include "src/ecs/scene.h"
#include "classeditorwindow.h"

namespace exedra {
	namespace gui {
		class SceneManager : public ClosableWindow {
			void DrawImGui() override;
			void DrawEntityTree(ecs::Entity* _entity);
		};
	}
}