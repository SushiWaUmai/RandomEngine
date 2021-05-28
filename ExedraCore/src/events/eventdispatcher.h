#pragma once
#include <iostream>
#include <list>
#include "event.h"
#include <memory>

namespace exedra {
	namespace events {
		class EventDispatcher {
		public:
			EventDispatcher() = default;
			void Subscribe(const Event& _func);
			void Unsubscribe(const Event& _func);
			void Dispatch();
		private:
			std::list<Event> functions;
		};
	}
}