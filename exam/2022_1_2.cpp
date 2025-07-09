//documentation and comments are wrtitten in Polish
//2022 rok 1 termin 2 zadanie:

// ROZWIĄZANIE

 /* 
Proszę dokończyć program tylko w podanych miejscach i zgodnie z podanymi warunkami, tak
aby wyjście programi było takie jak podany na w komantarzu na 
końcu kodu. W rozwiązaniach proszę uywać C++ w standardzie przynajmniej C++11 lub 14, 
wszędzie tam gdzie jest to moliwe i uzasadnione. Prosze podać naprostszą mozliwa 
*/

#include <iostream>
#include <list>
#include <string>

//funkcja szablonowa która wypisuje elementy kontenerów, jeśli te są zwrócone przez funkcję
template< typename Iter, typename Fun>
void print_to_if(std::ostream& os, Iter first, Iter last, Fun f){
	while(first!=last){//przechodzimy po iteratorach 
		if(f(*first)) //jeżeli funckcja funktor zwróci true to element zostanie wypisany
			os<<(*first)<<",";
		first++;
	}
	os<<std::endl;
}

//funkcja która prowadzi zmiany na elementach
template<typename Iter, typename Fun>
void change(Iter first, Iter last, Fun f){
    while(first!=last){
		f(*first); //wyłowanie funkcji która zmienia element
		first++;
	}
}

//funkcja która zawsze zwraca prawdę(można wypisać wszystkie elementy)
bool f1(int smth){
	return true;
}

//funkcja wykrywa elementy parzyste
bool f2(int smth){
	if(smth%2==0)return true;
	else return false;
}

//funktor. pozwala zmienić element. 
template<typename T=int>
class f3{
	T a;
	public:
	f3(T a):a(a){} // przez konstruktor ustawiamy znaczenie dla a
	//przeładowanie operatora ()
	void operator()(T& val){
		val+=a; //funktor dodaje a do elementu
	}
};



int main()
{
     const auto c1 = {1, 2, 3, 4, 5, 6, 7};

     print_to_if(std::cout << "All: ", begin(c1), end(c1), f1);
     print_to_if(std::cout << "Even: ", begin(c1), end(c1), f2);
     int add_value{-1};
     std::list<int> c12 = {7, 6, 5, 4, 3, 2, 1};
     change(begin(c12), end(c12), f3{add_value});

     print_to_if(std::cout << "All: ", begin(c12), end(c12), f1);
 }
// /*
// All: 1,2,3,4,5,6,7,
// Even: 2,4,6,
// All: 6,5,4,3,2,1,0,
// */


// ZADANIE

// /* 
// Proszę dokończyć program tylko w podanych miejscach i zgodnie z podanymi warunkami, 
//tak aby wyjście programi było takie jak podany na w komantarzu na końcu kodu.
// W rozwiązaniach proszę uywać C++ w standardzie przynajmniej C++11 lub 14, 
//wszędzie tam gdzie jest to moliwe i uzasadnione. Prosze podać naprostszą
// mozliwa działającą implementację. Proszę dokładnie uzasadnić odpowiedź.
// */

// #include <iostream>
// #include <list>

// template</*U1*/>
// void print_to_if(/*U2*/){
//     /*U3*/
// }

// template</*U4*/>
// void change(/*U5*/){
//     /*U6*/
// }

// /* U7 - mogą być tylko definicję f1, f2, f3 */

// int main()
// {
//     const auto c1 = {1, 2, 3, 4, 5, 6, 7};

//     print_to_if(std::cout << "All: ", begin(c1), end(c1), f1);
//     print_to_if(std::cout << "Even: ", begin(c1), end(c1), f2);
//     int add_value{-1};
//     std::list<int> c12 = {7, 6, 5, 4, 3, 2, 1};
//     change(begin(c12), end(c12), f3{add_value});

//     print_to_if(std::cout << "All: ", begin(c12), end(c12), f1);
// }
// /*
// All: 1,2,3,4,5,6,7,
// Even: 2,4,6,
// All: 6,5,4,3,2,1,0,
// */