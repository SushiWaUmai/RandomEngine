#pragma once
#include <string>
#include <iostream>
#include "src/core.h"

namespace exedra {
	namespace utils {
		class FileReader {
		public:
			static const char* LoadText(const char* _path);
			static std::string LoadText(const std::string& _path);
			static std::string GetFileName(const std::string& _fullPath);

			static uint8_t* LoadImageFile(const std::string& _path, int& _width, int& _height, int& _nrChannels, int targetChannels);
			static void FreeImagefile(uint8_t* data);
		};
	}
}