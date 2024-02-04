# Windows Build

## Table of Contents
- [msys2](#msys2)
- [required Libs](#required-libs)
- [Build](#build)

## msys2
Download and install the [msys2](https://www.msys2.org/) terminal application to download the libraries and build the application.

## Required Libs
- GTK
  - `pacman -S base-devel mingw-w64-i686-toolchain mingw-w64-i686-gtk3`
- Curl
  - `pacman -S mingw-w64-x86_64-curl`

## Build
- "gcc main.c functions.c -o application_name_here \`pkg-config --cflags --libs gtk+-3.0\` -lcurl -mwindows -Wl,--subsystem,windows"
