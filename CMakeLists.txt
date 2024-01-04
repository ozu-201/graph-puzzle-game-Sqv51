cmake_minimum_required(VERSION 3.23)
project(graph-puzzle-game-Sqv51)

set(CMAKE_CXX_STANDARD 17)

#add_library(graph-puzzle-game-Sqv51 GraphPuzzleGame/main.cpp GraphPuzzleGame/Queue.cpp GraphPuzzleGame/Queue.h
#        GraphPuzzleGame/Graph.cpp GraphPuzzleGame/Graph.h GraphPuzzleGame/Vertex.h GraphPuzzleGame/Vertex.cpp
#        GraphPuzzleGame/Path.h GraphPuzzleGame/Path.cpp)

add_executable(main GraphPuzzleGame/main.cpp GraphPuzzleGame/Queue.cpp GraphPuzzleGame/Queue.h
        GraphPuzzleGame/Graph.cpp GraphPuzzleGame/Graph.h  GraphPuzzleGame/Vertex.cpp GraphPuzzleGame/Vertex.h
         GraphPuzzleGame/Path.cpp GraphPuzzleGame/Path.h)

#target_link_libraries(main graph-puzzle-game-Sqv51)