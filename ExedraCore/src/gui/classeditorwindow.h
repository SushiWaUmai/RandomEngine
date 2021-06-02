#pragma once
#include "closablewindow.h"

namespace exedra {
	namespace gui {
		template<typename T, typename O>
		class ClassEditorWindow : public ClosableWindow<T> {
		public:
			void Init(O& _obj);
			void ChangeTarget(O& _obj);
		protected:
			O* obj;
		};
	}
}
#include "classeditorwindow.tpp"