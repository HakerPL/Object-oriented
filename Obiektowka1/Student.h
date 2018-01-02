#pragma once
#include "Osoba.h"
#include <cstdlib>
#include <ctime>

class Student :
	public Osoba
{
public:

	int* Oceny;

	Student();
	Student(std::string imie, std::string nazwisko, int ocena1, int ocena2, int ocena3);
	Student(Student* stu);
	~Student();

	void UzupelnijOceny(int pierwsza, int druga, int trzecia);
	void Wypisz() override;
};

