// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest rozszerzenie kodu źródłowego projektu zarządzania drużynami Pokémonów,
// gdzie dane powinny być przechowywane w listach dwukierunkowych, bez użycia kontenerów STL
// takich jak `std::vector` czy `std::list`.
//
// Założenia do ogólnej struktury projektu:
// - PokemonNode powinien być zdefiniowany w tym samym pliku co klasa Pokemon
// - TeamNode powinien być zdefiniowany w tym samym pliku co klasa Team
// 
// Zadaniem w ramach tych laboratotów są tematy:
// - niejawna konwersja typów
// - przeciążanie operatorów, operator przypisania kopiującego
// - niestandardowy konstruktor kopiujący 
// UWAGA: co potrzebne proszę wywnioskować z treści funkcji main
//
// Jeśli wystarczy czasu, proszę przeanalizować ostatnią cześć
// dotyczącą różnicy między `std::is_trivially_default_constructible` a `std::is_default_constructible`
//
// Prosze zadbać o dobre zarzadzanie pamiecia.
// Plik Main.cpp w przesłanym rozwiązaniu powinien być niezmodyfikowany.
// Struktura programu powinna być oparta o definicję zawartą w pliku CMakeLists.txt
//
// Ostateczny program powinien byc przyjazny dla programisty (czytelny i dobrze napisany),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materiałów.
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp)
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab06/
// * archiwum nie powinno zawierać katalogu build/

#include "Trainer.h"
#include "Team.h"
#include "Pokemon.h"
#include <type_traits>
#include <iostream>

class Region {};

class KantoRegion {
public:
    KantoRegion(){} // Brak domyślnego konstruktora?
};

class JohtoRegion {
public:
    JohtoRegion(int badgeCount) {} // Brak domyślnego konstruktora
};

int main() {
    Trainer ash("Ash Ketchum");

    ash.addTeam("Hoenn Team"); // Uwaga: skorzystać z niejawnej konwersji
    ash.addTeam("Sinnoh Team");
    ash.addTeam("Unova Team");

    Team& hoenn = ash["Hoenn Team"];
    const Team& unova = ash["Unova Team"];

    Pokemon p1("Treecko", "Grass");
    Pokemon p2("Torchic", "Fire");

    hoenn.addPokemon(p1);
    hoenn.addPokemon(p2);

    std::cout << ash << std::endl; // wypisuje drużyny Ash'a

    ash.printEmptyTeams(); // Wypisuje drużyny bez Pokémonów

    p1.printInfo();
    Pokemon p3 = hoenn[0]; // UWAGA: p3 NIE należy do drużyny "Hoenn Team"
    p3.printInfo();

    auto printMsgDefaultConstructible = [](const std::string& className, bool isDefaultConstr) {
        std::cout << "Is " << className << " default constructible? " 
        << std::boolalpha << isDefaultConstr << std::endl;
    };

    printMsgDefaultConstructible("Region", std::is_trivially_default_constructible<Region>::value);
    printMsgDefaultConstructible("JohtoRegion", std::is_trivially_default_constructible<JohtoRegion>::value);
    printMsgDefaultConstructible("KantoRegion", std::is_trivially_default_constructible<KantoRegion>::value);
    printMsgDefaultConstructible("KantoRegion", std::is_default_constructible<KantoRegion>::value); // jaka jest różnica?

    return 0;
}

/* wynik działania:
Trainer: Ash Ketchum teams: Hoenn Team, Sinnoh Team, Unova Team,
Trainer: Ash Ketchum teams (empty): Sinnoh Team, Unova Team,
Pokemon: Treecko (Type: Grass)
Pokemon: Treecko (Type: Grass)
Is Region default constructible? true
Is JohtoRegion default constructible? false
Is KantoRegion default constructible? false
Is KantoRegion default constructible? true
*/
