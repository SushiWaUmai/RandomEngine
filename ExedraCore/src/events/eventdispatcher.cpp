#include "eventdispatcher.h"
#include "src/logging/log.h"
#include <functional>
#include <iostream>

namespace exedra {
	namespace events {
		void EventDispatcher::Subscribe(const Event& _func) {
			functions.push_back(_func);
		}

		void EventDispatcher::Unsubscribe(const Event& _func) {
			functions.remove_if([_func = &_func](auto& x) { return &x == _func; });
		}

		void EventDispatcher::Dispatch() {
			for (auto& func : functions)
				func.Raise();
		}
	}
}