const char* vertexShaderSource = R"(
    #version 330 core
    layout (location) = 0 in vec3 aPos;

    uniform mat4 MVP

    void main() {
        gl_Position = MVP * vec4(aPos, 1.0);
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;

    void main() {
        FragColor = vec4(1.0);
    }
)";
