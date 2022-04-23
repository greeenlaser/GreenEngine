cmake_minimum_required(VERSION 3.23.1)  #CMake version check
project(Application)               	#Create project "Application"

#Add main.cpp file of project root directory as source file
set(SOURCE_FILES Main.cpp)

#Add executable target with source files listed in SOURCE_FILES variable
add_executable(Application ${SOURCE_FILES})