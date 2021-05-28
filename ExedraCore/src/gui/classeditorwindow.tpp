#pragma once

namespace exedra {
	namespace gui {
		template<typename T>
		void ClassEditorWindow<T>::Init(T& _obj) {
			ChangeTarget(_obj);
		}

		template<typename T>
		void ClassEditorWindow<T>::ChangeTarget(T& _obj) {
			obj = &_obj;
		}
	}
}