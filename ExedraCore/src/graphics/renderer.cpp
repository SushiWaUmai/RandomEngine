#include "exedra.h"
#include "renderer.h"
#include "src/resources/shader.h"
#include "src/resources/model.h"
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

			LOG_CORE_TRACE("Renderer initialized successfully.");
		}
	}
}