#pragma once

namespace exedra {
	namespace ecs {
		template<typename... T>
		class System {
		public:
			void Start();
			void Update();
		};
	}
}