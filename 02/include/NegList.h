#include <iostream>
#ifndef NEGLIST_H
#define NEGLIST_H
class ListInspector;

///@brief class NegList describes a list which uses negative values as indexes
class NegList{
    int* list;
    int size;
    ListInspector * list_inspector;
    public:

    // default constructor
    NegList():list(nullptr), size(0), list_inspector(nullptr){}


    //destructor
    ~NegList();

    ///@brief adds a value to a list (simmilar to Python )
    ///@param number the number we are going to add
    void append(int number);

    // simple getter
    int getSize()const;

    // setter for inspector
    void setInspector(ListInspector * l);

    // operator [] overoading. Using negative values as indexes
    int& operator[](int i);

    ///@brief function deletes the last element of array(list)
    void pop();
};

#endif