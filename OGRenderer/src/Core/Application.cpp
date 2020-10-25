#include "Application.h"

#include <iostream>
#include <functional>

namespace OGRenderer {

    Application& Application::GetInstance() {
        // Lazy init
        static Application app;

        return app;
    }

    int Application::StartUp() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        m_Window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
        if (m_Window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(m_Window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        return 0;
    }

    void Application::Run() {

        glViewport(0, 0, 800, 600);
        glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
            {
                glViewport(0, 0, width, height);
            }
        );

        while (!glfwWindowShouldClose(m_Window))
        {
            ProcessInput(m_Window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }
    }

    void Application::Shutdown() {
        glfwTerminate();
    }

    void Application::ProcessInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
}