cmake_minimum_required(VERSION 3.19)
project(BugGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BugGame main.cpp Character.cpp Character.h Bomb.cpp Bomb.h Map.cpp Map.h)