#pragma once
#include <iostream>

namespace exedra {
	namespace resources {
		class Texture {
		public:
			Texture() = default;
			Texture(const std::string& _path, int _type);
			//~Texture();

			void Init(const std::string& _path, int _type);
			void Bind();
			static void Unbind();
			
			inline const std::string GetPath() const { return path; }
			inline const int GetWidth() const { return width;  }
			inline const int GetHeight() const { return height; }

		private:
			std::string path;
			uint32_t textureID;
			int width;
			int height;
			int nrChannels;
			int type;
		};
	}
}