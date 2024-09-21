cmake_minimum_required(VERSION 3.10)

# Project name
project(AlgorithmVisualizer)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 23)

# Use vcpkg for package management
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Find GLEW package
find_package(glew REQUIRED)

# Find GLFW package
find_package(glfw3 REQUIRED)

# Set an absolute path to ImGui
set(IMGUI_DIR "C:/Users/aftom/Documents/GitHub/imgui")

# Include directories for ImGui
include_directories(${IMGUI_DIR})
include_directories(${IMGUI_DIR}/backends)

# Add ImGui source files
set(IMGUI_SRC
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        Algorithms/Algorithm.h
        Algorithms/Sort/SortingAlgorithm.cpp
        Algorithms/Sort/SortingAlgorithm.h
        Algorithms/Sort/BubbleSort.cpp
        Algorithms/Sort/BubbleSort.h
        Algorithms/Backend/AlgorithmRegistry.cpp
        Algorithms/Backend/AlgorithmRegistry.h
        Algorithms/Backend/AlgorithmVisualizer.cpp
        Algorithms/Backend/AlgorithmVisualizer.h
        Algorithms/Backend/AlgorithmRegistrar.h
)

# Add the executable
add_executable(AlgorithmVisualizer main.cpp ${IMGUI_SRC})

# Link the libraries to your executable
target_link_libraries(AlgorithmVisualizer ${OPENGL_LIBRARIES} GLEW::GLEW glfw)
