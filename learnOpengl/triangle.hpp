#pragma once

#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Triangle {
    private:
        unsigned int VBO, vertexShader;
        const char* vertexShaderSource;
        const char* fragmentShaderSource;

    public:
        Triangle();
        ~Triangle();

        void init();
        void draw();
};
        