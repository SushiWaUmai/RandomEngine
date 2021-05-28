#include "imguiwindow.h"

namespace exedra {
	namespace gui {
		class ClosableWindow : public ImGuiWindow {
		public:
			bool isOpen = true;
		};
	}
}