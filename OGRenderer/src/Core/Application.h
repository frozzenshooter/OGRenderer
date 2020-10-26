#pragma once
#include <memory>
#include "Core/Window.h"
#include "Log/Logger.h"

namespace OGRenderer{

    class Application {

    private:
        Application() : m_Window(nullptr) {};
            
    public: 
        ~Application() {};

        int StartUp();
        void Run();
        void Shutdown();

        static Application* GetInstance();

    private:
        std::unique_ptr<Window> m_Window;
    };
}