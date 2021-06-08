#pragma once
#include <GLFW/glfw3.h>
#include "src/events/event.h"
#include "src/events/eventdispatcher.h"
#include "src/resources/model.h"
#include "src/resources/rendertexture.h"
#include "src/graphics/camera.h"
#include "src/ecs/drawer.h"
#include <vector>
#include <memory>

namespace exedra {
	namespace graphics {
		class Renderer {
		public:
			Renderer() = default;
			~Renderer();
			void Init(GLFWwindow* _window);

			void Clear();
			void Draw();
			void SetClearColor(glm::vec4 _rgba);
			void AddDrawer(const std::shared_ptr<ecs::DrawerComponent>& _model);
		private:
			Camera cam;
			glm::vec4 clearColor;
			res::RenderTexture renderTexture;
			std::vector<std::shared_ptr<ecs::DrawerComponent>> drawers;
		};
	}
}