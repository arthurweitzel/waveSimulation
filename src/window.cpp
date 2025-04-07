#include "window.hpp"
#include <iostream>

Window::Window(int width, int height, char* title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!_window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
    
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
}

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldClose() const{
    return glfwWindowShouldClose(_window);
}

void Window::processInput() {
    if (glfwGetKey(_window, GLFW_KEY_Q) == GLFW_PRESS) {
        glfwSetWindowShouldClose(_window, true);
    }
}

void Window::swapBuffers() {
    glfwSwapBuffers(_window);
}

void Window::pollEvents() {
    glfwPollEvents();
}

GLFWwindow* Window::getNativeWindow() const {
    return _window;
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}