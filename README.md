# Tux

A tux game.

# Building

You need to build the dependency first (kokiri), generate the necessary build
files with premake and then go over `vendor/kokiri/kokiri/` and `make` it. After
that it will create a build folder within the kokiri vendor folder with a
libkokiri.a file, that file will be used when compiling the game.

- Execute `premake gmake`
- Go to `vendor/kokiri` and execute `make kokiri`
- Go back to the root folder and execute `make`