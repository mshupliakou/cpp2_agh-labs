//documentation and comments are wrtitten in Polish
//2021 rok 2 termin 2 zadanie:

// ROZWIĄZANIE

#include <iostream>
#include <memory>
#include <array>

//wyświetlanie string'a
void my_print_el(std::string s){
	std::cout<<s;
}

//funkcja szablonowa która wyświetla tablicę ptr'ow
template<typename T>
void my_print(const T& ar, const char* s1=";", const char* s2="\n"){//są argumenty domyślne
	std::cout<<"[";
	for(const auto& el: ar){
		std::cout<<*el<<s1;
	}
	std::cout<<"]"<<s2;
}

//funkcja szablonowa która zamienia miejscami dwa unique_ptr
template<typename T>
void my_swap(T& a1, T& a2){
	T copy=std::move(a1); //można tylko przenosic
	a1=std::move(a2);
	a2=std::move(copy);
}

int main()
{
  std::array<std::unique_ptr<int>,2>a={std::unique_ptr<int>(new int {1}), std::unique_ptr<int>(new int {2})};

  my_print_el("----------------\n");
  my_print(a,";"," -> ");
  my_swap(a[0],a[1]);
  my_print(a,";"," -> ");
  my_swap(*a[0],*a[1]);
  my_print(a);
  my_print_el("----------------");
}
/*
----------------
[1;2;] -> [2;1;] -> [1;2;]
----------------
*/



//ZADANIE

// int main()
// {
//   std::array<std::unique_ptr<int>,2>a={std::unique_ptr<int>(new int {1}), std::unique_ptr<int>(new int {2})};

//   my_print_el("----------------\n");
//   my_print(a,";"," -> ");
//   my_swap(a[0],a[1]);
//   my_print(a,";"," -> ");
//   my_swap(*a[0],*a[1]);
//   my_print(a);
//   my_print_el("----------------");
// }
// /*
// ----------------
// [1;2;] -> [2;1;] -> [1;2;]
// ----------------
// */