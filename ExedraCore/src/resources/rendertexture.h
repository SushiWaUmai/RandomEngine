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

			void BindFB() const;
			void BindRB() const;
			static void UnbindFB();
			static void UnbindRB();

		private:
			uint32_t fbo;
			uint32_t rbo;
		};
	}
}