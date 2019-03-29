cmake_minimum_required(VERSION 3.13)
project(patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(patterns main.cpp Village.h buildings.h squads.h Game.h buildings.cpp squads.cpp Village.cpp Game.cpp)