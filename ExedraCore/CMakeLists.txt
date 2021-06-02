option(EXD_DYNAMIC_LINK "Build the shared library" off)
option(EXD_STATIC_LINK "Build the static library" on)

set(SRC
# Core
    "exedra.h"

    "src/core.h"
    "src/application.cpp"
    "src/application.h"

# Graphics
    "src/graphics/window.cpp"
    "src/graphics/window.h"
    "src/graphics/renderer.cpp"
    "src/graphics/renderer.h"
    "src/graphics/camera.h"
    "src/graphics/camera.cpp"

# Input
    "src/input/inputhandler.cpp"
    "src/input/inputhandler.h"

# Resources
    "src/resources/shader.cpp"
    "src/resources/shader.h"
    "src/resources/mesh.h"
    "src/resources/mesh.cpp"
    "src/resources/model.cpp"
    "src/resources/model.h"

# Utils
    "src/utils/filereader.cpp"
    "src/utils/filereader.h"
    "src/utils/time.cpp"
    "src/utils/time.h"
    "src/utils/fileloader.cpp"
    "src/utils/fileloader.h"

# Logging
    "src/logging/log.h"
    "src/logging/debug.cpp"
    "src/logging/debug.h"

# Events
    "src/events/eventdispatcher.cpp"
    "src/events/eventdispatcher.h"
    "src/events/event.cpp"
    "src/events/event.h"
    "src/resources/texture.cpp"
    "src/resources/texture.h"
    "src/resources/modeltexture.cpp"
    "src/resources/modeltexture.h"
    "src/resources/rendertexture.cpp"
    "src/resources/rendertexture.h"

# GUI
    "src/gui/imguiwindow.cpp"
    "src/gui/imguiwindow.h"
    "src/gui/guihandler.cpp"
    "src/gui/guihandler.h"
    "src/gui/classeditorwindow.tpp"
    "src/gui/classeditorwindow.h"
    "src/gui/dockspacewindow.cpp"
    "src/gui/dockspacewindow.h"
    "src/gui/transformwindow.cpp"
    "src/gui/transformwindow.h"
    "src/gui/camerawindow.cpp"
    "src/gui/camerawindow.h"
    "src/gui/mainmenubar.cpp"
    "src/gui/mainmenubar.h"
    
    
    "src/gui/scenemanager.cpp"
    "src/gui/scenemanager.h"

# ECS
    "src/ecs/transform.cpp"
    "src/ecs/transform.h"
    "src/ecs/entity.cpp"
    "src/ecs/entity.h"
    "src/ecs/entity.tpp"
    "src/ecs/component.cpp"
    "src/ecs/component.h"
    "src/ecs/modeldrawer.cpp"
    "src/ecs/modeldrawer.h"
    "src/ecs/drawer.cpp"
    "src/ecs/drawer.h"
    "src/ecs/scene.cpp"
    "src/ecs/scene.h"

     "src/gui/renderview.cpp" "src/gui/renderview.h" "src/gui/closablewindow.h" "src/gui/closablewindow.tpp")

if(EXD_DYNAMIC_LINK)
    add_library(ExedraCore SHARED ${SRC})

    add_custom_command(TARGET ExedraCore POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/bin/ExedraCore-$<CONFIGURATION>/ExedraCore-$<CONFIGURATION>.dll"
        "${CMAKE_BINARY_DIR}/bin/Sandbox-$<CONFIGURATION>/ExedraCore-$<CONFIGURATION>.dll")
elseif(EXD_STATIC_LINK)
    add_library(ExedraCore STATIC ${SRC} "src/gui/closablewindow.cpp")
endif()

target_compile_definitions(ExedraCore PUBLIC
    RE_PLATFORM_WINDOWS
    GLFW_INCLUDE_NONE
    STB_IMAGE_IMPLEMENTATION
    $<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>
)

add_compile_definitions(ExedraCore PRIVATE RE_BUILD_DLL)

set_target_properties(ExedraCore PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/ExedraCore-Debug/"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/ExedraCore-Release/"
)


message("Add assimp ${CMAKE_BUILD_TYPE} lib file")
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	target_link_libraries(ExedraCore PUBLIC assimp-vc142-mtd)

    add_custom_command(TARGET ExedraCore POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/vendor/assimp/lib/assimp-vc142-mtd.dll"
        "${CMAKE_BINARY_DIR}/bin/Sandbox-$<CONFIGURATION>/assimp-vc142-mtd.dll")

elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	target_link_libraries(ExedraCore PUBLIC assimp-vc142-mt)

    add_custom_command(TARGET ExedraCore POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/vendor/assimp/lib/assimp-vc142-mt.dll"
        "${CMAKE_BINARY_DIR}/bin/Sandbox-$<CONFIGURATION>/assimp-vc142-mt.dll")
endif()