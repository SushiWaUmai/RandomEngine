#include "modeldrawer.h"

namespace exedra {
	namespace ecs {
		void Drawer::Init() {
			transform = atttachedEntity->GetComponent<Transform>();
		}
	}
}