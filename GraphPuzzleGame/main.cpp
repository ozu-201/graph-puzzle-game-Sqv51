//
// Created by yk029484 on 12/14/2023.
//
#pragma once
#include <vector>
#include "GraphPuzzleGame.h"
#include <string>
#include <fstream>


using namespace std;
int main(){
    cout << "hello" <<endl;
    //vector of strings
    auto strVector = new vector<string>;

    ifstream MyReadFile("dictionary.txt");
    string myText;

    while(getline(MyReadFile,myText)){
        //add all dictionary to vector
    }
    MyReadFile.close();




    //ask input either 3 4 or 5
    int x;
    cout << "Type 3, 4 or 5: ";
    cin >> x;

    //user input

    if (x==3){
        //filter the vector and construct a graph
    }
    else if(x==4){
        //word graph
    }
    else if(x==5){
        //word graph
    }
    else{cout<<"GEÇERSİZ";}



    //ask word1 and word2

    //BFS

    //Djikstra

};
