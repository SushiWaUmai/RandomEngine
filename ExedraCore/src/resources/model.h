#pragma once
#include <string>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <vector>
#include "mesh.h"
#include "shader.h"
#include "modeltexture.h"
#include "src/ecs/scene.h"
#include <deque>

namespace exedra {
	namespace res {
		class Model {
		public:
			Model() = default;
			Model(const std::string& _path);
			void Load(const std::string& _path);
			void ProcessNode(aiNode* _node, const aiScene* _scene);
			Mesh ProcessMesh(aiMesh* _mesh, const aiScene* _scene);
			std::vector<ModelTexture> LoadMaterialTextures(aiMaterial* _mat, aiTextureType _type, std::string _typeName);
			static const std::string GetImportExtensions();
			std::vector<entt::entity> CreateEntities();

		private:
			std::vector<Mesh> meshes;
			std::vector<ModelTexture> textures;

			static Assimp::Importer modelImporter;
		};
	}
}