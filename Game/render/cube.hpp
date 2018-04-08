//
//  cube.hpp
//  Game
//
//  Created by Brandon Kervin on 4/8/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef cube_hpp
#define cube_hpp

#include <stdio.h>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>

static glm::vec3 verts[] = {
    //front
    glm::vec3(-0.5f, -0.5f, 0.5f),
    glm::vec3(0.5f, -0.5f, 0.5f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    glm::vec3(-0.5f, 0.5f, 0.5f),
    glm::vec3(-0.5f, -0.5f, 0.5f),
    
    //back
    glm::vec3(-0.5f, -0.5f, -0.5f),
    glm::vec3(0.5f, -0.5f, -0.5f),
    glm::vec3(0.5f, 0.5f, -0.5f),
    glm::vec3(0.5f, 0.5f, -0.5f),
    glm::vec3(-0.5f, 0.5f, -0.5f),
    glm::vec3(-0.5f, -0.5f, -0.5f),
    
    //top
    glm::vec3(-0.5f, 0.5f, 0.5f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    glm::vec3(0.5f, 0.5f, -0.5f),
    glm::vec3(0.5f, 0.5f, -0.5f),
    glm::vec3(-0.5f, 0.5f, -0.5f),
    glm::vec3(-0.5f, 0.5f, 0.5f),
    
    //bottom
    glm::vec3(-0.5f, -0.5f, 0.5f),
    glm::vec3(0.5f, -0.5f, 0.5f),
    glm::vec3(0.5f, -0.5f, -0.5f),
    glm::vec3(0.5f, -0.5f, -0.5f),
    glm::vec3(-0.5f, -0.5f, -0.5f),
    glm::vec3(-0.5f, -0.5f, 0.5f),
    
    //left
    glm::vec3(-0.5f, -0.5f, -0.5f),
    glm::vec3(-0.5f, -0.5f, 0.5f),
    glm::vec3(-0.5f, 0.5f, 0.5f),
    glm::vec3(-0.5f, 0.5f, 0.5f),
    glm::vec3(-0.5f, 0.5f, -0.5f),
    glm::vec3(-0.5f, -0.5f, -0.5f),
    
    //right
    glm::vec3(0.5f, -0.5f, -0.5f),
    glm::vec3(0.5f, -0.5f, 0.5f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    glm::vec3(0.5f, 0.5f, -0.5f),
    glm::vec3(0.5f, -0.5f, -0.5f),
};

static glm::vec2 tCoords[] = {
    glm::vec2(0.0f, 0.0f),
    glm::vec2(0.5f, 0.0f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.0f, 0.5f),
    glm::vec2(0.0f, 0.0f),
    
    glm::vec2(0.0f, 0.0f),
    glm::vec2(0.5f, 0.0f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.0f, 0.5f),
    glm::vec2(0.0f, 0.0f),
    
    glm::vec2(0.0f, 0.0f),
    glm::vec2(0.5f, 0.0f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.0f, 0.5f),
    glm::vec2(0.0f, 0.0f),
    
    glm::vec2(0.0f, 0.0f),
    glm::vec2(0.5f, 0.0f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.0f, 0.5f),
    glm::vec2(0.0f, 0.0f),
    
    glm::vec2(0.0f, 0.0f),
    glm::vec2(0.5f, 0.0f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.0f, 0.5f),
    glm::vec2(0.0f, 0.0f),
    
    glm::vec2(0.0f, 0.0f),
    glm::vec2(0.5f, 0.0f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.5f, 0.5f),
    glm::vec2(0.0f, 0.5f),
    glm::vec2(0.0f, 0.0f),
};

class Cube {
public:
    Cube();
    void draw();
private:
    GLuint vao, vbo, tbo;
};

#endif /* cube_hpp */
