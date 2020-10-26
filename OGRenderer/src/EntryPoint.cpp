#include "Core/Application.h"
#include "Log/Logger.h"

int main() {

    OGRenderer::Logger::Init();
    auto app = OGRenderer::Application::GetInstance();
    app->StartUp();
    app->Run();
    app->Shutdown();

    return 0;
}
