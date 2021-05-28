#pragma once
#include <string>
#include "src/core.h"

namespace exedra {
	namespace utils {
		class FileReader {
		public:
			static const char* LoadText(const char* _path);
			static std::string LoadText(const std::string& _path);
			static std::string GetFileName(const std::string& _fullPath);
		};
	}
}