#pragma once 

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

class Mesh {
    public:
        Mesh(int axisX, int axisZ);
       ~Mesh();
        
        void draw();
    private:
        std::vector <float> _vertices;
        std::vector <unsigned int> _indices;
        glm::mat4 _modelMatrix;
        GLuint _vao;
        GLuint _vbo;
        GLuint _ebo;
        int _axisX;
        int _axisZ;

        void createMesh();
        void setBuffers();

};