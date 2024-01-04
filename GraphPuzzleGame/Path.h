//
// Created by yk029484 on 1/4/2024.
//

#ifndef GRAPH_PUZZLE_GAME_SQV51_PATH_H
#define GRAPH_PUZZLE_GAME_SQV51_PATH_H
#include "Vertex.h"
#include <vector>


class Path{

public:
    vector<Vertex> path;
    int id;
    Path(int id, vector<Vertex> path, Vertex& nextVertex) : id(id) {
        this->path = path;
        this->path.push_back(nextVertex);
    }
    Path(int id, vector<Vertex> path) : id(id) {
        this->path = path;
    }
    void printPath() {
        for (auto iter = path.begin(); iter != path.end(); iter++) {
            auto& item = *iter;
            cout << item.getWord();
            if (iter + 1 != path.end()) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
};


#endif //GRAPH_PUZZLE_GAME_SQV51_PATH_H
