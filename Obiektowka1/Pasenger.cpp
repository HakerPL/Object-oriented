#include "Pasenger.h"

int Pasenger::count_ = 0;

Pasenger::Pasenger()
{
	cout << "Klasa Pasenger, konstruktor domyslny" << endl;
	name_ = "Jan";
	sername_ = "Kowalski";
	id_ = ++Pasenger::count_;
	price_ = 0;
}

Pasenger::Pasenger(string name, string sername)
{
	cout << "Klasa Pasenger, konstruktor z parametrami" << endl;
	name_ = name;
	sername_ = sername;
	id_ = ++Pasenger::count_;
	price_ = 0;
}

Pasenger::Pasenger(Pasenger& pas)
{
	cout << "Klasa Pasenger, konstruktor kopiujacy" << endl;
	name_ = pas.name_;
	sername_ = pas.sername_;
	price_ = pas.price_;
	id_ = ++Pasenger::count_;
}

Pasenger::~Pasenger()
{
	cout << "Klasa Pasenger, destruktor" << endl;
	--Pasenger::count_;
}

void Pasenger::write() const
{
	cout << "ID :" << id_ << " Imie :" << name_ << " Nazwisko :" << sername_ << " Cena :" << price_ << endl;
}

void Pasenger::changeData(string name, string sername)
{
	name_ = name;
	sername_ = sername;
}

void Pasenger::SetPrice(double price)
{
	price_ = price;
}

int Pasenger::GetID()
{
	return id_;
}
