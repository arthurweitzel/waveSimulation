cmake_minimum_required(VERSION 3.9)

project(waveSimulation)

set(SOURCES
    "src/main.cpp"
    "src/glad.c"
    "src/window.cpp"

)

add_executable(waveSimulation ${SOURCES})

target_link_libraries(waveSimulation
    PRIVATE
        glfw
)

target_include_directories(waveSimulation
    PRIVATE
        "include/"
)

