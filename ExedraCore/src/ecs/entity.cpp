#include "entity.h"
#include "src/logging/log.h"
#include "scene.h"
#include <sstream>

namespace exedra {
	namespace ecs {
		Entity::Entity() {
			std::ostringstream getAdressStream;
			getAdressStream << this;
			name = "Entity_" + getAdressStream.str();
		}

		Entity::Entity(const std::string& _name) {
			Init(_name);
		}

		Entity::~Entity() {
			if(parent != nullptr)
				parent->RemoveChild(this);

			uint32_t size = children.size();
			for (uint32_t i = 0; i < size; i++)
				delete children[0];

			LOG_CORE_TRACE("Entity {0} Destroyed.", name);
		}

		void Entity::Init(const std::string& _name) {
			name = _name;
		}

		void Entity::SetParent(Entity* _parent) {
			parent->RemoveChild(this);
			parent = _parent;
			parent->children.push_back(this);
		}

		void Entity::AddChild(Entity* _child) {
			children.push_back(_child);
			_child->parent = this;
		}

		void Entity::RemoveChild(Entity* _child) {
			children.erase(std::remove(children.begin(), children.end(), _child), children.end());
		}

		Entity* Entity::GetChild(int _index) {
			return children[_index];
		}
	}
}