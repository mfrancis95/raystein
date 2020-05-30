#ifndef VERTEX_FRAGMENT_PROGRAM_H
#define VERTEX_FRAGMENT_PROGRAM_H

#include "ShaderProgram.h"

struct VertexFragmentProgram : ShaderProgram<1, 2> {

    VertexFragmentProgram
    (const std::string& vertexShader = "shader.vert",
    const std::string& fragmentShader = "shader.frag");

    void execute() final;

};

#endif
