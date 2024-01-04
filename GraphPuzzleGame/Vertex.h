//
// Created by yk029484 on 1/4/2024.
//

#ifndef GRAPH_PUZZLE_GAME_SQV51_VERTEX_H
#define GRAPH_PUZZLE_GAME_SQV51_VERTEX_H
#include <iostream>

#include <string>
#include <vector>

using namespace std;

class Vertex {
    string word;

public:
    string getWord(){
        return word;
    }

    Vertex(string word) : word(word){}
};


#endif //GRAPH_PUZZLE_GAME_SQV51_VERTEX_H
