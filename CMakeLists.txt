cmake_minimum_required(VERSION 3.23)
project(graph-puzzle-game-Sqv51)

set(CMAKE_CXX_STANDARD 17)

add_executable(main GraphPuzzleGame/main.cpp GraphPuzzleGame/Queue.cpp GraphPuzzleGame/Queue.h)
