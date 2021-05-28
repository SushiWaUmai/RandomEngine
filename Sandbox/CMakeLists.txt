message(${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(Sandbox 
    "main.cpp"
    "Demo.h"    
    "Demo.cpp"
    )

set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Sandbox-Debug/"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Sandbox-Release/"
)