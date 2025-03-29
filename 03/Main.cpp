// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest zdefiniowanie klasy IntProcessor, przechowującej kolekcję liczb całkowitych
// oraz dynamicznie dodawane algorytmy ich przetwarzania.
//
// Algorytmy powinny być dodawane dynamicznie za pomocą metody addAlgorithm().
// Klasa powinna również posiadać możliwość aktywowania wbudowanych algorytmów metodą enableAlgorithm().
//
// Klasa powinna mieć przeładowane operatory:
// 1. operator+= dla dodawania liczb do kolekcji,
// 2. operator() dla wykonania wszystkich dodanych algorytmów na kolekcji.
//
// Dodatkowo proszę zaimplementować przeciążenie operatora << do wyświetlania zawartości kolekcji.
//
// Wymagania dodatkowe:
// - użycie std::function oraz std::bind,
// - przejrzystość kodu oraz zgodność z zasadą D.R.Y. (Don't Repeat Yourself).
//
// Dodatkowy challenge:
// - Dodaj metodę int computeTotal(), która zwraca sumę wszystkich liczb w kolekcji po wykonaniu algorytmów.
//
// Plik Main.cpp w przesłanym rozwiązaniu powinien być niezmodyfikowany.
//
// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek, ani żadnych innych materiałów.
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz właściciela nie ma praw dostępu.
// Rozwiązanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL jako archiwum tar.gz.
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab07/
// * archiwum nie powinno zawierać katalogu build/

#include "IntProcessor.h"
#include <iostream>
#include <functional>

int multiply(int val, int factor) { return val * factor; }
int increment(int val) { return val + 1; }

int main() {
    IntProcessor processor;

    processor += 1;
    processor += 2;
    processor += 3;

    processor.addAlgorithm(std::bind(multiply, std::placeholders::_1, 10));
    processor.addAlgorithm(increment);

    processor();

    std::cout << processor;
    std::cout << "Total: " << processor.computeTotal() << std::endl;

    processor.enableAlgorithm("decrement");
    processor();

    std::cout << processor;
    std::cout << "Total: " << processor.computeTotal() << std::endl;

    return 0;
}

/* Wynik działania:
Collection: 11 21 31
Total: 63
Enabling built-in algorithm: decrement
Collection: 10 20 30
Total: 60
*/