#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>
#include <cstring>
#include <functional>

///@brief describes a class of complex numbers
class Complex{
    double a; //re
    double b; //im
    public:

    //default constructor
    Complex():a(0), b(0){}

    //constructor
    Complex(double a, double b):a(a), b(b){}

    //overloading ostream operator <<
    friend std::ostream& operator <<(std::ostream& os, const Complex& complex);

    //overloading operator +
    Complex operator+(const Complex& complex);

    //overloading operator *
    Complex operator*(const Complex& complex);

    //overloading operator -
    Complex operator-(const Complex& complex);

    //overloading operator -
    Complex operator/(const Complex& complex);

    //conversion to double
    operator double();

    //explicit conversion to string
    explicit operator std::string(){
        std::string answ;
        answ+=std::to_string(int(a));
        if(b>=0){
            answ+=" + ";
            answ+=std::to_string((int)b);
        }

        else{
            answ+=" - ";
            answ+=std::to_string((int)-b);
        }
        answ+="i";
        return answ;
    }

    double operator()(std::function<double(const Complex&)> f);
    
};
std::ostream& operator <<(std::ostream& os, const Complex& complex);

#endif