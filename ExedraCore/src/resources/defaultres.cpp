#include "defaultres.h"
#include "model.h"
#include <assimp/material.h>

namespace exedra {
	namespace res {
		Mesh DefaultResources::defaultCube;
		Shader DefaultResources::defaultShader;
		ModelTexture DefaultResources::defaultTexture;

		void DefaultResources::Init(const std::string& projectPath) {

			std::string vertPath = projectPath + R"(\exedraCore\assets\default\shaders\default_vert.glsl)";
			std::string fragPath = projectPath + R"(\exedraCore\assets\default\shaders\default_frag.glsl)";

			defaultShader.Init(vertPath.c_str(), fragPath.c_str());

			std::string whiteTexture = projectPath + R"(\ExedraCore\assets\default\textures\white_pixel.png)";
			defaultTexture.Init(whiteTexture, aiTextureType_DIFFUSE);


			std::string cubePath = projectPath + R"(\ExedraCore\assets\default\models\DefaultCube.fbx)";
			Model cubeModel(cubePath);
			defaultCube = cubeModel.meshes[0];
		}
	}
}