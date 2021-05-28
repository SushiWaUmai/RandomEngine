#include "exedra.h"
#include "renderer.h"
#include "src/resources/shader.h"
#include "src/resources/model.h"
#include "src/gui/camerawindow.h"
#include <memory>

namespace exedra {
	namespace graphics {
		Renderer::~Renderer() {
			LOG_CORE_TRACE("Renderer Destroyed.");
		}

		void Renderer::Init(GLFWwindow* _window) {

			LOG_CORE_TRACE("Initializing Renderer...");
			
			glEnable(GL_CULL_FACE); 
			glEnable(GL_DEPTH_TEST);
			
			cam.Init(60, 5, 1);
			std::shared_ptr<gui::CameraWindow> camWindow = std::make_shared<gui::CameraWindow>();
			camWindow->Init(cam);
			graphics::Window::current->GetImGui().AddWindow(camWindow);
			LOG_CORE_TRACE("Camera created.");


			LOG_CORE_TRACE("Renderer initialized successfully.");
		}

		void Renderer::Clear() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Renderer::Draw() {

			cam.Update();
			Clear();
			for (auto& m : models) {
				m->Draw();
			}
		}

		void Renderer::SetClearColor(float _r, float _g, float _b, float _a)
		{
			glClearColor(_r, _g, _b, _a);
		}

		void Renderer::SetClearColor(glm::vec4 _rgba)
		{
			glClearColor(_rgba.r, _rgba.g, _rgba.b, _rgba.a);
		}

		void Renderer::AddDrawer(const std::shared_ptr<ecs::Drawer>& _model) {
			models.push_back(_model);
		}
	}
}