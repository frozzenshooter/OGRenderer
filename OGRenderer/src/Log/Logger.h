#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace OGRenderer {

    class Logger {

    public: 

        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetInstance() { return s_Instance; }

    private:
        static std::shared_ptr<spdlog::logger> s_Instance;

    };
}
#define OGR_TRACE(...) ::OGRenderer::Logger::GetInstance()->trace(__VA_ARGS__)
#define OGR_INFO(...)  ::OGRenderer::Logger::GetInstance()->info(__VA_ARGS__)
#define OGR_WARN(...)  ::OGRenderer::Logger::GetInstance()->warn(__VA_ARGS__)
#define OGR_ERROR(...) ::OGRenderer::Logger::GetInstance()->error(__VA_ARGS__)