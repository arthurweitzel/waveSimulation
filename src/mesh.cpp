#include "mesh.hpp"
#include "meshShader.h"

Mesh::Mesh(int axisX, int axisY) : axisX(_axisX), axisY(_axisY) {
    createMesh();
    setBuffers();
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
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
x

void Mesh::createMesh() {
    float 

    for(int i = 0; i < gridX; i++) {
        for(int j = 0, j < gridZ; j++) {
            
        }
    }
}