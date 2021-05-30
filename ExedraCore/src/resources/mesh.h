#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
//#include "src/resources/texture.h"

namespace exedra {
	namespace res {
		class Mesh {
		public:
			struct Vertex {
				glm::vec3 position;
				glm::vec3 normal;
				glm::vec2 uv;
			};

			Mesh() = default;
			Mesh(const std::vector<Vertex>& _vertices, const std::vector<uint32_t>& _indices);
			void Load(const std::vector<Vertex>& _vertices, const std::vector<uint32_t>& _indices);
			void Draw() const;
			void Bind() const;
			static void Unbind();

		private:
			uint32_t vbo;
			uint32_t ebo;
			uint32_t vao;

			std::vector<Vertex> vertices;
			std::vector<uint32_t> indices;
			//std::vector<Texture> textures;
		};
	}
}