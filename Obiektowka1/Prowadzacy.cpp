#include "Prowadzacy.h"

Prowadzacy::Prowadzacy()// : Osoba()
{
	std::cout << "Konstruktor Prowadzacy()" << std::endl;
	Imie = "Jan";
	Nazwisko = "Kowalski";
	licznik_++;
	id_ = licznik_;
}

Prowadzacy::Prowadzacy(std::string imie, std::string nazwisko, std::string przedmiot, std::string konsultacje)// : Osoba(imie,nazwisko)
{
	std::cout << "Konstruktor Prowadzacy(imie,nazwisko,przedmiot,konsultacje)" << std::endl;
	Imie = imie;
	Nazwisko = nazwisko;
	licznik_++;
	id_ = licznik_;
	Przedmiot = przedmiot;
	Konsultacje = konsultacje;
}

Prowadzacy::Prowadzacy(Prowadzacy * pro)// : Osoba()
{
	std::cout << "Konstruktor Prowadzacy(pro)" << std::endl;
	Imie = pro->Imie;
	Nazwisko = pro->Nazwisko;
	Przedmiot = pro->Przedmiot;
	Konsultacje = pro->Konsultacje;
	licznik_++;
	id_ = licznik_;
}

Prowadzacy::~Prowadzacy()
{
	std::cout << "Destruktor Prowadzacy" << std::endl;
}

void Prowadzacy::Wypisz()
{
	Osoba::Wypisz();
	std::cout << "Przedmiot = " << Przedmiot << " Konsultacje = " << Konsultacje << std::endl;
}
