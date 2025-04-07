#include "triangle.hpp"

//a vertex is a colection of data per 3D cordinate

//glsl
const char* vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0"
;

const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
    "}\0"
;

//array de vertices para criar o triangulo 2D
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  
    
//construtor --todo
//destrutor --todo

void Triangle::init() {
    //cria o vertex buffer (id, referencia para o verter buffer objects(VBO))
    glGenBuffers(1, &VBO);
    //binda o buffer criado acima, usando o tipo array
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //configura o buffer, passa os dados
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //variable to store the shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //create ****and then compile the vertex shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //checks if the shader compilation was successfull
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Triangle::draw() {

}