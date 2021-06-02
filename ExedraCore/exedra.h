#pragma once

// stl lib
#include <vector>
#include <list>
#include <deque>
#include <set>

// deps
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <entt/entt.hpp>

// Core
#include "src/core.h"
#include "src/application.h"

// Events
#include "src/events/event.h"
#include "src/events/eventdispatcher.h"

// Debug
#include "src/logging/log.h"

// GUI
#include "src/gui/imguiwindow.h"
#include "src/gui/classeditorwindow.h"
#include "src/gui/transformwindow.h"

// Graphics
#include "src/graphics/camera.h"
#include "src/graphics/window.h"

// Resources
#include "src/resources/shader.h"
#include "src/resources/modeltexture.h"
#include "src/resources/rendertexture.h"

// Utils
#include "src/utils/time.h"

// Entity Component System (ECS)
//#include "src/ecs/entity.h"
#include "src/ecs/drawer.h"
#include "src/ecs/transform.h"
#include "src/ecs/meshdrawer.h"
#include "src/ecs/scene.h"