#include "Ulamek.h"


double Ulamek::dziesietnie()
{
	return static_cast<double>(licznik_) / static_cast<double>(mianownik_);
}

void Ulamek::skroc()
{
	int a, b, c = 0;

	if(licznik_ < mianownik_)
	{
		a = mianownik_;
		b = licznik_;
	}
	else
	{
		a = licznik_;
		b = mianownik_;
	}

	do
	{
		c = a%b;
		a = b;
		b = c;
	} while (c != 0);


	if (a <= 1)
		return;

	licznik_ /= a;
	mianownik_ /= a;
}

Ulamek::Ulamek()
{
	licznik_ = 1;
	mianownik_ = 3;
}

Ulamek::Ulamek(int licznik, int mianownik)
{
	licznik_ = licznik;
	mianownik_ = mianownik;
}

Ulamek::Ulamek(Ulamek * ulam)
{
	licznik_ = ulam->licznik_;
	mianownik_ = ulam->mianownik_;
}

Ulamek::~Ulamek(){}

Ulamek & Ulamek::operator+(Ulamek & ulam)
{
	int licznikA = licznik_ * ulam.mianownik_;
	int licznikB = ulam.licznik_ * mianownik_;
	int mianownik = ulam.mianownik_ * mianownik_;

	Ulamek* newUlam = new Ulamek(licznikA + licznikB, mianownik);
	newUlam->skroc();
	return *newUlam;
}

Ulamek & Ulamek::operator-(Ulamek & ulam)
{
	int licznikA = licznik_ * ulam.mianownik_;
	int licznikB = ulam.licznik_ * mianownik_;
	int mianownik = ulam.mianownik_ * mianownik_;

	Ulamek* newUlam = new Ulamek(licznikA - licznikB, mianownik);
	newUlam->skroc();
	return *newUlam;
}

Ulamek & Ulamek::operator*(Ulamek & ulam)
{
	int licznik = licznik_ * ulam.licznik_;
	int mianownik = mianownik_ * ulam.mianownik_;

	Ulamek* newUlam = new Ulamek(licznik, mianownik);
	newUlam->skroc();
	return *newUlam;
}

Ulamek & Ulamek::operator/(Ulamek & ulam)
{
	int licznik = licznik_ * ulam.mianownik_;
	int mianownik = mianownik_ * ulam.licznik_;

	Ulamek* newUlam = new Ulamek(licznik, mianownik);
	newUlam->skroc();
	return *newUlam;
}
