#include <exedra.h>
#include <string>
#include "Demo.h"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

void Demo::Init(int _width, int _height, const std::string& _title) {
	Application::Init(_width, _height, _title);

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
			std::string cubePath = projectPath + R"(\ExedraCore\assets\default\models\DefaultCube.fbx)";
			Model cubeModel(cubePath);
			std::vector<Entity> cubes = cubeModel.CreateEntities();
			TransformComponent& t = cubes[0].GetComponent<TransformComponent>();
			t.position = { 0, 0, 10 };
		}

		Window::current->GetRenderer().SetClearColor({ 21.0/255, 32.0/255, 43.0/255, 1 });
	}
}

void Demo::Update() {
	Application::Update();
}
