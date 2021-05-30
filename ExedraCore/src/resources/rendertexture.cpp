#include "rendertexture.h"
#include "glad/glad.h"
#include "src/logging/log.h"

namespace exedra {
	namespace resources {
		RenderTexture::RenderTexture(int _width, int _height) {
			Init(_width, _height);
		}

		void RenderTexture::Init(int _width, int _height) {
			width = _width;
			height = _height;

			glGenFramebuffers(1, &fbo);
			glGenRenderbuffers(1, &rbo);

			Texture::Init();
			Bind();

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureID, 0);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, _width, _height);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

			LOG_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is not complete!");

			UnbindRT();
		}

		void RenderTexture::Bind() {
			Texture::Bind();
			glBindFramebuffer(GL_FRAMEBUFFER, fbo);
			glBindRenderbuffer(GL_RENDERBUFFER, rbo);
		}

		void RenderTexture::UnbindRT() {
			Texture::Unbind();
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}
	}
}