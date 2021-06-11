#pragma once
#include <string>

namespace exedra {
	namespace utils {
		class FileLoader {
		public:
			static void Load3dObject();
			static void LoadTexture();
			static std::string GetFolder();
		};
	}
}