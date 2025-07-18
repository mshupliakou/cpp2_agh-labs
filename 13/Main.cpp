
/*
 * Celem zadania jest zaimplementowanie funkcji `format_value(...)`
 * oraz `format_range(...)` jako funkcji szablonowych, które elegancko
 * formatują różne typy danych do postaci tekstowej.
 *
 * Wymagane przypadki specjalne:
 *  - `int`, `double` → tekst z drobną manipulacją (np. x2 lub *1.5)
 *  - `bool` → "yes"/"no" oraz wersja zanegowana w nawiasie
 *  - `std::string`, `const char*` → tekst wielkimi literami z sufiksem "!"
 *  - `T*` → dereferencja lub "null"
 *
 * Dodatkowo należy zaimplementować funkcję `format_range(begin, end)`,
 * która działa z zakresami danych (zakres wskaźników), formatowany jako
 * tekst w stylu "1, 2, 3". Jeśli zakres pusty → "empty".
 *
 * --------------------------------------
 * PRZYKŁADOWE REZULTATY DLA `main.cpp`:
 * --------------------------------------
 *
 * format_value(10) → "VALUE: 10 [x2 = 20]"
 * format_value(3.14) → "VALUE: 3.14 [x1.5 = 4.71]"
 * format_value(true) → "BOOL: yes (negated: no)"
 * format_value("hello") → "STRING: hello → HELLO!"
 * format_value(ptr) → "PTR: 42", format_value(nullptr) → "PTR: null"
 * format_range(...) → "RANGE: 1, 2, 3", pusty zakres → "RANGE: empty"
 *
 */


#include <iostream>
#include <vector>
#include <string>
#include "Formatter.hpp"

int main() {
    int x = 42;
    int* pi = &x;
    double* pd = nullptr;
    std::vector<int> v{1,2,3};

    std::cout << format_value(10) << "\n";                  // VALUE: 10 → [10 * 2 = 20]
    std::cout << format_value(3.14) << "\n";                // VALUE: 3.14 → [3.14 * 1.5 = 4.71]
    std::cout << format_value(true) << "\n";                // BOOL: yes → [negated: no]
    std::cout << format_value(false) << "\n";               // BOOL: no → [negated: yes]
    std::cout << format_value("hello") << "\n";             // STRING: hello → [HELLO!]
    std::cout << format_value(std::string("hi")) << "\n";   // STRING: hi → [HI!]
    std::cout << format_value(pi) << "\n";                  // PTR: 42
    std::cout << format_value(pd) << "\n";                  // PTR: null
    std::cout << format_range(v.data(), v.data() + v.size()) << "\n"; // RANGE: 1, 2, 3
    std::cout << format_range((int*)nullptr, (int*)nullptr) << "\n";  // RANGE: empty

    return 0;
}

/*
VALUE: 10 [x2 = 20]
VALUE: 3.14 [x1.5 = 4.71]
BOOL: yes (negated: no)
BOOL: no (negated: yes)
STRING: hello → [HELLO!]
STRING: hi → [HI!]
PTR: 42
PTR: null
RANGE: 1, 2, 3
RANGE: empty
*/