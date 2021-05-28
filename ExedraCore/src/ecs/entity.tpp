#include "entity.h"
#include "src/logging/log.h"
#include <type_traits>
#include <memory>
#include <iostream>

namespace exedra {
	namespace ecs {
		template<typename T>
		std::shared_ptr<T> Entity::AddComponent() {
			static_assert(std::is_base_of<Component, T>::value, "Type parameter of this Method must derive from Component");
			std::shared_ptr<T> shared = std::make_shared<T>(*this);
			components.push_back(shared);
			shared->Init();

			return shared;
		}

		template<typename T>
		std::shared_ptr<T> Entity::AddComponent(std::shared_ptr<T> obj) {
			static_assert(std::is_base_of<Component, T>::value, "Type parameter of this Method must derive from Component");

			components.push_back(obj);
			obj->Init();

			return obj;
		}

		template<typename T>
		std::shared_ptr<T> Entity::GetComponent() {
			static_assert(std::is_base_of<Component, T>::value, "Type parameter of this Method must derive from Component");

			for (int i = 0; i < components.size(); i++) {
				if (typeid(*components[i]) == typeid(T)) {
					return std::dynamic_pointer_cast<T>(components[i]);
				}
			}

			LOG_CORE_ERROR("Could not find Component \"{0}\"!", typeid(T).name());
			return {};
		}
	}
}