#!/bin/sh

#
# compile the engine (Kokiri) and the game
#

BASE=$(pwd)

compile_engine() {
    cd vendor/kokiri || return 1

    premake gmake
    make

    cd "${BASE}" || return 1
}

compile_game() {
    premake gmake

    cd tux || return 1

    make
}

compile_engine
compile_game