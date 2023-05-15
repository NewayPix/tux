# Tux

A tux game.

## Cloning

This repository contains submodules, you'll have to fetch those before building
anything. If you use `gh` use the following command.

`gh repo clone newaypix/tux -- --recursive`

Otherwise, use the old fashioned and plain git command

`git clone https://github.com/Newaypix/tux --recursive`.

# Building

You need to build the dependency first (kokiri), generate the necessary build
files with premake and then go over `vendor/kokiri/kokiri/` and `make` it. After
that it will create a build folder within the kokiri vendor folder with a
libkokiri.a file, that file will be used when compiling the game.

- Execute `premake gmake`
- Go to `vendor/kokiri` and execute `make kokiri`
- Go back to the root folder and execute `make`
- Make sure the binary is side to side with the assets folder