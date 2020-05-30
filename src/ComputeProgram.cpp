#include "ComputeProgram.h"

ComputeProgram::ComputeProgram
(const std::string& shader, const unsigned width, const unsigned height)
: ShaderProgram{setupShader<GL_COMPUTE_SHADER>(shader)} {
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, buffers[0]);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffers[0]);
}

void ComputeProgram::execute() {
    glDispatchCompute(width, height, 1);
    glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
}

void ComputeProgram::setSize(unsigned width, unsigned height) {
    this->width = width;
    this->height = height;
}