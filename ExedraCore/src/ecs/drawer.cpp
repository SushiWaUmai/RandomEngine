#include "drawer.h"
#include "transform.h"
#include "src/graphics/camera.h"
#include "src/logging/log.h"

namespace exedra {
	namespace ecs {
		void DrawerSystem::Start() {
			LOG_CORE_TRACE("Initialized Drawer System");
		}

		void DrawerSystem::Update(entt::registry& _registry){
			auto view = _registry.view<const DrawerComponent, const TransformComponent>();
			view.each([](const DrawerComponent& drawer, const TransformComponent& transform) {
				drawer.shader.UseShader();
				drawer.shader.SetUniformVector("objectColor", { 1, 1, 1 });
				drawer.shader.SetUniformVector("lightDirection", { 0.75f, -1, 0.5f });
				drawer.shader.SetUniformMatrix("ViewProjectionMatrix", graphics::Camera::current->GetViewProjectionMatrix());
				drawer.shader.SetUniformMatrix("ModelMatrix", transform.GetTransformMatrix());
				res::DefaultResources::defaultTexture.Bind();
				drawer.mesh.Draw();

				res::Texture::Unbind();
				res::Shader::UnuseShader();
			});
		}
	}
}