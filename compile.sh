#!/bin/sh

#
# compile the engine (Kokiri) and the game
#

BASE=$(pwd)
BUILD="${BASE}/build"

KOKIRI_LOGS="${BUILD}/kokiri.log"
TUX_LOGS="${BUILD}/tux.log"

prepare() {
    mkdir -p "${BUILD}"
    cp -r ./tux/assets "${BUILD}"
}

compile_engine() {
    echo "COMPILING KOKIRI..."

    cd ./vendor/kokiri || return 1

    premake gmake > /dev/null
    make > "${KOKIRI_LOGS}" 2>&1 || return 1

    cd "${BASE}" || return 1
}

compile_game() {
    echo "COMPILING TUX..."

    premake gmake > /dev/null

    cd tux || return 1

    make > "${TUX_LOGS}" 2>&1 || return 1

    cp ./build/tux/tux "${BASE}/build/"
    cd "${BASE}" || return 1
}


prepare

compile_engine
compile_game