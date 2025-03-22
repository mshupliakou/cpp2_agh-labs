#include <iostream>
#include <iostream>
#ifndef LISTLNSPECTOR_H
#define LISTLNSPECTOR_H


class NegList;

///@brief class ListInspector describes an inspector(a tool to inspect some list)
class ListInspector{

    public:

    ///@brief function is used to learn size of the list
    ///@param NegList the list we would like to inspect
    std::string inspect(NegList list);
};






#endif
