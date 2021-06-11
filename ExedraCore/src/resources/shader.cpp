#include <iostream>
#include "exedra.h"
#include "shader.h"
#include "src/utils/filereader.h"
#include "src/logging/log.h"

namespace exedra {
	namespace res {
		Shader::~Shader() {
			glDeleteProgram(programID);
		}

		void Shader::Init(const char* _vertPath, const char* _fragPath) {

			using namespace exedra::utils;

			// Read source files form path
			const char* vertCode = FileReader::LoadText(_vertPath);
			const char* fragCode = FileReader::LoadText(_fragPath);

			// Logging
			char infolog[512];

			// Create and compile vertex shader
			uint32_t vertexShader = CreateShader(GL_VERTEX_SHADER, vertCode);
			CompileShader(vertexShader, infolog);

			// Create and compile fragment shader
			uint32_t fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragCode);
			CompileShader(fragmentShader, infolog);

			// Create and link Program
			programID = glCreateProgram();
			glAttachShader(programID, vertexShader);
			glAttachShader(programID, fragmentShader);
			glLinkProgram(programID);

			// Delete Shaders
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			LOG_CORE_TRACE("Successfully Initialized Shader with path: {0}, {1}", _vertPath, _fragPath);
		}

		uint32_t Shader::CreateShader(uint32_t _shaderType, const char* _shaderSource) {

			uint32_t _shaderID;

			_shaderID = glCreateShader(_shaderType);
			glShaderSource(_shaderID, 1, &_shaderSource, NULL);

			return _shaderID;
		}

		void Shader::CompileShader(uint32_t _shaderID, char* _infoLog) {

			int _success;
			glCompileShader(_shaderID);
			glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &_success);

			if (!_success)
			{
				glGetShaderInfoLog(_shaderID, 512, NULL, _infoLog);
				LOG_CORE_WARN("Shader Compilation failed: {0}", _infoLog);
			}
		}

		void Shader::UseShader() const {
			glUseProgram(programID);
		}

		void Shader::UnuseShader() {
			glUseProgram(0);
		}

		void Shader::SetUniformInt(const std::string& _location, int _value) const {
			int _locID = GetUniformLocation(_location);
			glUniform1i(_locID, _value);
		}

		void Shader::SetUniformBool(const std::string& _location, bool _value) const {
			int _locID = GetUniformLocation(_location);
			glUniform1i(_locID, _value);
		}

		void Shader::SetUniformFloat(const std::string& _location, float _value) const {
			int _locID = GetUniformLocation(_location);
			glUniform1f(_locID, _value);
		}

		void Shader::SetUniformVector(const std::string& _location, glm::vec2 _value) const {
			int _locID = GetUniformLocation(_location);
			glUniform2fv(_locID, 1, &_value[0]);
		}

		void Shader::SetUniformVector(const std::string& _location, glm::vec3 _value) const {
			int _locID = GetUniformLocation(_location);
			glUniform3fv(_locID, 1, &_value[0]);
		}

		void Shader::SetUniformVector(const std::string& _location, glm::vec4 _value) const {
			int _locID = GetUniformLocation(_location);
			glUniform4fv(_locID, 1, &_value[0]);
		}

		void Shader::SetUniformMatrix(const std::string& _location, const glm::mat2& _value)  const {
			int _locID = GetUniformLocation(_location);
			glUniformMatrix2fv(_locID, 1, GL_FALSE, &_value[0][0]);
		}

		void Shader::SetUniformMatrix(const std::string& _location, const glm::mat3& _value) const {
			int _locID = GetUniformLocation(_location);
			glUniformMatrix3fv(_locID, 1, GL_FALSE, &_value[0][0]);
		}

		void Shader::SetUniformMatrix(const std::string& _location, const glm::mat4& _value) const {
			int _locID = GetUniformLocation(_location);
			glUniformMatrix4fv(_locID, 1, GL_FALSE, &_value[0][0]);
		}

		int Shader::GetUniformLocation(const std::string& _location) const {
			glUseProgram(programID);

			int _locID = glGetUniformLocation(programID, _location.c_str());

			if (_locID < 0) {
				LOG_CORE_ERROR("[Shader Error] Uniform {0} not found.", _location);
			}

			return _locID;
		}
	}
}