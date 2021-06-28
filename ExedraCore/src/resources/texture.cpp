#include "texture.h"
#include <glad/glad.h>
#include "src/logging/log.h"

namespace exedra {
	namespace res {

		void Texture::Init() {

			glGenTextures(1, &textureID);
			Bind();

			// set the texture wrapping/filtering options(on the currently bound texture object)
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			Unbind();
		}

		void Texture::Bind() const {
			glBindTexture(GL_TEXTURE_2D, textureID);
		}

		void Texture::Unbind() {
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}