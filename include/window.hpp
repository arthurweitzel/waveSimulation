#pragma once 

#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

class Window {
    public:    
        Window(const int width, const int height, char* title); // char* pois o title original é implementado em C
        ~Window();

        bool shouldClose() const;
        void processInput();
        void swapBuffers();
        void pollEvents();
        GLFWwindow* getNativeWindow() const;

    private:
        GLFWwindow* window;
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};