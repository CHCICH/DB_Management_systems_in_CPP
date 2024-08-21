#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <variant>
#include <unordered_map>
using namespace std;

// building  all components of a sql compiler which is going to parse the query assign to each algberic sign its own operation and then
// the resulted data is going to optimize the query in order to access the data quickly and find the most effiecent way and finally the query executer
// is a instance that is going to plan all the action that sould be done

class Compiler{
    public:
        Query_parser parser = Query_parser();
        Algebrizer opterator_assigner = Algebrizer();
        Query_Optimizer optimizer = Query_Optimizer();
        Query_exectionner plan_exection = Query_exectionner();

};

class Query_parser{

};

class Algebrizer{

};

class Query_Optimizer{

};



class Query_exectionner{

};

#endif
