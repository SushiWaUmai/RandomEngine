#include "camerawindow.h"
#include <imgui.h>

namespace exedra {
	namespace gui {
		void CameraWindow::DrawImGui() {

			ImGui::Begin("Camera");

			ImGui::DragFloat("FOV", &obj->fov, 0.01f);
			ImGui::DragFloat("Mouse Sensitivity", &obj->mouseSensitivity, 0.01f);
			ImGui::DragFloat("Movement Speed", &obj->moveSpeed, 0.01f);
			ImGui::DragFloat("Near Clip Plane", &obj->nearClipPlane, 0.01f);
			ImGui::DragFloat("Far Clip Plane", &obj->farClipPlane, 0.01f);

			//ImGui::ShowDemoWindow();

			ImGui::End();
		}
	}
}