//
// Created by yk029484 on 1/4/2024.
//

#include "Graph.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Path.h"


bool isSingleCharDiff(string firstWord, string secondWord) {
    int size = 0;
    for ([[maybe_unused]] auto i : firstWord) {//to avoid using size() function
        size++;
    }

    bool differenceDetectedOnce = false;
    //check if the words are different by more than one character
    for (size_t i = 0; i < size; i++) {
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

Graph::Graph(const size_t wordLength,const string& filestr) {
    ifstream  file;
    file.open(filestr);

    //read the file and create the graph
    if (file.is_open()){
        string line;
        while (file){
            getline(file, line);
            if (line.size() == wordLength){
                vertices.push_back(line);
            }
        }
    } else {
        cout << "File not open" << endl;
    }
    file.close();


    //create the adjacency matrix according to the size of the vertices
    size = vertices.size();
    adjMatrix = vector<vector<int>>(size);
    for (size_t i = 0; i < size; i++){
        adjMatrix[i] = vector<int>(size,0);
    }

    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size; j++){
            if (isSingleCharDiff(vertices[i].getWord(), vertices[j].getWord())){
                //both vertices are adjacent
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }
        }
    }
}

void Graph::printEdges(){
    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++){
            if (adjMatrix[i][j] == 1){
                cout << vertices[i].getWord() << " <-> " << vertices[j].getWord() << endl;
            }
        }
    }
}

void Graph::addWord(string str) {

    size = vertices.size();
    adjMatrix = vector<vector<int>>(size);
    for (size_t i = 0; i < size; i++){
        adjMatrix[i] = vector<int>(size,0);
    }

    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size; j++){
            if (isSingleCharDiff(vertices[i].getWord(), vertices[j].getWord())){
                //both vertices are adjacent
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }
        }
    }


}
void Graph::addEdge(string string1, string string2){
    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size; j++){
            if (isSingleCharDiff(vertices[i].getWord(), vertices[j].getWord())){
                //both vertices are adjacent
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }
        }
    }
}

auto Graph::findShortestPath(const string& start, const string& end){
    vector<Vertex> returnElement;
    //create bool array to check if the vertex is visited

    bool visited[size];
    for (size_t i = 0; i < size; i++){
        visited[i] = false;
    }
    int verticeStart = -1;
    int verticeEnd = -1;


    //find start and end vertices
    for(size_t i = 0; i < size; i++){
        if (vertices[i].getWord() == start){
            verticeStart = i;
        }
        if (vertices[i].getWord() == end){
            verticeEnd = i;
        }
    }


    if(verticeStart == -1 || verticeEnd == -1){
        if (verticeStart == -1){
            cout << "Start vertex not found" << endl;
        }
        if (verticeEnd == -1){
            cout << "End vertex not found" << endl;
        }
        return Path(-1, returnElement);
    }

    //use queue for BFS and add vertices to the path until the end vertex is reached
    Queue<Path> queue;
    queue.push(Path(verticeStart, vector<Vertex>(),vertices[verticeStart]));
    visited[verticeStart] = true;
    while (!queue.isEmpty()){
        Path path = queue.getFront();
        queue.pop();
        //if end vertice found return the path
        if(path.id == verticeEnd){
            returnElement = path.path;
            return Path(-1, returnElement);

        }
        for (size_t i = 0; i < size; i++){
            if (adjMatrix[path.id][i] == 1 && !visited[i]){
                queue.push(Path(i, path.path, vertices[i]));
                visited[i] = true;
            }
        }
    }
    returnElement = vector<Vertex>{{"No path found"}};
    return Path(-1, returnElement);
}

auto Graph::findShortestPathDjikstra(const string& start, const string& end){
    //distance will be considered but always 1
    vector<int> dist(size, INT_MAX);
    Queue<int> queue;
    vector<Vertex> returnElement;
    int verticeStart = -1;
    int verticeEnd = -1;

    // Find start and end vertices
    for(size_t i = 0; i < size; i++){
        if (vertices[i].getWord() == start){
            verticeStart = i;
        }
        if (vertices[i].getWord() == end){
            verticeEnd = i;
        }
    }

    if(verticeStart == -1 || verticeEnd == -1){
        // Handle vertex not found
        return Path(-1, returnElement);
    }

    // Dijkstra's algorithm
    dist[verticeStart] = 0;
    queue.push(verticeStart);

    while (!queue.isEmpty()){
        int u = queue.getFront();
        queue.pop();

        for (size_t v = 0; v < size; v++){
            //compare the distances and add the values to queue
            if (adjMatrix[u][v] && dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                queue.push(v);
            }
        }
    }

    // Handle the no path case
    if (dist[verticeEnd] == INT_MAX) {
        returnElement = vector<Vertex>{{"No path found"}};
        return Path(-1, returnElement);
    }

    // Trace back the path from end vertex to start vertex
    int trace = verticeEnd;
    while (trace != verticeStart) {
        returnElement.insert(returnElement.begin(), vertices[trace]);
        // Find the previous vertex in path
        for (size_t i = 0; i < size; i++) {
            if (adjMatrix[i][trace] && dist[i] == dist[trace] - 1) {
                trace = i;
                break;
            }
        }
    }
    returnElement.insert(returnElement.begin(), vertices[verticeStart]);

    return Path(verticeEnd, returnElement);
}