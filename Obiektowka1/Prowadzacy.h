#pragma once
#include "Osoba.h"
class Prowadzacy :
	public Osoba
{
public:
	std::string Przedmiot;
	std::string Konsultacje;

	Prowadzacy();
	Prowadzacy(std::string imie, std::string nazwisko, std::string przedmiot, std::string konsultacje);
	Prowadzacy(Prowadzacy* pro);
	~Prowadzacy();

	void Wypisz() override;
};

