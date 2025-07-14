#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>

///@brief main template function
///@return string with description of element
template<typename T>
auto describe(const T& value) -> std::string{
    std::string type=typeid(T).name();
    return type+": "+std::to_string(value);

}

///@brief full specialization for strings
///@return string with description of element
template<>
auto describe<std::string>(const std::string& value)-> std::string{
    std::string type = typeid(std::string).name();
    return type+": "+value;
}

///@brief full specialization for booleans
///@return string with description of element
template<>
auto describe<bool>(const bool& value)-> std::string{
    std::string type = typeid(bool).name();
    std::string v;
    if(value==1)
    v="true";
    else
    v = "false";
    return type+": "+v;
}

///@brief  specialization for std::pair
///@return string with description of pair and elements it contains
template<typename T1, typename T2>
auto describe(std::pair<T1, T2> p)-> std::string{
    std::string type1 = typeid(T1).name();
    std::string type2 = typeid(T2).name();
    return "("+type1+":"+std::to_string(p.first)+ ", "+type2+":"+ p.second+" ) ";
}

///@brief  specialization for std::vector
///@return string with description of std::vector and elements it contains
template<typename T>
auto describe(std::vector<T> v)-> std::string{
    std::string type = typeid(T).name();
    std::string s= "std::vector of "+std::to_string(v.size())+" elements : [";
    std::string s2="";
    std::for_each(v.begin(), v.end(), [&s2, &type](int x){
        s2+=type+": "+std::to_string(x)+",";
    });
    s2+="]";
    return s+s2;
}


///@brief  specialization for std::vector which contains vectors
///@return string with description of std::vector and elements it contains
template<typename T>
auto describe(std::vector<std::vector<T>> v)-> std::string{
    std::string s="std::vector of "+std::to_string(v.size())+" elements: [";
    std::for_each(v.begin(), v.end(), [&s](std::vector<T> t){
        s+=describe(t)+", ";
    });
    return s+"]";
}