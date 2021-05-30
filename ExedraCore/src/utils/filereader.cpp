#include "filereader.h"
#include "src/logging/log.h"
#include <fstream>
#include <stb_image.h>

namespace exedra {
	namespace utils {
		const char* FileReader::LoadText(const char* _path) {

			FILE* file = fopen(_path, "rb");

			if (file == nullptr) {
				LOG_CORE_WARN("Failed to open file: \"{0}\"", GetFileName(_path));
				return NULL;
			}

			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			LOG_CORE_TRACE("Successfully opened file: \"{0}\"", GetFileName(_path));

			return data;

		}

		std::string FileReader::LoadText(const std::string& _path) {

			std::string result;
			std::ifstream in(_path, std::ios::in | std::ios::binary); // ifstream closes itself due to RAII
			if (in) {
				in.seekg(0, std::ios::end);
				size_t size = in.tellg();
				if (size != -1) {
					result.resize(size);
					in.seekg(0, std::ios::beg);
					in.read(&result[0], size);
				}
				else
					LOG_CORE_ERROR("Could not read from file \"{0}\"", GetFileName(_path));
			}
			else
				LOG_CORE_ERROR("Could not open file \"{0}\"", GetFileName(_path));

			LOG_CORE_TRACE("Successfully opened file: \"{0}\"", GetFileName(_path));

			return result;
		}

		std::string FileReader::GetFileName(const std::string& _fullPath) {
			return _fullPath.substr(_fullPath.find_last_of("/\\") + 1);
		}

		uint8_t* FileReader::LoadImageFile(const std::string& _path, int& _width, int& _height, int& _nrChannels, int targetChannels) {
			return stbi_load(_path.c_str(), &_width, &_height, &_nrChannels, targetChannels);
		}

		void FileReader::FreeImagefile(uint8_t* data) {
			stbi_image_free(data);
		}
	}
}