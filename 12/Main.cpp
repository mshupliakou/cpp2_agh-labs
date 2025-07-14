#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::pair
#include "Describe.hpp"
//
// Celem zadania jest zaimplementowanie funkcji `describe`, która przyjmuje
// dane różnych typów i zwraca ich tekstowy opis jako `std::string`.
//
// Funkcja powinna być szablonowa oraz wspierać:
//    pełną specjalizację (np. `bool`),
//    częściową specjalizację (np. `std::vector<T>`),
//    `std::pair<T1, T2>` (obowiązkowo!),
//    rekurencję dla zagnieżdżonych kontenerów,
//    `auto` jako typ zwracany.
//
// WYMAGANIA (OBOWIĄZKOWE):
//
// 1. Ogólny szablon:
//      template<typename T>
//      auto describe(const T& value) -> std::string;
//
//    powinien zwracać np.:
//      - "int: 42"
//      - "std::string: Hello"
//
// 2. Pełna specjalizacja dla `bool`:
//      - describe(true)  → "true"
//      - describe(false) → "false"
//
// 3. Częściowa specjalizacja dla `std::vector<T>`:
//      - np. describe(std::vector<int>{1, 2})
//        → "std::vector of 2 elements: [int: 1, int: 2]"
//      - Rekurencyjne działanie dla zagnieżdżonych kontenerów
//
// 4. Szablon `describe` dla `std::pair<T1, T2>`:
//      - np. describe(std::pair<int, std::string>{7, "cat"})
//        → "(int: 7, std::string: cat)"
//
// 5. Typ zwracany funkcji powinien być określony za pomocą `auto -> std::string`.
//
// -------------------------
// DLA AMBITNYCH (opcjonalne):
// -------------------------
//
//  Użyj `if constexpr` i `std::is_same_v<T, ...>` aby własnoręcznie określać nazwę typu,
//     zamiast korzystać z `typeid(T).name()` (który daje niezrozumiałe nazwy typu).
//
//  Dodaj własną funkcję `type_name<T>()` i używaj jej w `describe(...)`
//
//  UWAGA: Wersje z `typeid(...)` działają, ale mogą wypisywać niezrozumiałe nazwy ABI.
//  https://en.cppreference.com/w/cpp/types/is_same.html
//  https://en.cppreference.com/w/cpp/language/constexpr.html
//




int main() {
    std::cout << describe(42) << "\n";                     
    std::cout << describe(3.14) << "\n";                   
    std::cout << describe(std::string("C++")) << "\n";     
    std::cout << describe(true) << "\n";                    
    std::cout << describe(false) << "\n";                 

    std::vector<int> numbers = {1, 2, 3};
    std::cout << describe(numbers) << "\n";                

    std::vector<std::vector<int>> nested = {{1, 2}, {3}};
    std::cout << describe(nested) << "\n";                 

    std::pair<int, std::string> p = {7, "cat"};
    std::cout << describe(p) << "\n";                     

    return 0;
}


//
// Przewidywany output:

//  Wersja bez constexpr z std::is_same_v
//  i: 42
//  d: 3.14
//  NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE: C++
//  true
//  false
//  std::vector of 3 elements: [i: 1, i: 2, i: 3]
//  std::vector of 2 elements: [std::vector of 2 elements: [i: 1, i: 2], std::vector of 1 elements: [i: 3]]
//  (i: 7, NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE: cat)
//  
//
//  Wersja z constexpr z std::is_same_v
//  int: 42
//  double: 3.14
//  std::string: C++
//  true
//  false
//  std::vector of 3 elements: [int: 1, int: 2, int: 3]
//  std::vector of 2 elements: [std::vector of 2 elements: [int: 1, int: 2], std::vector of 1 elements: [int: 3]]
//  (int: 7, std::string: cat)