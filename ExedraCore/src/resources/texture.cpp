#include "texture.h"
#include <glad/glad.h>
#include "src/logging/log.h"
#include <stb_image.h>

namespace exedra {
	namespace resources {

		Texture::Texture(const std::string& _path, int _type) {
			Init(_path, _type);
		}

		void Texture::Init(const std::string& _path, int _type) {
			type = _type;
			path = _path;

			glGenTextures(1, &textureID);
			Bind();

			// set the texture wrapping/filtering options(on the currently bound texture object)
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			// load and generate the texture
			uint8_t* data = stbi_load(_path.c_str(), &width, &height, &nrChannels, 4);
			if (data) {
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else {
				LOG_CORE_ERROR("Failed to load texture");
			}
			stbi_image_free(data);

			Unbind();

			LOG_CORE_TRACE("Successfully loaded texture {0} with dimensions ({1}, {2}) with {3} channels", _path, width, height, nrChannels);
		}

		void Texture::Bind() {
			glBindTexture(GL_TEXTURE_2D, textureID);
		}

		void Texture::Unbind() {
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}