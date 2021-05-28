#include "time.h"
#include <imgui.h>
#include <GLFW/glfw3.h>

namespace exedra {
	namespace utils {
		float Time::GetDeltaTime() {
			ImGuiIO& io = ImGui::GetIO();
			return io.DeltaTime;
		}

		float Time::GetTime() {
			return (float)glfwGetTime();
		}
	}
}