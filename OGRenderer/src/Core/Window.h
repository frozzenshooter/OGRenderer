#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace OGRenderer {

    class Window {

    public:
        Window(int width = 800, int height = 600, GLFWwindow* window = nullptr):m_Width(width), m_Height(height), m_Window(window) {};
        virtual ~Window() {};

        int StartUp();
        void Shutdown();
        bool CloseWindow();
        void ProcessInput();
        void OnUpdate();

    private:
        int m_Width, m_Height;
        GLFWwindow* m_Window;
    
    public:
        static Window* Create(int width, int height);
    };

}