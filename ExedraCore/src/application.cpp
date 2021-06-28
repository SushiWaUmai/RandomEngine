#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "application.h"
#include "graphics/window.h"
#include "resources/shader.h"
#include "src/logging/log.h"
#include "events/event.h"
#include <functional>
#include <nfd.h>
#include "utils/fileloader.h"
#include "src/resources/defaultres.h"

namespace exedra {

	Application::~Application() {
		NFD_Quit();
		LOG_CORE_TRACE("Application Destroyed.");
	}

	void Application::Init(int _width, int _height, const std::string& title) {

		logging::Debug::Init();

		InitGLFW();
		window.Init(_width, _height, title);
		window.CreateGLFWwindow();
		InitGLAD();
		window.InitRenderer();


		LOG_CORE_TRACE("Initializing Native File Dialog...");
		NFD_Init();


		projectPath = utils::FileLoader::GetFolder();

		res::DefaultResources::Init(projectPath);
	}

	void Application::Run() {
		while (!window.ShouldClose()) {
			Update();
		}
	}

	void Application::Update() {
		window.Update();
		ecs::Scene::current->Update();
	}

	void Application::InitGLFW() const {

		logging::Debug::GLFWInit();

		LOG_CORE_TRACE("Initializing GLFW...");

		if (!glfwInit()) {
			LOG_CORE_ERROR("Failed to initialize GLFW");
			glfwTerminate();
		}

		LOG_CORE_TRACE("Successfully initialized GLFW");
	}

	void Application::InitGLAD() const {

		LOG_CORE_TRACE("Initializing GLAD...");

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			LOG_CORE_ERROR("Failed to initialize GLAD");
			glfwTerminate();
		}

		LOG_CORE_TRACE("Successfully initialized GLAD");
		LOG_CORE_TRACE("OpenGL VERSION: {0}", glGetString(GL_VERSION));

		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

		logging::Debug::OpenGLInit();
	}
}