//
//  texture.hpp
//  Game
//
//  Created by Brandon Kervin on 4/8/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <OpenGL/gl3.h>

enum TextureType {
  TX_BRICKS = 0
};

static std::vector<std::string> textures = {
  "./Textures/bricks.png"
};

class Texture {
public:
    Texture(TextureType type);
    void bind(GLuint loc);
private:
    GLuint texture;
};

#endif /* texture_hpp */
