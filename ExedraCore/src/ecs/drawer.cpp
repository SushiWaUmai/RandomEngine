#include "drawer.h"
#include "transform.h"
#include "src/graphics/camera.h"
#include "src/logging/log.h"

namespace exedra {
	namespace ecs {
		void DrawerSystem::Start() {
			LOG_CORE_TRACE("Initialized Drawer System");
		}

		void DrawerSystem::Update(const entt::registry& _registry){
			auto view = _registry.view<const DrawerComponent, const TransformComponent>();
			view.each([](const DrawerComponent& drawer, const TransformComponent& transform) {
				glm::vec3 lightDirection = glm::vec3(0.75f, -1, 0.5f);
				drawer.shader.SetUniformVector("lightDirection", lightDirection);
				drawer.shader.SetUniformMatrix("ViewProjectionMatrix", graphics::Camera::current->GetViewProjectionMatrix());
				drawer.shader.SetUniformMatrix("ModelMatrix", transform.GetTransformMatrix());
				drawer.shader.UseShader();
				drawer.mesh.Draw();
			});
		}
	}
}