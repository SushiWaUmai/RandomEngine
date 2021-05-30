#include "model.h"
#include <assimp/postprocess.h>
#include "src/logging/log.h"
#include "src/graphics/window.h"

namespace exedra {
	namespace res {
		Assimp::Importer Model::modelImporter;

		Model::Model(const std::string& _path) {
			Load(_path);
		}

		void Model::Load(const std::string& _path) {

			int processFlag = aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType | aiProcess_FlipUVs;

			const aiScene* scene = modelImporter.ReadFile(_path, processFlag);

			LOG_ASSERT(scene && !(scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE && scene->mRootNode), modelImporter.GetErrorString());

			ProcessNode(scene->mRootNode, scene);

			LOG_CORE_TRACE("Successfully loaded Model {0} with {1} meshes and {2} textures", _path, meshes.size(), textures.size());
		}

		void Model::ProcessNode(aiNode* _node, const aiScene* _scene) {
			// process all the node's meshes (if any)
			for (uint32_t i = 0; i < _node->mNumMeshes; i++) {
				aiMesh* _mesh = _scene->mMeshes[_node->mMeshes[i]];
				meshes.push_back(ProcessMesh(_mesh, _scene));
			}
			// then do the same for each of its children
			for (uint32_t i = 0; i < _node->mNumChildren; i++) {
				ProcessNode(_node->mChildren[i], _scene);
			}
		}

		Mesh Model::ProcessMesh(aiMesh* _mesh, const aiScene* _scene) {

			std::vector<Mesh::Vertex> vertices;
			std::vector<uint32_t> indices;

			for (uint32_t i = 0; i < _mesh->mNumVertices; i++) {

				Mesh::Vertex vert;

				glm::vec3 position;
				position.x = _mesh->mVertices[i].x;
				position.y = _mesh->mVertices[i].y;
				position.z = _mesh->mVertices[i].z;
				vert.position = position;

				glm::vec3 normal;
				normal.x = _mesh->mNormals[i].x;
				normal.y = _mesh->mNormals[i].y;
				normal.z = _mesh->mNormals[i].z;
				vert.normal = normal;

				// does the mesh contain texture coordinates?
				if (_mesh->mTextureCoords[0]) {
					glm::vec2 uv;
					uv.x = _mesh->mTextureCoords[0][i].x;
					uv.y = _mesh->mTextureCoords[0][i].y;
					vert.uv = uv;
				}
				else {
					vert.uv = glm::vec2(0.0f, 0.0f);
				}

				vertices.push_back(vert);
			}

			for (uint32_t i = 0; i < _mesh->mNumFaces; i++) {
				aiFace face = _mesh->mFaces[i];
				for (uint32_t j = 0; j < face.mNumIndices; j++) {
					indices.push_back(face.mIndices[j]);
				}
			}

			if (_mesh->mMaterialIndex >= 0) {
				aiMaterial* material = _scene->mMaterials[_mesh->mMaterialIndex];
				std::vector<ModelTexture> diffuseMaps = LoadMaterialTextures(material, aiTextureType_DIFFUSE, "diffuseMap");
				textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
				std::vector<ModelTexture> specularMaps = LoadMaterialTextures(material, aiTextureType_SPECULAR, "specularMap");
				textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
			}

			return Mesh(vertices, indices);
		}

		std::vector<ModelTexture> Model::LoadMaterialTextures(aiMaterial* _mat, aiTextureType _type, std::string _typeName) {
			std::vector<ModelTexture> _textures;
			for (uint32_t i = 0; i < _mat->GetTextureCount(_type); i++) {
				aiString textureType;
				_mat->GetTexture(_type, i, &textureType);
				ModelTexture texture(textureType.C_Str(), _type);
				_textures.push_back(texture);
			}
			return _textures;
		}

		const std::string Model::GetImportExtensions() {
			std::string importExtensions;
			modelImporter.GetExtensionList(importExtensions);
			return importExtensions;
		}

		//void Model::Draw() {
		//	for (uint32_t i = 0; i < meshes.size(); i++) {
		//		//transform.ApplyShader();
		//		meshes[i].Draw();
		//	}
		//}
	}
}