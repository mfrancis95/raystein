#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#define GL_GLEXT_PROTOTYPES

#include <array>
#include <fstream>
#include <GL/gl.h>
#include <initializer_list>
#include <string>

template <size_t numBuffers, size_t numShaders>
struct ShaderProgram {

    ShaderProgram(const GLuint shaders, ...) : program{glCreateProgram()},
    shaders{shaders} {
        glGenBuffers(numBuffers, buffers.data());
        for (const auto shader : this->shaders) {
            glAttachShader(program, shader);
        }
        glLinkProgram(program);
        for (const auto shader : this->shaders) {
            glDetachShader(program, shader);
        }    
    }

    virtual ~ShaderProgram() {
        glDeleteBuffers(buffers.size(), buffers.data());
        for (const auto shader : shaders) {
            glDeleteShader(shader);
        }
        glDeleteProgram(program);
    }

    virtual void execute() = 0;

    void use() {
        glUseProgram(program);
    }

protected:

    template <GLint type>
    GLuint setupShader(const std::string& file) {
        const auto shader = glCreateShader(type);
        std::ifstream stream{file};
        std::string source{std::istreambuf_iterator<char>{stream}, {}};
        auto cstrsource = source.c_str();
        glShaderSource(shader, 1, &cstrsource, nullptr);
        glCompileShader(shader);
        GLint errorLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLogLength);
        GLint compiled;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLchar error[errorLogLength];
            glGetShaderInfoLog(shader, errorLogLength, nullptr, error);
            throw std::runtime_error(error);
        }
        return shader;        
    }

    std::array<GLuint, numBuffers> buffers;
    GLuint program;
    std::array<GLuint, numShaders> shaders;

};

#endif
