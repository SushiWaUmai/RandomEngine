#pragma once
#include "classeditorwindow.h"
#include "src/resources/rendertexture.h"
#include "src/resources/shader.h"

namespace exedra {
	namespace gui {
		class RenderView : public ClassEditorWindow <RenderView, res::RenderTexture> {
		public:
			void DrawImGui() override;
		};
	}
}