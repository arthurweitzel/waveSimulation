#include "../include/window.hpp"
#include "../include/global_variables.hpp"

int main() {
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    while(!window.shouldClose()) {
        window.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        window.swapBuffers();
        window.pollEvents();
    }
}