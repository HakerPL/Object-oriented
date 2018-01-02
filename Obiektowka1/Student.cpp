#include "Student.h"


Student::Student()// : Osoba()
{
	std::cout << "Konstruktor Student()" << std::endl;
	Imie = "Jan";
	Nazwisko = "Kowalski";
	licznik_++;
	id_ = licznik_;

	Oceny = new int[3];

	UzupelnijOceny(rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1);
}

Student::Student(std::string imie, std::string nazwisko, int ocena1, int ocena2, int ocena3)// : Osoba(imie,nazwisko)
{
	std::cout << "Konstruktor Student(imie,nazwisko)" << std::endl;
	Imie = imie;
	Nazwisko = nazwisko;
	licznik_++;
	id_ = licznik_;

	Oceny = new int[3];
	UzupelnijOceny(ocena1, ocena2, ocena3);
}

Student::Student(Student * stu)// : Osoba()
{
	std::cout << "Konstruktor Student(stu)" << std::endl;
	Imie = stu->Imie;
	Nazwisko = stu->Nazwisko;
	licznik_++;
	id_ = licznik_;

	Oceny = new int[3];
	UzupelnijOceny(stu->Oceny[0], stu->Oceny[1], stu->Oceny[2]);
}

Student::~Student()
{
	std::cout << "Destruktor Student" << std::endl;
}

void Student::UzupelnijOceny(int pierwsza , int druga, int trzecia)
{
	Oceny[0] = pierwsza;
	Oceny[1] = druga;
	Oceny[2] = trzecia;
}

void Student::Wypisz()
{
	Osoba::Wypisz();
	std::cout << "OCENY:" << std::endl;

	for (int i = 0; i < 3; i++)
		std::cout << " Ocena " << i << " = " << Oceny[i];

	std::cout << std::endl;
}
