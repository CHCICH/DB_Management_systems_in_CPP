#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <variant>
#include <unordered_map>
#include "DB.h"

using namespace std;
using AllPermmittedTypes = variant<int,string,double,float,char,bool>;


// when we want to create a row we have to specify the parent Table as well as the element
// for example Row(parentTable, elements)



int main(){
    vector<DataBase> MaindDBHolder = {};
    return 0;

}