#include "renderview.h"
#include <imgui.h>
#include "src/logging/log.h"

namespace exedra {
	namespace gui {

		void RenderView::DrawImGui() {

			ImGui::Begin("Render View");
			{
				// Using a Child allow to fill all the space of the window.
				// It also alows customization
				ImGui::BeginChild("Game");
				 //Get the size of the child (i.e. the whole draw size of the windows).
				ImVec2 wsize = ImGui::GetWindowSize();
				obj->Resize(wsize.x, wsize.y);

				// Because I use the texture from OpenGL, I need to invert the V from the UV.
				ImGui::Image((ImTextureID)obj->GetID(), wsize, ImVec2(0, 1), ImVec2(1, 0));
				ImGui::EndChild();

			}
			ImGui::End();
		}
	}
}