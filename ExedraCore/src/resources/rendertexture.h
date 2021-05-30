#include "texture.h"

namespace exedra {
	namespace resources {
		class RenderTexture : public Texture {
		public:
			RenderTexture(int width, int height);
			void Init(int width, int height);

			void Bind() override;
			static void UnbindRT();

		private:
			uint32_t fbo;
			uint32_t rbo;
		};
	}
}