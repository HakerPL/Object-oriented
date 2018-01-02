#include "Osoba.h"

int Osoba::licznik_ = 0;

//Osoba::Osoba()
//{
//	std::cout << "Konstruktor Osoba()" << std::endl;
//	Imie = "Jan";
//	Nazwisko = "Kowalski";
//	licznik_++;
//	id_ = licznik_;
//}
//
//Osoba::Osoba(std::string imie, std::string nazwisko)
//{
//	std::cout << "Konstruktor Osoba(imie,nazwisko)" << std::endl;
//	Imie = imie;
//	Nazwisko = nazwisko;
//	licznik_++;
//	id_ = licznik_;
//}
//
//Osoba::Osoba(Osoba * oso)
//{
//	std::cout << "Konstruktor Osoba(oso)" << std::endl;
//	Imie = oso->Imie;
//	Nazwisko = oso->Nazwisko;
//	licznik_++;
//	id_ = licznik_;
//}

Osoba::~Osoba()
{
	std::cout << "Destruktor Osoba" << std::endl;
	licznik_--;
}

void Osoba::WypiszLicznik()
{
	std::cout << "Licznik = " << licznik_ << std::endl;
}

void Osoba::Wypisz()
{
	std::cout << "ID = " << id_ << " Licznik = " << licznik_ << " Imie = " 
			  << Imie << " Nazwisko = " << Nazwisko << std::endl;
}
