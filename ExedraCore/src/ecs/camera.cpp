#include "camera.h"
#include "drawer.h"
#include "transform.h"

namespace exedra {
	namespace ecs {
		void CameraSystem::Start() {
			LOG_CORE_DEBUG("Create Camera System");
		}

		void CameraSystem::Update(entt::registry& _registry) {
			auto view = _registry.view<const CameraComponent, const TransformComponent>();
			view.each([&](const CameraComponent& cam, const TransformComponent& camTransform) {

				cam.Bind();
				cam.Clear();

				auto view = _registry.view<const DrawerComponent, const TransformComponent>();
				view.each([&](const DrawerComponent& drawer, const TransformComponent& transform) {

					// Drawer Shader
					drawer.shader.UseShader();
					drawer.shader.SetUniformVector("objectColor", { 1, 1, 0 });
					drawer.shader.SetUniformVector("lightDirection", { 0.75f, -1, 0.5f });
					drawer.shader.SetUniformMatrix("ViewProjectionMatrix", cam.GetViewProjectionMatrix(camTransform));
					drawer.shader.SetUniformMatrix("ModelMatrix", transform.GetTransformMatrix());

					// Bind Texture
					res::DefaultResources::defaultTexture.Bind();
					drawer.mesh.Draw();

					res::Texture::Unbind();
					res::Shader::UnuseShader();
				});

				cam.Unbind();
			});
		}
	}
}