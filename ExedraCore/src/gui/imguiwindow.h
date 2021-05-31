#pragma once
#include "src/core.h"
#include <iostream>

namespace exedra {
	namespace gui {
		class EXD_API ImGuiWindow{
		public:
			virtual void DrawImGui() = 0;
		};
	}
}