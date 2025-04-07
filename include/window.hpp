#pragma once 

#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

class Window {
    public:    
        Window(const int width, const int height, char* title); 
        ~Window();

        bool shouldClose() const;
        void processInput();
        void swapBuffers();
        void pollEvents();
        GLFWwindow* getNativeWindow() const;

    private:
        GLFWwindow* _window;
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};