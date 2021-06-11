#pragma once
#include "shader.h"
#include "mesh.h"
#include "modeltexture.h"
#include <string>

namespace exedra {
	namespace res {
		struct DefaultResources {
			static Mesh defaultCube;
			static Shader defaultShader;
			static ModelTexture defaultTexture;

			static void Init(const std::string& projectPath);
		};
	}
}