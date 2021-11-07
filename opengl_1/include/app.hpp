#ifndef __APP_HPP
#define __APP_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class App
{
private:
    const int SCR_WIDTH = 1920;
    const int SCR_HEIGHT = 1080;

public:
    static App *the_app;
    App() {}
    virtual void init() {}
    virtual void display(){};

    virtual void run(App *app)
    {
        if (the_app != NULL)
        { //同一时刻，只能有一个App运行
            std::cerr << "The the_app is already run." << std::endl;
            return;
        }
        the_app = app;

        glfwInit();
        GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "StudyOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);
        if (glewInit() != GLEW_OK)
        {
            std::cerr << "Failed to initalize GLEW" << std::endl;
            return;
        }

        init(); //用来准备各种数据

        while (!glfwWindowShouldClose(window))
        {

            display(); //这里才是渲染图形的主战场

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwDestroyWindow(window);

        glfwTerminate();
        return;
    }
};

#endif




