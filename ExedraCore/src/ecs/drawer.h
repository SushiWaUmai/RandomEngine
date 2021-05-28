#pragma once
#include <memory>
#include "component.h"
#include "transform.h"

namespace exedra {
	namespace ecs {
		class Drawer : public Component {
		public:
			using Component::Component;
			virtual void Draw() = 0;
			void Init() override;
		protected:
			std::shared_ptr<Transform> transform;
		};
	}
}