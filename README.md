# DWS
### Discord Webhook Sender

# Table of Contents
- [Introduction](#introduction)
- [To-Do](#to-do)
- [Required Libs](#required-libs)
- [Build](#build)
- [Contributors](#contributors)

# Introduction
I started this project because I wanted to learn how to make a desktop application in the C language. In this project I've used the curl library for API requests, and the GTK library to make it an actual desktop application.

# To Do
- Make it have embed fiels;
- Make error messages;
- Make it so that fields can be empty;
- Make it use color;
- Make it send images;

# Required Libs
- GTK
  - `sudo apt-get install libgtk-3-dev`
- Curl
  - `sudo apt-get install libcurl4-openssl-dev`
 
# Build
## As of now, I only support the build on linux!!
- Linux
  - "gcc main.c -o application_name_here \`pkg-config --cflags --libs gtk+-3.0\` -lcurl"

# Contributors
- [John](https://github.com/p3rs0n-001)
- [Mauro](https://github.com/HowlingArcher)
