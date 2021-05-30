#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "src/core.h"

namespace exedra {
	namespace res {
		class EXD_API Shader {
		public:
			static Shader *current;

			Shader() = default;
			void Init(const char* _vertPath, const char* _fragPath);
			~Shader();

			void UseShader();
			static void UnuseShader();

			void SetUniformInt(const std::string& _location, int _value);
			void SetUniformBool(const std::string& _location, bool _value);
			void SetUniformFloat(const std::string& _location, float _value);
			void SetUniformVector(const std::string& _location, glm::vec2 _value);
			void SetUniformVector(const std::string& _location, glm::vec3 _value);
			void SetUniformVector(const std::string& _location, glm::vec4 _value);
			void SetUniformMatrix(const std::string& _location, const glm::mat2& _value);
			void SetUniformMatrix(const std::string& _location, const glm::mat3& _value);
			void SetUniformMatrix(const std::string& _location, const glm::mat4& _value);

			int GetUniformLocation(const std::string& _location);
		private:
			uint32_t programID;
			static uint32_t CreateShader(uint32_t _shaderType, const char* _shaderSource);
			static void CompileShader(uint32_t _shaderID, char* _infolog);
		};
	}
}