#include "mesh.hpp"
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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


Mesh::Mesh(int size, int width) {
    /*cria uma matriz que será a matriz identidade que usarei para armazenar as posições e dados (vertex)
    {
     1.0, 1.0, 1.0, 1.0,
     1.0, 1.0, 1.0, 1.0,
     1.0, 1.0, 1.0, 1.0}
    */
    _modelMatrix = glm::mat4(1.0);

    //limpa os vectors
    _vertices.clear();
    _index.clear();

}

//todo
Mesh::~Mesh() {

}

void Mesh::draw() {
    //cria e compila o vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    //cria e compila o fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    

    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);
    
    //libera os shaders após a vinculação
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Mesh::initShaders () {

}

void Mesh::initBuffers() {

}