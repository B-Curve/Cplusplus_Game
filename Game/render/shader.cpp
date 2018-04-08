//
//  shader.cpp
//  Game
//
//  Created by Brandon Kervin on 4/7/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "shader.hpp"

Shader::Shader(ShaderSource source) {
    program = glCreateProgram();
    GLuint vShader = loadShader(source, GL_VERTEX_SHADER);
    GLuint fShader = loadShader(source, GL_FRAGMENT_SHADER);
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);
    glUseProgram(program);
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::setVec3(glm::vec3 target, const std::string &name) {
    glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &target[0]);
}

void Shader::setMat4(glm::mat4 target, const std::string &name) {
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &target[0][0]);
}

void Shader::setSize(glm::vec3 size) {
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), size);
    setMat4(scale, "size");
}

GLuint Shader::loadShader(ShaderSource source, GLenum shaderType) {
    std::ifstream file;
    std::string sourceCode;
    std::string line;
    switch (shaderType) {
        case GL_VERTEX_SHADER:
            file.open(sources[source] + ".vert");
            break;
        case GL_FRAGMENT_SHADER:
            file.open(sources[source] + ".frag");
            break;
        default:
            fprintf(stderr, "Invalid shader type.");
            return -1;
    }
    if(file.is_open()) {
        while(file.good()) {
            getline(file, line);
            sourceCode.append(line + "\n");
        }
    } else {
        fprintf(stderr, "Failed to open file: %s for %u", sources[source].c_str(), shaderType);
        return -1;
    }
    
    const char* shaderCode = sourceCode.c_str();
    
    GLuint shader = glCreateShader(shaderType);
    
    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);
    checkShaderError(shader);
    return shader;
}

void Shader::checkShaderError(GLuint shader) {
    int success;
    char infoLog[512];
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        fprintf(stderr, "Error linking shader to program: %s", infoLog);
    }
}
