cmake_minimum_required(VERSION 3.13)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Moves.cpp Link.hpp Check.cpp)