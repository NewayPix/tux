include "dependencies.lua"

workspace "tux"
    configurations {"debug", "release"}

    group "game"
        include "tux"
    group ""

    group "dependencies"
        include "vendor/kokiri"
    group ""
