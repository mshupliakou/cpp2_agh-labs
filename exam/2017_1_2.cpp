//documentation and comments are wrtitten in Polish
//2017 rok 1 termin 2 zadanie:

// ROZWIĄZANIE

#include <iostream>
#include <string>
//klasa bazowa. dla klas którech obiekty się wypisują
class is_printable{
public:
is_printable()=default;

//konstructor kopiujący
is_printable(const is_printable& other)=default;

//funkcja wirualna print(). zwraca string który ma się wypisać gdy sprobujemy wypisać obiekt
// używając operatora <<
virtual std::string print() =0;

//przeładowanie operatora <<
friend std::ostream& operator<<(std::ostream& os,  is_printable& ip){
    return os<<ip.print();
}
};

//klasa A. zawiera string. dziedziczy po is_printable
class A: public is_printable{
std::string text;

public:
//konstruktor
A(std::string text):text(text){}

//konstruktor kopiujący
A(const A& other):text(other.text){}

//metoda print. zwraca text
std::string print(){
    return text;
}
};

//klasa B. zawiera pole typu int. dziedziczy po is_printable
class B: public is_printable{
int number;

public:
B(int number):number(number){}

//konstruktor kopiujący
B(const B& other):number(other.number){}

//metoda print. zwraca number
std::string print(){
    return std::to_string(number);//konwersja do string
}
};

int main() {
	A a{"Tekst"};
	B b{123};

	std::cout << "a=" << a << ";\tb=" << b << ";\n";
	is_printable& a_r = a; is_printable& b_r = b; 
	std::cout << "a=" << a_r << ";\tb=" << b_r << ";\n";

    return 0;
}
/*Wyjście programu*/
//a=Tekst;	b=123;
// a=Tekst;	b=123;

// ZADANIE

// int main() {
// 	A a{"Tekst"};
// 	B b{123};

// 	std::cout << "a=" << a << ";\tb=" << b << ";\n";
// 	is_printable& a_r = a; is_printable& b_r = b; 
// 	std::cout << "a=" << a_r << ";\tb=" << b_r << ";\n";

//     return 0;
// }
// /*Wyjście programu*/
// //a=Tekst;	b=123;
// // a=Tekst;	b=123;