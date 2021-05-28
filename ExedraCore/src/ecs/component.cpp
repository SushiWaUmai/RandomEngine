#include "component.h"

namespace exedra {
	namespace ecs {
		Component::Component(Entity& _attached) {
			atttachedEntity = _attached;
		}
	}
}