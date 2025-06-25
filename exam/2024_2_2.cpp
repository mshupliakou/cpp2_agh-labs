//documentation and comments are wrtitten in Polish
//2024 rok 2 termin 2 zadanie:

// ROZWIĄZANIE

#include <iostream>
#include <list> // dla list

//klasa szabonowa array
template<typename T>
class array{
T* arr;
int s;
public:
using value_type =T;//member type
array(std::initializer_list<T> k){//konstruktor przejmujący liste inicjalazacyjną. jak tego wymaga zadanie
//konwertuje niejawnie 
	std::list<T> l =k;
	s=k.size();
	arr = new T[l.size()]; //żeby ta linijka była możliwa, żeby zaalokować pamięć dla tablicy mamy mieć default consructor dla box
	auto first = l.begin();//iterator dla przesunęcia się po liście
	for(int i=0; i<l.size(); i++){
		arr[i]=*first;//żeby ta linijka była wykonywalna potrzebujemy mieć konstruktor, który konwertowałby z T na box
		first++;//możliwę kjest przesunęcie tylko o jedną pozycję naprzód
	}
	}

	array(const array& other):arr(new T[other.s]), s(other.s){
		for(int i=0; i<s; i++){
			arr[i]=other.arr[i];//kopije każdy element. jest to możliwe dzięki copy constructor w box
		}
	} //konstruktor kopiujący dla całej tablicy

	T& operator[](int i){//przeładowanie operatora []. w przypadku podania ujemnego indexu tez ma swoją logikę
		if(i<0){return arr[i+s];}
		else return arr[i];
	}
	const T& operator[](int i) const{// to samo dla elementów const
		if(i<0){return arr[i+s];}
		else return arr[i];
	}

	int size()const{ return s;} //zwraca rozmiar

	~array(){ //simple destructor
		delete[] arr;
	}

};


//klasa szablnowa box
template<typename T=int>
class box{
T number;
public:
using value_type =T;//member type
box():number(0){} //default constructor
box(T number):number(number){} //constructor
box(const box& other):number(other.number){}//konstruktor kopiyjący
friend std::ostream& operator<<(std::ostream& os, const box& smth){//przeładowanie operatora <<
	return os<<smth.number;
}
void operator=(T i){ //operator konwerujący z T do box
	number =i;
}
};

//funkcja szablonowa print(wypisuje array)
template<typename T>
void print(T tab){
	for(int i=0; i<tab.size(); i++){
		std::cout<<tab[i]<<","; // żeby ta linijka się kompilowała w box musi być przeładowany operator <<
	}
	std::cout<<"\n";
}

int main()
{
    array<box<>> a = {5, 6, 7}; // Inicjalizacja tablicy z wartościami
    const array<box<>> b = a;   // Kopiowanie tablicy

    a[-1] = array<box<>>::value_type{2}; // Ustawienie wartości w ostatnim elemencie
    a[-a.size()] = box<>::value_type{3}; // Ustawienie wartości w pierwszym elemencie

    print(a); // Wydrukowanie tablicy a
    print(b); // Wydrukowanie tablicy b
}



//ZADANIE

// int main()
// {
//     array<box<>> a = {5, 6, 7}; // Inicjalizacja tablicy z wartościami
//     const array<box<>> b = a;   // Kopiowanie tablicy

//     a[-1] = array<box<>>::value_type{2}; // Ustawienie wartości w ostatnim elemencie
//     a[-a.size()] = box<>::value_type{3}; // Ustawienie wartości w pierwszym elemencie

//     print(a); // Wydrukowanie tablicy a
//     print(b); // Wydrukowanie tablicy b
// }