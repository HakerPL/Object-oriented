#include "Car.h"

int Car::count_ = 0;

void Car::calculatePrice()
{
	double pricePerPasenger = price_ / (countPasenger_ + 1);

	driver_->SetPrice(pricePerPasenger);

	for (int i = 0; i < countPasenger_; i++)
		pasengers_[i]->SetPrice(pricePerPasenger);
}

Car::Car()
{
	cout << "Klasa Car, konstruktor domyslny" << endl;
	id_ = ++Car::count_;
	driver_ = new Pasenger("Kierowca","brak");
	pasengers_ = new Pasenger*[LIMIT];
	countPasenger_ = 0;
	destiny_ = "Warszawa";
	price_ = 400;
	state_ = false;

	ClearPasenger();
}

Car::Car(Pasenger * driver, string destiny, double price)
{
	cout << "Klasa Car, konstruktor z parametrami" << endl;
	id_ = ++Car::count_;
	driver_ = driver;
	pasengers_ = new Pasenger*[LIMIT];
	countPasenger_ = 0;
	destiny_ = destiny;
	price_ = price;
	state_ = false;

	ClearPasenger();
}

Car::Car(Car * car)
{
	cout << "Klasa Car, konstruktor kopiujacy" << endl;
	id_ = ++Car::count_;
	driver_ = car->driver_;
	pasengers_ = car->pasengers_;
	countPasenger_ = car->countPasenger_;
	destiny_ = car->destiny_;
	price_ = car->price_;
	state_ = car->state_;
}

Car::~Car()
{
	cout << "Klasa Car, destruktor" << endl;
	--Car::count_;

	delete driver_;
}

void Car::Write()
{
	cout << "ID samochodu: " << id_ << endl;
	cout << "Cel: " << destiny_ << " Cena: " << price_ << endl;
	cout << "Kierowca: " << endl;
	driver_->write();
	cout << "Pasazerowie: " << endl;

	for (int i = 0; i < countPasenger_; i++)
		pasengers_[i]->write();
}

void Car::ClearPasenger()
{
	for (int i = 0; i < LIMIT; i++)
		pasengers_[i] = nullptr;
}

void Car::Reservation(Pasenger * pasenger)
{
	if(state_)
	{
		cout << "Samochod pelny. Nie mozna zarezerwowac" << endl;
		return;
	}

	pasengers_[countPasenger_] = pasenger;

	countPasenger_++;
	if (countPasenger_ == this->LIMIT)
		state_ = true;

	calculatePrice();
}

void Car::CancelReservation(Pasenger * pasenger)
{
	pasenger->SetPrice(0);

	for (int i = 0; i < countPasenger_; i++)
	{
		if(pasengers_[i]->GetID() == pasenger->GetID())
		{
			pasengers_[i] = nullptr;
			break;
		}
	}

	countPasenger_--;
	state_ = false;

	for (int i = 0; i < LIMIT ; i++)
	{
		if (i + 1 >= LIMIT)
			break;

		if(pasengers_[i + 1] == nullptr)
			continue;

		pasengers_[i] = pasengers_[i + 1];
		pasengers_[i + 1] = nullptr;
	}

	calculatePrice();
}

void Car::ChangePrice(double newPrice)
{
	price_ = newPrice;
	calculatePrice();
}
