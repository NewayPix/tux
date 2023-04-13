project "tux"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("build/%{prj.name}")
    objdir ("build/%{prj.name}")

    files {
        "**.cpp",
        "**.hpp"
    }

    includedirs {
        "%{TuxIncludeDir.kokiri}/src",
        "%{TuxIncludeDir.kokiri}/vendor"
    }

    libdirs {
        "%{TuxLibraryDir.kokiri}",
        "%{TuxLibraryDir.glad}"
    }

    links {
        "kokiri:static",
        "glad:static",

        "SDL2",
        "SDL2_ttf",
        "SDL2_mixer",
        "SDL2_image",

        -- to work with .ogg files
        "ogg",
        "vorbis"
    }

    filter "configurations:debug"
        buildoptions { "-Wextra", "-Wall" }
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:release"
        optimize "On"