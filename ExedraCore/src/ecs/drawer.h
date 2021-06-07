#pragma once
#include "src/resources/mesh.h"

namespace exedra {
	namespace ecs {
		struct DrawerComponent {
			DrawerComponent() = default;
			DrawerComponent(res::Mesh _mesh) {
				mesh = _mesh;
			}

			res::Mesh mesh;
		};

		class DrawerSystem {

		};
	}
}