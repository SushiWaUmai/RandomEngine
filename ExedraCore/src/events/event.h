#pragma once
#include <functional>

namespace exedra {
	namespace events {
		class Event {
		public:
			std::function<void()> Raise;

			Event() = default;
			Event(const std::function<void()>& _func);
			void Init(const std::function<void()>& _func);
		};
	}
}