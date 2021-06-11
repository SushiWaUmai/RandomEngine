#include <exedra.h>
#include <string>
#include "Demo.h"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

void Demo::Init(int _width, int _height, const std::string& _title) {
	Application::Init(_width, _height, _title);

	//std::string projectPath = R"(C:\Users\eugen\Coding\C++\Projects\Exedra)";
	//std::string projectPath = R"(F:\Coding\C++\Projects\Exedra)";
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
			//Transform t = cubes[0].GetComponent<Transform>();
		}


		Window::current->GetRenderer().SetClearColor({ 21.0/255, 32.0/255, 43.0/255, 1 });

		//std::string grassTexture = R"(D:\Downloads\grass.png)";
		//Texture grassTex(grassTexture, aiTextureType_DIFFUSE);
		//grassTex.Bind();
	}
}

void Demo::Update() {
	Application::Update();
}
