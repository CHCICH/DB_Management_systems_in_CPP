#ifndef DB_H
#define DB_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <variant>
#include <unordered_map>
using namespace std;


using AllPermmittedTypes = variant<int,string,double,float,char,bool>;

// we are trying to create an abstract class to create hybrid databases tables thus we need
// to create some creation function to mimic Scripting query languages
// the schema of the function looks like this 

// create a db => connect to it=> create a table => create a column or a label then store the data inside of the table

class Column{
    public:
        string columnName;
        string dataType;
    Column(string name,string type){
        columnName = name;
        dataType = type;
    }
};

class Table{
    public:
        string TableName = "";
        bool isTableActive = false;
        vector <Column> ColumnList = {};
        vector <unordered_map<string,AllPermmittedTypes>> RowList = {}; 
    Table(string name){
        TableName = name;
    }

    void InsertAColumn(string columnName,string columnType){
        if(isTableActive){
            cout << "we cannot create a column because the table already contains data "<< endl;
            cout << "either create a new table or empty the Table to procced" << endl;
        }else if (ColumnList.size() >= 0 ){
            Column * newColumn = new Column(columnName,columnType);
            ColumnList.push_back((*newColumn));
            delete newColumn;
            newColumn = nullptr;
            cout << "column was created" << endl;
        }
    }
    unordered_map<string,AllPermmittedTypes> CreateARow (vector<AllPermmittedTypes> element_given){
        unordered_map <string,AllPermmittedTypes> FinalReturnedMap;
        for( int i = 0; i < element_given.size();i++){
            FinalReturnedMap.insert({(this->ColumnList)[i].columnName,element_given[i]});
        }
        return FinalReturnedMap;
    }
    void InsertARow(vector<AllPermmittedTypes> ** elementList){

        if((**elementList).size() != this->ColumnList.size()){
            cout << "Error you cannot insert this row because the number of element inserted is diffrent than the number of column availble"<< endl;
        }else{
            bool IsError = false;
            for(int i = 0 ; i< (**elementList).size(); i++){
                if((this->ColumnList)[i].dataType != typeid((**elementList)[i]).name()){
                    cout << "error you cannot have to insert the element with the same type respectively to the refered column number "<< i << endl;
                    IsError = true;
                }
            }
            if(IsError){
                unordered_map<string,AllPermmittedTypes> InsertedElement = this->CreateARow(**elementList);
                RowList.push_back(InsertedElement);
            }else{
                cout << "Please reenter the inserted row "<< endl;
            }
        }
    }
};

class DataBase{
    public:
        vector<Table> TableHolder;
        string DB_Name;
    DataBase(string DB_name){
        TableHolder = {};
        DB_Name = DB_name;
    }
    void createTable(string tableName){
        Table newTable = Table(tableName);
        TableHolder.push_back(newTable);
    }
};

class DBMS{
    public:
        vector<DataBase> DataBaseHolder;
        unordered_map<string,int> pointer_location = {};
        int currentDBPointer;
    DBMS(){
        DataBaseHolder = {};
        currentDBPointer = 0;
    }
    void create_DataBase(string DB_Name){
        DataBaseHolder.push_back(DataBase(DB_Name));
    }
};

#endif