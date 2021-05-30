#pragma once
#include "texture.h"

namespace exedra {
	namespace res {
		class RenderTexture : public Texture {
		public:
			RenderTexture() = default;
			RenderTexture(int width, int height);
			void Init(int width, int height);

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