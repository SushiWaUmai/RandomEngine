#include "camerawindow.h"
#include "src/logging/log.h"
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

namespace exedra {
	namespace gui {
		void CameraWindow::DrawImGui() {
			CheckForFocus();

			if (isOpen && ImGui::Begin("Camera", &isOpen, ImGuiWindowFlags_AlwaysAutoResize)) {

				ImGui::DragFloat4("Position", glm::value_ptr(obj->position), 0.01f);
				ImGui::DragFloat2("Rotation", glm::value_ptr(obj->rotation), 0.01f);
				ImGui::DragFloat("FOV", &obj->fov, 0.01f);
				ImGui::DragFloat("Mouse Sensitivity", &obj->mouseSensitivity, 0.01f);
				ImGui::DragFloat("Movement Speed", &obj->moveSpeed, 0.01f);
				ImGui::DragFloat("Near Clip Plane", &obj->nearClipPlane, 0.01f);
				ImGui::DragFloat("Far Clip Plane", &obj->farClipPlane, 0.01f);

				ImGui::End();
			}

			CheckForClose();
		}
	}
}