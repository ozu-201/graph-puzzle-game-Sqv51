//
// Created by yk029484 on 12/21/2023.
//
#include <iostream>
#include "Queue.cpp"
#include "Graph.h"
#include "Graph.cpp"

using namespace std;





int main(){

    //construct the graph from the txt file, file shoult be in working directory or you must write explicit file location
    Graph graph1 = Graph(5,"turkish-dictionary.txt");
    graph1.findShortestPath("tamam","devam").printPath();


    Graph graph2 = Graph(4,"english-dictionary.txt");
    graph2.findShortestPathDjikstra("cone","mole").printPath();

    Graph graph3(3,"english-dictionary.txt");
    graph3.addWord("cat");
    graph3.addWord("cot");
    graph3.addWord("cog");
    graph3.addWord("dog");
    graph3.addEdge("cat", "cot");
    graph3.addEdge("cot", "cog");
    graph3.addEdge("cog", "dog");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (3 letter words)\n";
    std::cout << "Shortest Path from 'cat' to 'dog' (BFS):\n";
    graph3.findShortestPath("cat", "dog").printPath();
    std::cout << "Shortest Path from 'cat' to 'dog' (Dijkstra):\n";
    graph3.findShortestPathDjikstra("cat", "dog").printPath();
    std::cout << "------------------------------------------\n";


    // Test Case: Adding Edges with One-Letter Difference (4 letter words)
    Graph graph4= Graph(4,"english-dictionary.txt");
    graph4.addWord("dark");
    graph4.addWord("bark");
    graph4.addWord("barn");
    graph4.addEdge("dark", "bark");
    graph4.addEdge("bark", "barn");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (4 letter words)\n";
    std::cout << "Shortest Path from 'dark' to 'barn' (BFS):\n";
    graph4.findShortestPath("dark", "barn").printPath();
    std::cout << "Shortest Path from 'dark' to 'barn' (Dijkstra):\n";
    graph4.findShortestPathDjikstra("dark", "barn").printPath();
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (5 letter words)
    Graph graph5= Graph(5,"english-dictionary.txt");
    graph5.addWord("stone");
    graph5.addWord("store");
    graph5.addWord("score");
    graph5.addEdge("stone", "store");
    graph5.addEdge("store", "score");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (5 letter words)\n";
    std::cout << "Shortest Path from 'stone' to 'score' (BFS):\n";
    graph5.findShortestPath("stone", "score").printPath();
    std::cout << "Shortest Path from 'stone' to 'score' (Dijkstra):\n";
    graph5.findShortestPathDjikstra("stone", "score").printPath();
    std::cout << "------------------------------------------\n";


    return 0;
}


