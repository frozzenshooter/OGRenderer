#include "Core/Application.h"

int main() {

    auto app = OGRenderer::Application::GetInstance();
    app.StartUp();
    app.Run();
    app.Shutdown();

    return 0;
}
