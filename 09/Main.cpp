// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Celem zadania jest zbudowanie "systemu plików" z klasą bazową FSItem,
// po której dziedziczą różne typy elementów. Celem dodatkowym jest zrozumienie
// problemu diamentu w dziedziczeniu wielokrotnym i jego rozwiązania poprzez dziedziczenie wirtualne.

// Utwórz klasę bazową FSItem z metodami wirtualnymi getName() i printInfo().
// Następnie zdefiniuj klasę File reprezentującą zwykły plik, która dziedziczy po FSItem.

// Zdefiniuj interfejs Executable (czysto wirtualna klasa), również dziedziczącą po FSItem.
// Interfejs powinien zawierać metodę execute().

// Zbuduj klasę ScriptFile, która dziedziczy zarówno po File, jak i Executable.
// W tej klasie zaimplementuj metodę execute() tak, aby wypisywała komunikat o uruchomieniu skryptu.

// Na koniec zaimplementuj funkcję tryExecute(FSItem* item), która:
// - używa dynamic_cast do sprawdzenia, czy item można rzutować na Executable*,
// - jeśli tak – wywołuje execute(),
// - jeśli nie – wypisuje, że element nie jest wykonywalny.


// Dodatkowe wymagania:
//  - Pliku Main.cpp nie wolno modyfikowac. (Nie licząc instancji wyboru kodu bazującego na zeszłotygodniowym kodzie lub pisania od zera)
//  - Kody źródłowe muszą znajdować się w katalogu, do którego nikt oprócz właściciela nie ma praw dostępu.
//  - Rozwiązanie (czyli dodane pliki oraz Main.cpp) należy wgrać do UPEL jako archiwum tar.gz.
//    UWAGA: archiwum powinno zawierać katalog z zadaniem, np. lab03/, a nie katalog build/.
//  - Kod powinien być przyjazny dla programisty, czytelny i zgodny z zasadą DRY.
//  - Podczas wykonywania zadania nie wolno korzystać z internetu, notatek ani żadnych innych materiałów.



#include <iostream>
#include "File.h"
#include "ScriptFile.h"
#include "FSItem.h"
#include <vector>
#include <memory>

void tryExecute(FSItem* item) {
    ScriptFile *s = dynamic_cast<ScriptFile*>(item);
    if(s==NULL){
        std::cout<<"Element "<<item->getName()<<" nie jest wykonywalny."<<std::endl;
    }
    else{
        s->execute();
    }
}
int main() {
    // Jeżeli piszemy od zera:
    std::vector<std::unique_ptr<FSItem>> items;
    items.emplace_back(std::make_unique<File>("README.txt"));
    items.emplace_back(std::make_unique<ScriptFile>("install.sh"));
    items.emplace_back(std::make_unique<File>("notes.md"));
    items.emplace_back(std::make_unique<ScriptFile>("run_all.sh"));

    std::cout << "== Próba wykonania wszystkich elementów ==\n";
    for (const auto& item : items) {
        tryExecute(item.get());
    }

    return 0;
}

/* Oczekiwany output:
== Próba wykonania wszystkich elementów ==
Element 'README.txt' nie jest wykonywalny.
Uruchamianie skryptu: install.sh
Element 'notes.md' nie jest wykonywalny.
Uruchamianie skryptu: run_all.sh
*/
