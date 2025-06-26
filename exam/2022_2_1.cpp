#include<iostream>

using namespace std; //korzystamy z przestrzeni nazw std(nie musimy pisać std:: przed nazwą każdej funkcji //
//standardowej)

struct A
{   
    //knstruktor z lista inicjalizacyjną
    explicit A(int _a, int _b):_a(_a), _b(_b){
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<", _b="<<_b<<std::endl;
    }

    //konstruktor domyślny.
    explicit A():A(0,0){
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<", _b="<<_b<<std::endl;
    }

    //konstruktor który pryjmuje jeden argument. powinien być explicit, bo tak tego wymaga zadanie 
    //(niemożliwe stają się konwersje niejawne)
    explicit A(int _a):A(_a,0){
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<", _b="<<_b<<std::endl;
    }

    //konstruktor kopijący. też ma być explicit
    explicit A(const A& other):_a(other._a), _b(other._b){}

    //konstruktor przenoszący
    A(A&& other):_a(other._a), _b(other._b){
        std::cout<<__PRETTY_FUNCTION__<<": _a="<<_a<<", _b="<<_b<<std::endl;
    }
//U2
//tylko konstruktory, zakaz użycia delete, w {} tylko printowanie __PRETTY_FUNCTION__ (oraz _a,_b)
private:
    int _a=0, _b=0;
};

int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    //A e = c;
    //A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/