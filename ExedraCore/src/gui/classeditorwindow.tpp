#pragma once

namespace exedra {
	namespace gui {
		template<typename T, typename O>
		void ClassEditorWindow<T, O>::Init(O& _obj) {
			ChangeTarget(_obj);
		}

		template<typename T, typename O>
		void ClassEditorWindow<T, O>::ChangeTarget(O& _obj) {
			obj = &_obj;
		}
	}
}