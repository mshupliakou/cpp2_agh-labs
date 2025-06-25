//documentation and comments are wrtitten in Polish
// ROZWIĄZANIE

#include <iostream>
// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu

//klasa absrakcyjna. nie da się utworzyć obiektu tej klasy. sproba powoduje bład kompilacji
class B{
    public:
    virtual std::ostream& printOn(std::ostream& os)const=0; // funkcja wirtualna
};

//overloading funkcji wirtualnej dla B
std::ostream& B::printOn(std::ostream& os)const{
	return os<<__PRETTY_FUNCTION__<<std::endl; // użycie __PRETTY_FUNCTION__ tak jak tego wymaga zadanie
    }

//D1 dziedziczy po B
class D1:public B{
    public:
    //overriding funkcji wirtualnej klasy bazowej
    std::ostream& printOn(std::ostream& os)const override{
	return os<<__PRETTY_FUNCTION__<<std::endl;}
};

//dziedziczy po D1
class D2: public D1{
    public:
    // nie ma własnej funkcji printOn. będzie korzystała z funkcji, którą posiada D1
};

//również dziedziczy po D1 ale robi ponwnie override funkcji printOn
class D3: public D1{
    public:
    std::ostream& printOn(std::ostream& os)const override{
    return os<<__PRETTY_FUNCTION__<<std::endl;
    }
};

//dziedziczy po D3
class D4: public D3{
    public:
    std::ostream& printOn(std::ostream& os)const override{
        B::printOn(os); // wyłowuje funkcje klas bazowych tak, aby output się zgadzał
        D1::printOn(os);
        D3::printOn(os);
        return os<<__PRETTY_FUNCTION__<<std::endl;
    }
};

//overloading operatora<< dla klasy bazowej B, co powoduje że każdy obiekt
// klas pochodnych może z tego operatora korzytać
std::ostream& operator<<(std::ostream& os, const B& b){
	return b.printOn(os);
}


int main(int argc, char *argv[]) {
   // B b; //odkomentowanie powoduje błąd kompilacji
  D1 d1; D2 d2; D3 d3; const D4 d4;
  std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}

/* Output:
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/




//ZADANIE:
// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu


// int main(int argc, char *argv[]) {
//    // B b; //odkomentowanie powoduje błąd kompilacji
//   D1 d1; D2 d2; D3 d3; const D4 d4;
//   std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
// }

/* Output:
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/