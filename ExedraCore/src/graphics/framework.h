#pragma once
#include <iostream>

namespace exedra {
	namespace graphics {
		class Framework {
		public:
			static uint32_t CreateVertexBuffer();
			static uint32_t CreateVertexArray();
			static uint32_t CreateIndexBuffer();
			static uint32_t CreateTexture();
			static uint32_t CreateFramebuffer();
			static uint32_t CreateRenderbuffer();
		};
	}
}