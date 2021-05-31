#pragma once
#include "src/ecs/scene.h"
#include "closablewindow.h"

namespace exedra {
	namespace gui {
		class SceneManager : public ClosableWindow {
		public:
			void DrawImGui() override;
		private:
			void DrawEntityTree(ecs::Entity* _entity);
		};
	}
}