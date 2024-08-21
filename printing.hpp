#ifndef Printing
#define Printing

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <variant>
#include <unordered_map>
using namespace std;



template <typename Y> void printArray(vector<Y> * arr){
    cout << "[";
    for(int i =0 ; i < (*arr).size(); i++){
        cout << (*arr)[i] << ",";
    }
    cout << "]" << endl;
}

#endif