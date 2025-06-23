//documentation and comments are wrtitten in Polish
//2021 rok 2 termin 1 zadanie:

// ROZWIĄZANIE
#include <iostream>

/*
A::A();B::B();Y::Y();B::B();X::X();Z::Z();
Schemat :
   A   B  B
   \ /    |
    Y    X
    \   /
      Z
*/

//klasa bazowa
class A{
    //musi byc public/protected
	public:
	A(){std::cout<<__PRETTY_FUNCTION__<<";";}
	~A(){std::cout<<__PRETTY_FUNCTION__<<";";}

};

//klasa bazowa
class B{
	public:
    //musi byc public/protected
	B(){std::cout<<__PRETTY_FUNCTION__<<";";}
	~B(){std::cout<<__PRETTY_FUNCTION__<<";";}
};

class Y:public A, public B{
	public:
    //musi byc public/protected
	Y(){std::cout<<__PRETTY_FUNCTION__<<";";}
	~Y(){std::cout<<__PRETTY_FUNCTION__<<";";}
};

class X:public B{
	public:
    //musi byc public albo protected
	X(){std::cout<<__PRETTY_FUNCTION__<<";";}
	~X(){std::cout<<__PRETTY_FUNCTION__<<";";}
};

// Z jest klasą najbardziej pochodną która dziedziczy po inncych klasach. można to zrozumiec, bo
//konstruktor jest wywoływany ostatnio
class Z:public Y, public X{
	public:
    //musi byc public
	Z(){std::cout<<__PRETTY_FUNCTION__<<";\n";}
	~Z(){std::cout<<__PRETTY_FUNCTION__<<";";}
};

int main() { Z z; }

/*standardowe wyjście
A::A();B::B();Y::Y();B::B();X::X();Z::Z();
Z::~Z();X::~X();B::~B();Y::~Y();B::~B();A::~A();
*/



//ZADANIE

/*W klasie dozowlone jest tylko zdefiniowanie konstruktora i destruktora oraz może być tylko zdefiniowany
std::cout<<__PRETTY_FUNCTION__<<";"; lub
std::cout<<__PRETTY_FUNCTION__<<"\n";
*/
//int main() { Z z; }
/*standardowe wyjście
A::A();B::B();Y::Y();B::B();X::X();Z::Z();
Z::~Z();X::~X();B::~B();Y::~Y();B::~B();A::~A();
*/