#pragma once
#include "classeditorwindow.h"
#include "src/graphics/camera.h"

namespace exedra {
	namespace gui {
		class CameraWindow : public ClassEditorWindow<CameraWindow, graphics::Camera> {
		public:
			void DrawImGui() override;
		};
	}
}