#include <glm/gtc/type_ptr.hpp>
#include "transformwindow.h"
#include "src/logging/log.h"

namespace exedra {
	namespace gui {
		void TransformWindow::DrawImGui() {

			bool changed = false;

			std::ostringstream get_the_address;
			get_the_address << this;
			std::string address = get_the_address.str();

			std::string title("Transform: ");

			title += address;

			ImGui::Begin(title.c_str());

			changed |= ImGui::DragFloat3("Position", glm::value_ptr(obj->position), 0.005f);
			changed |= ImGui::DragFloat3("Rotation", glm::value_ptr(obj->rotation), 0.005f);
			changed |= ImGui::DragFloat3("Scale", glm::value_ptr(obj->scale), 0.005f);

			ImGui::End();

			if (changed)
				obj->UpdateTransform();
		}
	}
}