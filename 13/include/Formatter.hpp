#pragma once
#include <iostream>
#include <string>

///@brief main function template to return string with information about something
template <typename T>
std::string format_value(const T t){
    return "VALUE: " + std::to_string(t) + " [x2 = " + std::to_string(2*t) + "]";
}

///@brief specialization for double
template <>
std::string format_value(const double t){
    return "VALUE: " + std::to_string(t) + " [x1.5 = " + std::to_string(1.5*t) + "]";
}

///@brief specialization for boolean
template <>
std::string format_value(const bool t){
    if(t == true)
        return "BOOL: yes (negated: no)";
    else
        return "BOOL: no (negated: yes)";
}

///@brief specialization for string
template<>
std::string format_value(std::string napis)
{
    std::string upper = "";
    for(char i : napis){
        upper += char(toupper(i));
    }
    return "STRING: " + napis + " [" + upper + "!]";
}

///@brief specialization for const char*
std::string format_value(const char* napis)
{
    std::string upper = "";
    for(auto i : std::string(napis)){
        upper += char(toupper(i));
    }
    return "STRING: " + std::string(napis) + " [" + upper + "!]";
}

///@brief specialization for pointers
template<typename T>
std::string format_value(T* t)
{
    if(t == nullptr)
        return "PTR: null";
    else
        return "PTR: " + std::to_string(*t);
}

///@brief main template function which returns the range of two pointers
template<typename T>
std::string format_range(T* q, T* q2)
{
    if(q == q2)
        return "RANGE: empty";
    
    std::string s = "";
    while(q != q2)
    {
        if(!s.empty())
            s += ", ";
        s += std::to_string(*q);
        q++;
    }
    return "RANGE: " + s;
}