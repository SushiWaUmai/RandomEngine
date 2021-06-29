#include <exedra.h>
#include <string>
#include "Demo.h"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

void Demo::Init(int _width, int _height, const std::string& _title) {
	Application::Init(_width, _height, _title);
	scene.Init();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//GetInput().SetCursorInput(GLFW_CURSOR_DISABLED);


	// Load Meshes
	{
		using namespace exedra;
		using namespace res;
		using namespace graphics;
		using namespace gui;
		using namespace ecs;
		using namespace utils;

		{
			Entity cube = scene.AddEntity();
			cube.AddComponent<DrawerComponent>();
			TransformComponent& transform = cube.AddComponent<TransformComponent>();
			transform.position = { 0, 0, 10 };
		}
	}
}

void Demo::Update() {
	Application::Update();
}
