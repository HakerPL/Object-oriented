#pragma once
#include <utility>
#include <iostream>

using namespace std;

class Ulamek
{
	int licznik_;
	int mianownik_;

	double dziesietnie();
	void skroc();

public:
	Ulamek();
	Ulamek(int licznik, int mianownik);
	Ulamek(Ulamek* ulam);
	~Ulamek();

	friend void wypisz(Ulamek* ulam);
	friend ostream & operator<<(ostream & wyjscie, Ulamek* ulamek);
	Ulamek& operator + (Ulamek& ulam);
	Ulamek& operator - (Ulamek& ulam); 
	Ulamek& operator * (Ulamek& ulam);
	Ulamek& operator / (Ulamek& ulam);
};

