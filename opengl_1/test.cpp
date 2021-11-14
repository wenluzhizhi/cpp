#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

//#include "include/shader_s.h"

int main()
{

    //Shader sh("/home/wenlu/work/cpp/opengl_1/test/tex.txt", "/home/wenlu/work/cpp/opengl_1/test/tex.txt");

    std::string vertexCode;
    std::ifstream vShaderFile;

    try
    {

        vShaderFile.open("/home/wenlu/work/cpp/opengl_1/test/tex.txt");
        std::stringstream sr;
        sr << vShaderFile.rdbuf();
        vShaderFile.close();

        std::string vdc;

        vdc = sr.str();

        std::cout << vdc << std::endl;
    }
    catch (std::ifstream::failure &e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
}