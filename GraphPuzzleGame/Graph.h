//
// Created by yk029484 on 1/4/2024.
//

#ifndef GRAPH_PUZZLE_GAME_SQV51_GRAPH_H
#define GRAPH_PUZZLE_GAME_SQV51_GRAPH_H

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Path.h"

using namespace std;





class Graph {
    size_t size;
    vector<Vertex> vertices;
    vector<vector<int>> adjMatrix;





public:
    Graph() {}

    void printEdges();
    Graph(const size_t wordLength,const string& filestr);
    void addWord(string str);
    void addEdge(string string1, string string2);

    auto findShortestPath(const string& start, const string& end);

    auto findShortestPathDjikstra(const string& start, const string& end);



};


#endif //GRAPH_PUZZLE_GAME_SQV51_GRAPH_H
