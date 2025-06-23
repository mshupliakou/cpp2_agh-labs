//documentation and comments are wrtitten in Polish
//2021 rok 1 termin 1 zadanie:

// int main()
// {
//     typedef ::OOP::Array<int> type;
//     type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

//     a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');

//     ++a[0];
//     for (unsigned i = 0; i != ~a; i++)
//     {
//         std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
//     }
// }

//Output: #_P_O_-_E_G_Z_1

#include <iostream>

namespace OOP{/* z pierwszej linijki w main widać, że chcielibyśmy żeby nasza klasa znalazłaby się w 
namespace OOP. Dlatego tu go definiujemy*/
template<typename T> //klasa Array z której będziemy korzystac jest szablonową
class Array{ // definicja klasy Array, która będzie zawierała głównie tablicę i rózne metody do pracy z nią
	int s; // rozmiar tablicy
	int current_s; // ile elementów w tablicy jest teraz
	T* array; // tablica
public:
	using value_type =T; // definiujemy value_type w taki sposób, żeby można było go odczytać w main

	Array(int s):s(s), array(new T[s]), current_s(0){}//konstruktor

	template<typename B>//szablon natomiast pozwala wstawiac elementy inne niż T
	Array& insert(B a){//metoda szablonowa, która pozwala wstawiać nowe elementy do tablicy
		if(current_s<s){
		array[current_s]=static_cast<T>(a);//konwersja z B do T
		current_s++;}
		return *this;
	}

	template<typename B>
	Array& operator%(B a){//operator który robi generalnie to samo co metoda isert()
		return insert(a);
	}
	
	T& operator[](int i){// przeładowanie operatora []
		return array[i];
	}
	const T& operator[](int i) const{// przeładowanie operatora [] dla elementów stałych
		return array[i];
	}
	
	int operator ~(){//operator zracający obecny rozmiar tablicy
		return current_s;
	}

    ~Array() { delete[] array; }// destruktor




};

};


int main()
{
    typedef ::OOP::Array<int> type;
    type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

    a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');

    ++a[0];
    for (unsigned i = 0; i != ~a; i++)
    {
        std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
    }
}
//#_P_O_-_E_G_Z_1