#pragma once
#include <iostream>
#include <vector>
#include <memory>

namespace exedra {
	namespace ecs {
		class Component;

		class Entity {
		public:
			~Entity();

			template<typename T> std::shared_ptr<T> AddComponent();
			template<typename T> std::shared_ptr<T> AddComponent(std::shared_ptr<T> _obj);
			template<typename T> std::shared_ptr<T> GetComponent();

			void SetParent(Entity* _parent);
			void AddChild(Entity* _parent);
			void RemoveChild(Entity* child);
			inline Entity* GetParent() const { return parent; }

		private:
			Entity* parent;
			std::vector<Entity*> children;
			std::vector<std::shared_ptr<Component>> components;
		};
	}
}

#include "entity.tpp"