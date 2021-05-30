#pragma once
#include <iostream>

namespace exedra {
	namespace resources {
		class Texture {
		public:
			Texture() = default;

			void Init();
			virtual void Bind();
			static void Unbind();

			inline const int GetWidth() const { return width;  }
			inline const int GetHeight() const { return height; }
			inline const uint32_t GetID() const { return textureID; }

		protected:
			uint32_t textureID;
			int width;
			int height;
			int nrChannels;
		};
	}
}