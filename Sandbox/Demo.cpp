#include <exedra.h>
#include <string>
#include "Demo.h"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

void Demo::Init(int _width, int _height, const std::string& _title) {
	Application::Init(_width, _height, _title);

	std::string projectPath = R"(F:\Coding\C++\Projects\Exedra)";
	//std::string projectPath = R"(C:\Users\eugen\Coding\C++\Projects\Exedra)";

	std::string vertPath = projectPath + R"(\exedraCore\src\assets\default\shaders\default_vert.glsl)";
	std::string fragPath = projectPath + R"(\exedraCore\src\assets\default\shaders\default_frag.glsl)";

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//GetInput().SetCursorInput(GLFW_CURSOR_DISABLED);

	shader.Init(vertPath.c_str(), fragPath.c_str());

	// Load Meshes
	{
		using namespace exedra;
		using namespace resources;
		using namespace graphics;
		using namespace gui;
		using namespace ecs;

		//std::string path = R"(D:\Downloads\pose.obj)";
		//std::string path = R"(C:\Users\eugen\Downloads\just-a-girl\source\sketch\sketch\final_v01.obj)";


		//std::string justAGirlPath = R"(D:\Downloads\just-a-girl\source\sketch\final_v01.obj)";
		//std::shared_ptr<Model> justAGirl = std::make_shared<Model>(justAGirlPath);
		//Window::current->GetRenderer().AddModel(justAGirl);
		//justAGirl->transform.SetTransform({ 0, 0, 10 }, { 0, 0, 0 }, { 0.01f, 0.01f, 0.01f });

		Entity cubeEntity;
		std::string cubePath = projectPath + R"(\ExedraCore\src\assets\default\models\DefaultCube.obj)";
		std::shared_ptr<Model> cube = std::make_shared<Model>(cubePath);
		std::shared_ptr<Transform> trasform = cubeEntity.AddComponent<Transform>();
		std::shared_ptr<ModelDrawer> drawer = cubeEntity.AddComponent<ModelDrawer>();
		drawer->SetModel(cube);
		Window::current->GetRenderer().AddDrawer(drawer);
		//cube->transform.Translate({ 0, 0, 5 });

		std::string whiteTexture = projectPath + R"(\ExedraCore\src\assets\default\textures\white_pixel.png)";
		Texture tex(whiteTexture, aiTextureType_DIFFUSE);
		tex.Bind();

	}
}

void Demo::Update() {

	shader.UseShader();
	glm::vec3 lightDirection = glm::vec3(0.75f, -1, 0.5f);

	typedef exedra::graphics::Camera Camera;
	typedef exedra::utils::Time Time;

	//shader.SetUniformVector("objectColor", glm::vec3(1.0f, 0.5f, 0.2f));
	shader.SetUniformVector("objectColor", glm::vec3(1));
	shader.SetUniformVector("lightDirection", lightDirection);

	shader.SetUniformMatrix("ViewMatrix", Camera::current->GetViewMatrix());
	shader.SetUniformMatrix("ProjectionMatrix", Camera::current->GetProjectionMatrix());

	Application::Update();
}
