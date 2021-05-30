#include "modeltexture.h"
#include "texture.h"
#include <glad/glad.h>
#include "src/logging/log.h"
#include "src/utils/filereader.h"

namespace exedra {
	namespace res {
		ModelTexture::ModelTexture(const std::string& _path, int _type) {
			Init(_path, _type);
		}
		void ModelTexture::Init(const std::string& _path, int _type) {

			path = _path;
			type = _type;

			Texture::Init();

			Bind();
			// load and generate the texture
			uint8_t* data = utils::FileReader::LoadImageFile(_path.c_str(), width, height, nrChannels, 4);

			if (data) {
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else {
				LOG_CORE_ERROR("Failed to load texture");
			}

			utils::FileReader::FreeImagefile(data);

			Unbind();

			LOG_CORE_TRACE("Successfully loaded texture {0} with dimensions ({1}, {2}) with {3} channels", _path, width, height, nrChannels);
		}
	}
}