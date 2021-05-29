#pragma once
#include <iostream>
#include <vector>
#include <memory>

namespace exedra {

	namespace gui { class SceneManager; }

	namespace ecs {
		class Component;

		class Entity {
			friend class gui::SceneManager;
		public:
			std::string name;

			Entity();
			Entity(const std::string& _name);
			~Entity();

			void Init(const std::string& _name);

			template<typename T> std::shared_ptr<T> AddComponent();
			template<typename T> std::shared_ptr<T> AddComponent(std::shared_ptr<T> _obj);
			template<typename T> std::shared_ptr<T> GetComponent();

			void SetParent(Entity* _parent);
			inline Entity* GetParent() const { return parent; }
			void AddChild(Entity* _parent);
			void RemoveChild(Entity* child);
			Entity* GetChild(int _index);

		private:
			Entity* parent = nullptr;
			std::vector<Entity*> children;
			std::vector<std::shared_ptr<Component>> components;
		};
	}
}

#include "entity.tpp"