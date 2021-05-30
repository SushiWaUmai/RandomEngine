#include "rendertexture.h"
#include "glad/glad.h"
#include "src/logging/log.h"
#include "src/graphics/camera.h"

namespace exedra {
	namespace res {
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
			BindFB();

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureID, 0);

			BindRB();
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, _width, _height);
			UnbindRB();

			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

			LOG_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is not complete!");

			Unbind();
			UnbindFB();

			LOG_CORE_TRACE("Created Rendertexture with dimensions ({0}, {1})", width, height);
		}

		// TODO Implement framebuffer resize
		void RenderTexture::Resize(int _width, int _height) {
			if (width == _width && height == _height)
				return;

			width = _width;
			height = _height;
		}

		void RenderTexture::BindFB() {
			glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		}

		void RenderTexture::BindRB() {
			glBindRenderbuffer(GL_RENDERBUFFER, rbo);
		}

		void RenderTexture::UnbindFB() {
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}

		void RenderTexture::UnbindRB() {
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}
	}
}