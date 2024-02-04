# Linux Build

## Table of Contents
- [required Libs](#required-libs)
- [Build](#build)


## Required Libs
- GTK
  - `sudo apt-get install libgtk-3-dev`
- Curl
  - `sudo apt-get install libcurl4-openssl-dev`

## Build
- "gcc main.c functions.c -o application_name_here \`pkg-config --cflags --libs gtk+-3.0\` -lcurl"