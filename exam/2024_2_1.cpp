//documentation and comments are wrtitten in Polish
//2024 rok 2 termin 1 zadanie:

// ROZWIĄZANIE

#include <iostream>
//zadanie polega na utworzeniu strukturt A, która ma pole string i ma również różne konstruktory i oeratory
//struktura A szczegółowo wyświetla informacje o działaniach z nią związanymi
struct A{
	std::string s; // pole string 

    //konstruktor, który również wyświela informacje,że obiekt został stworzony
	A(std::string s):s(s){
	    std::cout<<"Tworzenie: "<<s<<std::endl;
	}

    //konstruktor kopijuący. Wyświetla "kopiowanie wersja 2", bo tak tego wymaga zadanie, żeby zgadzał się output
	A(A& other):s(other.s){
	    std::cout<<"Kopiowanie wersja 2"<<std::endl;
	}

    //operator= kopiowania wyświela informacje,że obiekt został skopiowany
	A& operator=(A& other){
        if(this!=&other){
            s=other.s;
            std::cout<<"Kopiowanie wersja 1"<<std::endl;
        }
        return *this;
	}
	
    //konstruktor prszenoszący, wyświetla informacje,że obiekt został przeniesiony
	A(A&& other){
        s=std::move(other.s);//przenoszneie string innego obiektu do bieżącego
	    std::cout<<"Przenoszenie wersja 2"<<std::endl;
    }

    //operator prszenoszenia wyświetla informacje,że obiekt został przeniesiony
	A& operator=(A&& other){
	    if(this!=&other){
		s=std::move(other.s);
        std::cout<<"Przenoszenie wersja 1"<<std::endl;//ta linijka się wykonuje tylko gdy przenoszenie faktycznie'
        //miało miejsce
        }
	return *this;
	}

};

//funkcja f która przejmuje jako argumnet obiekt A i zwraca obiekt "gotowy do przenoszenia"
auto f(A smth){
	return std::move(smth);
}

int main() 
{ 
    A a("var_a"), b("var_b"); 
 
    std::cout << "(1) -> " 
              << "a.s = " << a.s << " b.s = " << b.s << std::endl; 
    A c = a; 
    std::cout << "(2) -> " 
              << "a.s = " << a.s << " b.s = " << b.s << std::endl; 
    a = b; 
    std::cout << "(3) ->" 
              << "a.s =" << a.s << " b.s = " << b.s << std::endl; 
    a = f(A{"var_c"}); 
 
    std::cout << "(4) -> " 
              << "a.s = " << a.s << " b.s = " << b.s << std::endl; 
    b = std::move(a); 
 
    std::cout << "(5) ->" 
              << "a.s =" << a.s << " b.s = " << b.s << std::endl; 
    b = std::move(b); 
    return 0;
} 
 
/*output: 
Tworzenie: var_a 
Tworzenie: var_b 
(1) -> a.s = var_a  b.s = var_b 
Kopiowanie wersja 2 
(2) -> a.s = var_a  b.s = var_b 
Kopiowanie wersja 1 
(3) -> a.s = var_b  b.s = var_b 
Tworzenie: var_c 
Przenoszenie wersja 2 
Przenoszenie werjsa 1 
(4) -> a.s = var_c  b.s = var_b 
Przenoszenie wersja 1 
(5) -> a.s =   b.s = var_c 
*/

// ZADANIE

// int main() 
// { 
//     A a("var_a"), b("var_b"); 
 
//     std::cout << "(1) -> " 
//               << "a.s = " << a.s << " b.s = " << b.s << std::endl; 
//     A c = a; 
//     std::cout << "(2) -> " 
//               << "a.s = " << a.s << " b.s = " << b.s << std::endl; 
//     a = b; 
//     std::cout << "(3) ->" 
//               << "a.s =" << a.s << " b.s = " << b.s << std::endl; 
//     a = f(A{"var_c"}); 
 
//     std::cout << "(4) -> " 
//               << "a.s = " << a.s << " b.s = " << b.s << std::endl; 
//     b = std::move(a); 
 
//     std::cout << "(5) ->" 
//               << "a.s =" << a.s << " b.s = " << b.s << std::endl; 
//     b = std::move(b); 
//     return 0;
// } 
 
/*output: 
Tworzenie: var_a 
Tworzenie: var_b 
(1) -> a.s = var_a  b.s = var_b 
Kopiowanie wersja 2 
(2) -> a.s = var_a  b.s = var_b 
Kopiowanie wersja 1 
(3) -> a.s = var_b  b.s = var_b 
Tworzenie: var_c 
Przenoszenie wersja 2 
Przenoszenie werjsa 1 
(4) -> a.s = var_c  b.s = var_b 
Przenoszenie wersja 1 
(5) -> a.s =   b.s = var_c 
*/