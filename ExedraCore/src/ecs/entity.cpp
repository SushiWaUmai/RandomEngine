#include "entity.h"
#include "scene.h"

namespace exedra {
	namespace ecs {
		Entity::~Entity() {
			parent->RemoveChild(this);
		}

		void Entity::SetParent(Entity* _parent) {
			parent = _parent;
			_parent->AddChild(this);
		}

		void Entity::AddChild(Entity* _child) {
			children.push_back(_child);
			_child->SetParent(this);
		}

		void Entity::RemoveChild(Entity* _child) {
			//children.erase(std::remove(children.begin(), children.end(), _child), children.end());
		}
	}
}