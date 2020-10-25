#include "Application.h"

#include <functional>

namespace OGRenderer {

    Application* Application::GetInstance() {
        // Lazy init
        static Application app;

        return &app;
    }

    int Application::StartUp() {

        m_Window = std::unique_ptr<Window>(Window::Create(800, 600));
        auto retValue = m_Window->StartUp();

        return retValue;
    }

    void Application::Run() {

        while (m_Window->CloseWindow())
        {
            m_Window->ProcessInput();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Window->OnUpdate();

        }
    }

    void Application::Shutdown() {
        m_Window->Shutdown();
    }
}