// Celem dzisiejszego zadania jest rozwinięcie poprzedniego ćwiczenia dotyczącego systemu zarządzania zwierzętami w zoo.

// Nowe wymagania i elementy do przećwiczenia:

// - Klasa bazowa `Animal` powinna być czysto abstrakcyjna (pure virtual).  
// - Wprowadzenie dodatkowej klasy pochodnej (nie można po niej dziedziczyć) –  `Elephant`.
// - Klasa `Zoo` powinna mieć metodę pozwalającą na wyjęcie zwierzęcia z zoo (operacja przenosząca własność – move semantics).
// - Dodanie klasy `ZooKeeper` (opiekun zwierząt), która zarządza pojedynczym zwierzęciem (użycie `std::unique_ptr` oraz  move semantics).
// - Wszystkie klasy powinny poprawnie obsługiwać kopiowanie i przenoszenie (O ile jest to sensowne).
// - Zachowanie zasad dobrego OOP oraz DRY (Don't Repeat Yourself).

// Ważne:

// - Dokumentacja - 1 pkt.  
// - Poprawna kompilacja (bez ostrzeżeń) - 2 pkt.  
// - Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci) - 3 pkt.  
// - Ocena kodu (projekt, zgodność z OOP, przejrzystość, implementacja) - maks. 4 pkt.
// - Nie można korzystać z internetu, AI, ani innych osób.
// - Pliku Main.cpp nie wolno modyfikować.
// 


#include "Zoo.h"
#include "ZooKeeper.h"
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Elephant.h"
#include <memory>

int main() {
    std::cout << "--- Original Zoo ---\n";

    Zoo cityZoo;
    cityZoo.addAnimal(std::make_unique<Lion>("Mufasa"));
    cityZoo.addAnimal(std::make_unique<Monkey>("Jack"));
    cityZoo.addAnimal(std::make_unique<Elephant>("Dumbo"));

    cityZoo.makeAllSounds();

    std::cout << "\n--- ZooKeeper Taking Animal ---\n";
    ZooKeeper keeper;
    keeper.takeAnimal(cityZoo.releaseAnimal(1)); 
    keeper.makeAnimalSound();

    std::cout << "\n--- Zoo after Animal Taken ---\n";
    cityZoo.makeAllSounds();

    std::cout << "\n--- Copying Zoo ---\n";
    Zoo copiedZoo = cityZoo;
    copiedZoo.addAnimal(std::make_unique<Lion>("Scar"));
    copiedZoo.makeAllSounds();

    std::cout << "\n--- Moving Zoo ---\n";
    Zoo movedZoo = std::move(cityZoo);
    movedZoo.makeAllSounds();

    std::cout << "\n--- Zoo after Move ---\n";
    cityZoo.makeAllSounds(); 

    return 0;
}

/* Oczekiwany wynik programu:

--- Original Zoo ---
Lion Mufasa roars: ROOAAAR!
Monkey Jack says: Ooh-ooh-aah-aah!
Elephant Dumbo trumpets: PAAAAWOOO!

--- ZooKeeper Taking Animal ---
ZooKeeper is now taking care of: Monkey Jack
Monkey Jack says: Ooh-ooh-aah-aah!

--- Zoo after Animal Taken ---
Lion Mufasa roars: ROOAAAR!
Elephant Dumbo trumpets: PAAAAWOOO!

--- Copying Zoo ---
Lion Mufasa roars: ROOAAAR!
Elephant Dumbo trumpets: PAAAAWOOO!
Lion Scar roars: ROOAAAR!

--- Moving Zoo ---
Lion Mufasa roars: ROOAAAR!
Elephant Dumbo trumpets: PAAAAWOOO!

--- Zoo after Move ---
Zoo is empty, no animals to make sounds!

Zoo destroyed.
Zoo destroyed.
Zoo destroyed.
ZooKeeper destroyed.*/