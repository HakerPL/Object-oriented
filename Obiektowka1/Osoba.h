#pragma once
#include <string>
#include <iostream>

class Osoba
{
public:
	static int licznik_;
	int id_;
	std::string Imie;
	std::string Nazwisko;

	//Osoba();
	//Osoba(std::string imie, std::string nazwisko);
	//Osoba(Osoba* oso);
	virtual ~Osoba();

	static void WypiszLicznik();

	virtual void Wypisz() = 0;

private:
	
};

