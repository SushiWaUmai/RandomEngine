#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "src/core.h"

namespace exedra {
	namespace res {
		class EXD_API Shader {
		public:
			Shader() = default;
			void Init(const char* _vertPath, const char* _fragPath);
			~Shader();

			void UseShader() const;
			static void UnuseShader();

			void SetUniformInt(const std::string& _location, int _value) const;
			void SetUniformBool(const std::string& _location, bool _value) const;
			void SetUniformFloat(const std::string& _location, float _value) const;
			void SetUniformVector(const std::string& _location, glm::vec2 _value) const;
			void SetUniformVector(const std::string& _location, glm::vec3 _value) const;
			void SetUniformVector(const std::string& _location, glm::vec4 _value) const;
			void SetUniformMatrix(const std::string& _location, const glm::mat2& _value) const;
			void SetUniformMatrix(const std::string& _location, const glm::mat3& _value) const;
			void SetUniformMatrix(const std::string& _location, const glm::mat4& _value) const;

			int GetUniformLocation(const std::string& _location) const;
		private:
			uint32_t programID;

			static uint32_t CreateShader(uint32_t _shaderType, const char* _shaderSource);
			static void CompileShader(uint32_t _shaderID, char* _infolog);
		};
	}
}