#pragma once
#include "system.h"
#include "src/resources/mesh.h"
#include "src/resources/shader.h"
#include "src/resources/defaultres.h"
#include "src/logging/log.h"

namespace exedra {
	namespace ecs {
		struct DrawerComponent {
			DrawerComponent() = default;
			DrawerComponent(const res::Mesh& _mesh) {
				mesh = _mesh;
				shader = res::DefaultResources::defaultShader;
			}

			DrawerComponent(const res::Mesh& _mesh, res::Shader& _shader) {
				mesh = _mesh;
				shader = _shader;
			}

			res::Mesh mesh;
			res::Shader shader;
		};

		class DrawerSystem : public System {
		public:
			DrawerSystem() = default;
			DrawerSystem(const DrawerSystem& cpy) = default;
			DrawerSystem(DrawerSystem&& cpy) = default;

			void Start() override;
			void Update(const entt::registry& _registry) override;
		};
	}
}