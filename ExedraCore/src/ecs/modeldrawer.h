#pragma once
#include "drawer.h"
#include "src/resources/model.h"

namespace exedra {
	namespace ecs {
		class ModelDrawer : public Drawer {
		public:
			using Drawer::Drawer;
			void Draw() override;
			void SetModel(const std::shared_ptr<resources::Model> _model);

		private:
			std::shared_ptr<resources::Model> model;
		};
	}
}