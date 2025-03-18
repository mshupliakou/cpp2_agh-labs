#include <iostream>
#include "Complex.h"

std::ostream& operator <<(std::ostream& os, const Complex& complex){
    if(complex.b>=0)
    os<<complex.a<<" + "<<complex.b<<"i";
    else
    os<<complex.a<<" - "<<-complex.b<<"i";
    return os;
}

Complex Complex::operator+(const Complex& complex){
    return Complex(complex.a+a, complex.b+b);
}

Complex  Complex::operator*(const Complex& complex){
    double re=complex.a*a-complex.b*b;
    double im= b*complex.a+complex.b*a;
    return Complex(re, im);
}

Complex  Complex::operator-(const Complex& complex){
    return Complex(a-complex.a, b-complex.b);
}

Complex  Complex::operator/(const Complex& complex){
    Complex c =*this*complex;
    return Complex(c.a/(complex.a*complex.a+complex.b*complex.b), c.b/(complex.a*complex.a+complex.b*complex.b));
}

Complex::operator double(){
    return sqrt((a*a)+(b*b));
}

double Complex::operator()(std::function<double(const Complex&)> f){
    return f(*this);
}
