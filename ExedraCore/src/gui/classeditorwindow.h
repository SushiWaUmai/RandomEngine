#pragma once
#include "closablewindow.h"

namespace exedra {
	namespace gui {
		template<typename T>
		class ClassEditorWindow : public ClosableWindow {
		public:
			void Init(T& _obj);
			void ChangeTarget(T& _obj);
		protected:
			T* obj;
		};
	}
}
#include "classeditorwindow.tpp"