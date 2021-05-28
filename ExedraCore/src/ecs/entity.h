#pragma once
#include <iostream>
#include <vector>
#include <memory>

namespace exedra {
	namespace ecs {
		class Component;

		class Entity {
		public:
			Entity() = default;

			template<typename T>
			std::shared_ptr<T> AddComponent();
			
			template<typename T>
			std::shared_ptr<T> AddComponent(std::shared_ptr<T> obj);

			template<typename T>
			std::shared_ptr<T> GetComponent();

		private:
			std::vector<std::shared_ptr<Component>> components;
		};
	}
}

#include "entity.tpp"