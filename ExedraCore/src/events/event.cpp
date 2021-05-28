#include "event.h"
#include <functional>

namespace exedra {
	namespace events {
		Event::Event(const std::function<void()>& _func) {
			Init(_func);
		}

		void Event::Init(const std::function<void()>& _func) {
			Raise = _func;
		}
	}
}