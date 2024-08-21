#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <variant>
#include <unordered_map>
#include "DB.h"
#include "printing.hpp"

using namespace std;
using AllPermmittedTypes = variant<int,string,double,float,char,bool>;


// when we want to create a row we have to specify the parent Table as well as the element
// for example Row(parentTable, elements)



int main(){
    vector<DataBase> MaindDBHolder = {};
    vector<int> arr = {1,2,3};
    printArray<int>(&arr);
    return 0;

}