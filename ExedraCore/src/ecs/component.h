#pragma once
#include "entity.h"

namespace exedra {
	namespace ecs {

		class Component {
		public:
			Component(Entity& _attached);
			virtual void Init() = 0;
		protected:
			Entity atttachedEntity;
		};
	}
}