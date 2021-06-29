#include "camera.h"
#include "drawer.h"
#include "transform.h"

namespace exedra {
	namespace ecs {
		void CameraSystem::Start() {

		}

		void CameraSystem::Update(const entt::registry& _registry) {
			auto view = _registry.view<const CameraComponent, const TransformComponent>();
			view.each([&](const CameraComponent cam, const TransformComponent camTransform) {

				cam.Bind();
				cam.Clear();

				auto view = _registry.view<const DrawerComponent, const TransformComponent>();
				view.each([&](const DrawerComponent& drawer, const TransformComponent& transform) {

					// Drawer Shader
					drawer.shader.UseShader();
					drawer.shader.SetUniformVector("objectColor", { 1, 1, 1 });
					drawer.shader.SetUniformVector("lightDirection", { 0.75f, -1, 0.5f });
					drawer.shader.SetUniformMatrix("ViewProjectionMatrix", cam.GetViewProjectionMatrix(transform));
					drawer.shader.SetUniformMatrix("ModelMatrix", transform.GetTransformMatrix());

					res::DefaultResources::defaultTexture.Bind();
					drawer.mesh.Draw();
				});

				cam.Unbind();
			});
		}
	}
}