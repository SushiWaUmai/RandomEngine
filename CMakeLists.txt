cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Exedra)
cmake_policy(SET CMP0079 NEW)

set(CMAKE_DEBUG_POSTFIX "-Debug")
set(CMAKE_RELEASE_POSTFIX "-Release")

#============================================================================================================================
# Subdirectories
add_subdirectory("ExedraCore")
add_subdirectory("Sandbox")

#============================================================================================================================
# glfw
add_subdirectory("vendor/glfw")

target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include")
target_link_libraries(ExedraCore PUBLIC glfw ${GLFW_LIBRARIES})

#============================================================================================================================
# glad
add_subdirectory("vendor/glad")

target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include")
target_link_libraries(ExedraCore PUBLIC glad)

#============================================================================================================================
# spdlog
add_subdirectory("vendor/spdlog")

target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include")

#============================================================================================================================
# imgui

add_subdirectory("vendor/imgui-cmake")

target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui-cmake")
target_link_libraries(ExedraCore PUBLIC imgui)

set_target_properties(imgui PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/vendor/ImGui-Debug/"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/vendor/ImGui-Release/"
)
#============================================================================================================================
# stb
target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb")

#============================================================================================================================
# assimp
target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/assimp/include")
target_link_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/assimp/lib")

#============================================================================================================================
# glm
add_subdirectory("vendor/glm")

target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm")

#============================================================================================================================
# native file dialog
add_subdirectory("vendor/nativefiledialog-extended")
target_link_libraries(ExedraCore PUBLIC nfd)

#============================================================================================================================
# ExedraCore
target_include_directories(ExedraCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ExedraCore")

target_link_libraries(Sandbox PRIVATE ExedraCore)

#============================================================================================================================

# Setup Sandbox
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT "Sandbox")

#============================================================================================================================