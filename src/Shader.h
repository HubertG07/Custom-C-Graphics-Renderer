#pragma once

#include <glad/glad.h>
#include <iostream>
#include <string>

class Shader {
public:
    GLuint ID;

    Shader(const char* vertexSource, const char* fragementSource)
    {
        GLuint vertex = compileShader(GL_VERTEX_SHADER, vertexSource);
        GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fragementSource);

        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    ~Shader()
    {
        glDeleteProgram(ID);
    }

    void use() const {
        glUseProgram(ID);
    }

private:
    GLuint compileShader(GLenum type, const char* source)
    {
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, NULL);
        glCompileShader(shader);
        checkCompileErrors(shader, type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");
        return shader;
    }

    void checkCompileErrors(GLuint shader, const std::string& type)
    {
        GLint success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cerr << "ERROR:SHADER_COMPILATION_ERROR of type:" << type << "\n" << infoLog << "\n";
            }
        } else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cerr << "ERROR:PROGRAM_LINKING_ERROR of type" << type << "\n" << infoLog << "\n";
            }
        }
    }
};