//documentation and comments are wrtitten in Polish
//2021 rok 1 termin 2 zadanie:

// ROZWIĄZANIE
#include <utility> //std::pair
#include <iostream>

template<typename T=float> //klasa szblonowa Type_t opakowuje typ(domyślnie jest float)
class Type_t{
	public:
    T _v;
	explicit Type_t(T _v):_v(_v){} //zadanie wymaga zakazania niejawnej konwersji, dlatego w tym konstruktotze 
    //używa się explicit
    Type_t() :  _v(0) {} // konctruktor domyślny
    friend std::ostream& operator<<(std::ostream& os, Type_t& t) { //przeładowanie operatora <<
        return os<<t._v;
    }
    Type_t(const Type_t&) = delete; //usuwanie konstruktora kopijuącego
};

template<typename T> //klasa szablonowa ptr zachowuje wskaźnik typu T
class ptr{
T* a;
public:
using value_type=T; //traktujemy value_type jako T
ptr(const ptr& other)=delete; // usuwamy konstruktor kopijący bo tego wymaga zadanie
ptr& operator=(const ptr& other)=delete; // usuwamy operator przypisania, bo tego wymaga zadanie
explicit ptr(T* a):a(a){} //konstruktor. słowo kluczowe explicit zakazuje na niejawne konwersje

//semantyka przenoszenia
ptr( ptr&& other){ //koncruktor przenoszący
    delete a;
	a=other.a;
	other.a = nullptr;
}

//operator przenoszący
ptr& operator=( ptr&& other){
	if(this!=&other){
        delete a;
		a=other.a;
		other.a = nullptr;	
	}
	return *this;
}

//przeładowanie operatorów * i ->. metody sa const, żeby działac na const obiektach
T& operator*() const {return *a;}
T* operator->() const {return a;}
};

using Float_t = Type_t<>;

int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>; //

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t2; t2 = t1;
    // Type_t t2 = new Type_t::value_type();
    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.};
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);
    std::cout << (*t2).first << ", " << t2->second._v << "\n";

    const Type_t t3 = std::move(t2);     
    // t3=std::move(t2);                      
    // (*t3).first= 13;
    // t3->second = 13;
    // Powyższe się mają nie kompilować

    (*t3).first = Type_t::value_type::first_type{1};   
    t3->second = Type_t::value_type::second_type{2.5};

    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
1, 2.5
*/


// POLECENIE

// int main()
// {
//     using Type_t = ptr<std::pair<Float_t, Float_t>>; //

//     Type_t t1{new Type_t::value_type{}};
//     // Type_t t2 = t1;
//     // Type_t t2; t2 = t1;
//     // Type_t t2 = new Type_t::value_type();
//     // Powyższe się mają nie kompilować
//     (*t1).first = Type_t::value_type::first_type{1.};
//     t1->second = Type_t::value_type::second_type{2.5};

//     Type_t t2 = std::move(t1);
//     std::cout << (*t2).first << ", " << t2->second._v << "\n";

//     const Type_t t3 = std::move(t2);     
//     // t3=std::move(t2);                      
//     //(*t3).first= 13;
//     // t3->second = 13;
//     // Powyższe się mają nie kompilować

//     (*t3).first = Type_t::value_type::first_type{1};   
//     t3->second = Type_t::value_type::second_type{2.5};

//     std::cout << (*t3).first._v << ", " << t3->second << std::endl;
// }
// /* output:
// 1, 2.5
// 1, 2.5
// */