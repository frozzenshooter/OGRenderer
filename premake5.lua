workspace "OGRenderer"
    architecture "x64"
    startproject "OGRenderer"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"
IncludeDir["Glad"] = "Hazel/vendor/Glad/include"

group "Dependencies"
    include "OGRenderer/vendor/GLFW"
    include "OGRenderer/vendor/Glad"

group ""

project "OGRenderer"
    location "OGRenderer"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    
    filter "system:windows"
        systemversion "latest"

        defines
        {
            "OGR_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }
    
    filter "configurations:Debug"
        defines "OGR_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "OGR_RELEASE"
        runtime "Release"
        optimize "on"