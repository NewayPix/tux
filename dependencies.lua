-- Tux dependencies (be careful with name occlusion on vendored premake files)

TuxIncludeDir = {}

TuxIncludeDir["kokiri"] = "%{wks.location}/vendor/kokiri/kokiri"

TuxLibraryDir = {}

TuxLibraryDir["kokiri"]  = "%{wks.location}/vendor/kokiri/build/kokiri/"
TuxLibraryDir["glad"] = "%{wks.location}/vendor/kokiri/kokiri/vendor/glad/build/glad/"