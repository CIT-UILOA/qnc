cmake_minimum_required(VERSION 3.20)
project(queen)

file(GLOB SOURCES "src/*.c")

include_directories(include)
add_executable(${PROJECT_NAME} ${SOURCES})