//
// Created by yk029484 on 12/21/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

bool isSingleCharDiff(string firstWord, string secondWord) {
    int size = 0;
    for ([[maybe_unused]] auto i : firstWord) {//to avoid using size() function
        size++;
    }

    bool differenceDetectedOnce = false;
    //check if the words are different by more than one character

    for (size_t i = 0; i < firstWord.size(); i++) {
        //if the words are different by more than one character, return false
        if (differenceDetectedOnce && firstWord[i] != secondWord[i]) {
            return false;
        }
        if (firstWord[i] != secondWord[i]) {
            differenceDetectedOnce = true;
        }
    }
    return true;
}

struct Vertex{
    string word;
    Vertex(string word): word(word){}
};

struct Path {
    int id;
    vector<Vertex> path;

    Path(int id, vector<Vertex> path): id(id){
        this-> path = path;
    }
    Path(int id, vector<Vertex> path, Vertex& nextVertex){
        this->path = path;
        this->path.push_back(nextVertex);
    }

    void printPath(){
        size_t size=0;
        for(auto i:path){
            cout<<i.word<<"->";
        }
        cout<<endl;
    }
};
struct Graph{
    size_t size;
    vector<Vertex> vertices;
    vector<vector<int>> adjMatrix;

    Graph(size_t wordSize,string filepath){
        ifstream file;
        file.open(filepath);


        if(file.is_open()){
            string line;
            size = 0;
            while(file){
                getline(file,line);
                if(line.size() == wordSize){
                    vertices.push_back(line);
                    size++;
                }

            }
        } else{cout<< "File is not open";}


        adjMatrix = vector<vector<int>>(size);


        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(isSingleCharDiff(vertices[i].word,vertices[j].word)){
                    adjMatrix[i][j] =1;
                    adjMatrix[j][i] = 1;
                }
            }
        }

    }
    void printEdges(){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(adjMatrix[i][j]== 1){
                    cout<<vertices[i].word<<"<---->"<< vertices[j].word<<endl;
                }
            }

        }
    }



};

int main(){

    Graph graph = Graph(5,"turkish-dictionary.txt");
    graph.printEdges();
    return 0;
}