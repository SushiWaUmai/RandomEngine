#pragma once
#include <imgui.h>
#include "classeditorwindow.h"
#include "src/ecs/transform.h"

namespace exedra {
	namespace gui {
		class TransformWindow : public ClassEditorWindow<TransformWindow, ecs::Transform> {
		protected:
			void DrawImGui() override;
		};
	}
}