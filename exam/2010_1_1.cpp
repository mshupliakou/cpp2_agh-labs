//documentation and comments are wrtitten in Polish
//2021 rok 2 termin 2 zadanie:

// ROZWIĄZANIE

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std; //chcemu korzystac z napespace std

struct A {
    int counter = -1;
    void operator()(int& value){
        value = counter;
        counter--;
    }
};

int main() {
    list<int> coll(11);
    for_each(coll.begin(), coll.end(), A());
    copy( coll.begin(), coll.end(), ostream_iterator<int>(cout, "; "));
    return 0;
}

// //to ma się wyświetlić:
// // -1; -2; -3; -4; -5; -6; -7; -8; -9; -10; -11;


//ZADANIE

// // uzupełnij 1

// struct A {
//  // uzupełnij 2
// };

// int main() {
//     list<int> coll(11);
//     for_each( /*uzupełnij 3*/ );
//     copy( /*uzupełnij 4*/ );
//     return 0;
// }
// //to ma się wyświetlić:
// // -1; -2; -3; -4; -5; -6; -7; -8; -9; -10; -11;