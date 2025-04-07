#pragma once 

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

class Mesh {
public:
        Mesh(int size, int width);
       ~Mesh();
        
        void draw();
        void setPosition(const glm::vec3);

    private:
        std::vector <float> _vertices;
        std::vector <GLuint> _index;
        glm::mat4 _modelMatrix;
        /*
        VAO = 
        VBO = Verter Buffer Objects -> a buffer that contains verter atributes and data
        EBO = 
        */


        GLuint _vao;
        GLuint _vbo;
        GLuint _ebo;
        GLuint _shaderProgram;

        void initShaders();
        void initBuffers();
};