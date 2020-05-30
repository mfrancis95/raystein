#ifndef COMPUTE_PROGRAM_H
#define COMPUTE_PROGRAM_H

#include "ShaderProgram.h"

struct ComputeProgram : ShaderProgram<1, 1> {

    ComputeProgram
    (const std::string& shader = "shader.comp", const unsigned width = 640,
    const unsigned height = 480);

    void execute() final;
    
    void setSize(unsigned width, unsigned height);

private:

    unsigned height, width;

};

#endif
