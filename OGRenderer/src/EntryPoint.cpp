#include "Core/Application.h"
#include "Core/Logger.h"

int main() {

    OGRenderer::Logger::Init();
    auto app = OGRenderer::Application::GetInstance();
    app->StartUp();
    app->Run();
    app->Shutdown();

    return 0;
}
