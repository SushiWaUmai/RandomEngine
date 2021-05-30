#pragma once
#include "texture.h"

namespace exedra {
	namespace res {
		class RenderTexture : public Texture {
		public:
			RenderTexture() = default;
			RenderTexture(int _width, int _height);
			void Init(int _width, int _height);

			void Resize(int _width, int _height);

			void BindFB();
			void BindRB();
			static void UnbindFB();
			static void UnbindRB();

		private:
			uint32_t fbo;
			uint32_t rbo;
		};
	}
}