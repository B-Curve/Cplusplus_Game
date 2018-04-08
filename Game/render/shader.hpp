//
//  shader.hpp
//  Game
//
//  Created by Brandon Kervin on 4/7/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

enum ShaderSource {
  DEFAULT = 0
};

static std::vector<std::string> sources = {
    "./shaders/shader"
};

class Shader {
public:
    Shader(ShaderSource source);
    void bind();
    void setVec3(glm::vec3 target, const std::string &name);
    void setMat4(glm::mat4 target, const std::string &name);
    void setSize(glm::vec3 size);
private:
    GLuint program;
    GLuint loadShader(ShaderSource source, GLenum shaderType);
    void checkShaderError(GLuint shader);
};

#endif /* shader_hpp */
