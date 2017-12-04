#pragma once
#include "Pasenger.h"
#include <string>
#include <iostream>

using namespace std;

class Car
{
	int id_;
	const int LIMIT = 3;
	Pasenger* driver_;
	Pasenger** pasengers_;
	int countPasenger_;
	string destiny_;
	double price_;
	bool state_; //full czy nie

	void calculatePrice();

public:
	static int count_;
	Car();
	Car(Pasenger* driver, string destiny, double price);
	Car(Car* car);
	~Car();

	void Write();
	void ClearPasenger();
	void Reservation(Pasenger* pasenger);
	void CancelReservation(Pasenger* pasenger);
	void ChangePrice(double newPrice);
};

