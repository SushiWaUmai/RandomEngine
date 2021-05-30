#pragma once
#include "texture.h"
#include <iostream>

namespace exedra {
	namespace res {
		class ModelTexture : public Texture {
		public:
			ModelTexture() = default;
			ModelTexture(const std::string& _path, int _type);

			void Init(const std::string& _path, int _type);

			inline const std::string GetPath() const { return path; }

		private:
			std::string path;
			int type;
		};
	}
}