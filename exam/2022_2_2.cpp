//documentation and comments are wrtitten in Polish
//2022 rok 2 termin 2 zadanie:

// ROZWIĄZANIE

/*
Proszę uzupełnić program, stosując standard nie niszy ni C++14, tylko w podanych miejsach 
i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
komentarzu na koncu kodu. Proszę podać najprostszą moliwą poprawnie działającą 
implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi uzycie 
konstrukcje. Brak poprawnego uzasadnenia lub niespełnienie warunkow jest roznoznaczne z 
brakiem odpowiedzi.
*/
#include <iostream>

//deklaracja struktury szablonowej
template<typename T>
struct B;

//definicja struktury szablonowej B
template<typename T>
struct B
{
T smth; 
B(T smth):smth(smth){} // konstruktor z listą inicjalizycyjną
B(const B& other):smth(other.smth){} // konstruktor kopiujący
using value_type=T; // member type
T& get(){ //funkcja zracająca zawartość zmiennej smth
    return smth;
}
private:
    value_type _v = value_type();
};

//specjaklizacja struktury szablonowej dla wskaźników
template<typename T>
struct B<T*>
{
T* smth;
B(T* smth):smth(smth){}
B(const B& other)=delete;//konstruktor kopijący jest usunięty. tak tego wymaga zadanie
B& operator=(const B& other)=delete; // usuwanie domyślnego operatora kopiowania
using value_type =T; // member type
T& get(){ // zwracamy wartość zmiennej smth
    return *smth;
}
private:
    value_type _v = value_type();
};

int main()
{
    typedef B<int> int_b;
    typedef B<int*> int_p_b;   

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    // int_p_b e = b; //error //musimy usunąc konstruktor kopiujący
    // b=b //error // musimu usunąć domyślny operator kopiowanie
    
    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout <<"b=" << b.get()+1 << std::endl;
}
/*
a=1
a_copy=2
b=3
*/


// ZADANIE


// /*
// Proszę uzupełnić program, stosując standard nie niszy ni C++14, tylko w podanych miejsach 
// i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
// komentarzu na koncu kodu. Proszę podać najprostszą moliwą poprawnie działającą 
// implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi uzycie 
// konstrukcje. Brak poprawnego uzasadnenia lub niespełnienie warunkow jest roznoznaczne z 
// brakiem odpowiedzi.
// */
// #include <iostream>

// template<typename T>
// struct B;

// template<typename T>
// struct // U1
// {
//     //U2
// private:
//     value_type _v = value_type();
// };

// template<typename T>
// struct // U3
// {
//     //U4
// private:
//     value_type //U5
// };

// int main()
// {
//     typedef B<int> int_b;
//     typedef B<int*> int_p_b;   

//     int_b a(1);
//     int_b a_copy(a);
//     int_p_b b(new int_p_b::value_type{2});
//     // int_p_b e = b; //error
//     // b=b //error
    
//     std::cout << "a=" << a.get() << std::endl;
//     std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
//     std::cout <<"b=" << b.get()+1 << std::endl;
// }
// /*
// a=1
// a_copy=2
// b=3
// */