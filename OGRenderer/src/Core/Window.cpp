#include "Window.h"

#include <iostream>

namespace OGRenderer {

    Window* Window::Create(int width, int height) {
        return new Window(width, height);
    }

    int Window::StartUp() {
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

        glViewport(0, 0, 800, 600);
        glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
            {
                glViewport(0, 0, width, height);
            }
        );

        return 0;
    }

    void Window::Shutdown() {
        glfwTerminate();
    }

    bool Window::CloseWindow() {
        return !glfwWindowShouldClose(m_Window);
    }

    void Window::ProcessInput() {
        if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_Window, true);
    }

    void Window::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
}