#include "VertexFragmentProgram.h"

VertexFragmentProgram::VertexFragmentProgram
(const std::string& vertexShader, const std::string& fragmentShader)
: ShaderProgram{setupShader<GL_VERTEX_SHADER>(vertexShader),
setupShader<GL_FRAGMENT_SHADER>(fragmentShader)} {
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    GLbyte positionData[8] = {
        -1, -1,
        -1, 1,
        1, -1,
        1, 1
    };
    glBufferStorage(GL_ARRAY_BUFFER, sizeof(positionData), positionData, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_BYTE, GL_FALSE, 0, nullptr);
}

void VertexFragmentProgram::execute() {
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}