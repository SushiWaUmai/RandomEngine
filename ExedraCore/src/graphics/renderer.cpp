#include "exedra.h"
#include "renderer.h"
#include "src/resources/shader.h"
#include "src/resources/model.h"
#include "src/gui/camerawindow.h"
#include "src/gui/renderview.h"
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
			//glEnable(GL_BLEND);
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			cam.Init(60, 5, 1);
			gui::CameraWindow* camWindow = new gui::CameraWindow();
			camWindow->Init(cam);
			graphics::Window::current->GetImGui().AddWindow(camWindow);

			LOG_CORE_TRACE("Camera created.");

			renderTexture.Init(1, 1);
			gui::RenderView* renderWindow = new gui::RenderView();
			renderWindow->Init(renderTexture);
			graphics::Window::current->GetImGui().AddWindow(renderWindow);

			LOG_CORE_TRACE("Render window created.");

			LOG_CORE_TRACE("Renderer initialized successfully.");
		}

		void Renderer::Draw() {

			cam.Update();
			renderTexture.BindFB();
			Clear();

			//for (auto& m : models)
			//	m->Draw();

			renderTexture.UnbindFB();
		}

		void Renderer::Clear() {
			glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Renderer::SetClearColor(glm::vec4 _rgba) {
			clearColor = _rgba;
		}

		void Renderer::AddDrawer(const std::shared_ptr<ecs::Drawer>& _model) {
			models.push_back(_model);
		}
	}
}