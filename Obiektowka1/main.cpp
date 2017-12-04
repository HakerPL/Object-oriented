#include "Car.h"
#include "Pasenger.h"
#include "Ulamek.h"
#include <stddef.h>

using namespace std;

void OperationOnClass();
void OperationFriend();
void wypisz(Ulamek* ulam);
ostream & operator<<(ostream & wyjscie, Ulamek* ulamek);

int main()
{
	OperationOnClass();
	system("PAUSE");
	return 0;
}

#pragma region Friend Operation 
void OperationFriend()
{
	Ulamek* u1 = new Ulamek(-1, 3);
	Ulamek* u2 = new Ulamek(3, 5);

	cout << endl << "Ulakem u1:";
	wypisz(u1);
	cout << endl << "Ulakem u2:";
	wypisz(u2);

	cout << endl << "Dodawanie u1 i u2:";
	Ulamek u3 = *u1 + *u2;
	wypisz(&u3);
	cout << endl << "Odejmowanie u1 i u2:";
	u3 = *u1 - *u2;
	wypisz(&u3);
	cout << endl << "Mnozenie u1 i u2:";
	u3 = *u1 * *u2;
	wypisz(&u3);
	cout << endl << "Dzielenie u1 i u2:";
	u3 = *u1 / *u2;
	wypisz(&u3);
}

void wypisz(Ulamek* ulam)
{
	cout << endl << "Licznik: " << ulam->licznik_ << " Mianownik: " << ulam->mianownik_ << " Dziesietnie: " << ulam->dziesietnie() << endl;
}

ostream & operator<<(ostream & wyjscie, Ulamek* ulamek)
{
	wyjscie << " Licznik: " << ulamek->licznik_ << " Mianownik: " << ulamek->mianownik_;
	return wyjscie;
}
#pragma endregion

#pragma region Class Operation 
void ClassOperation()
{
	OperationOnClass();
	cout << endl << "Pasenger count: " << Pasenger::count_ << " Car count: " << Car::count_ << endl << endl;
}

void OperationOnClass()
{
	Pasenger* p1 = new Pasenger();
	Pasenger* p2 = new Pasenger("Alibaba", "Bel");
	Pasenger* p3 = new Pasenger(*p2);
	Pasenger* p4 = new Pasenger("Kaska", "Opal");

	p1->changeData("Wojtek", "As");

	p1->write();
	p2->write();
	p3->write();

	Pasenger* tab[2];
	tab[0] = new Pasenger("Adam", "Dal");
	tab[1] = new Pasenger("Anna", "Col");

	for (Pasenger* element : tab)
		element->write();

	cout << endl;

	delete tab[0];
	delete tab[1];

	tab[0] = nullptr;
	tab[1] = nullptr;

	Car car(p1, "Opole", 500);
	car.Reservation(p2);
	car.Reservation(p3);
	car.Reservation(p4);

	cout << endl;
	car.Write();
	cout << endl;

	car.CancelReservation(p3);
	car.CancelReservation(p2);
	cout << endl;

	car.Write();
	cout << endl;

	Pasenger* p5 = new Pasenger("Ola", "Mon");
	Pasenger* p6 = new Pasenger("Walery", "Ton");

	car.Reservation(p5);
	car.Reservation(p6);
	car.Write();
	cout << endl;

	car.ChangePrice(200);
	car.Write();
	cout << endl;

	car.CancelReservation(p5);
	car.CancelReservation(p6);

	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
}
#pragma endregion