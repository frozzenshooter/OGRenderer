#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace OGRenderer{

    class Application {

    public: 
        virtual ~Application() {}

        int StartUp();
        void Run();
        void Shutdown();

        static Application& GetInstance();

    private:
        Application():m_Window(nullptr) {}
        void ProcessInput(GLFWwindow* window);
    
    private:
        GLFWwindow* m_Window;
    };
}