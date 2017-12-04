#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pasenger
{
	int id_;
	double price_;
	string name_;
	string sername_;

public:
	static int count_;
	Pasenger();
	Pasenger(string name, string sername);
	Pasenger(Pasenger& pas);
	~Pasenger();

	void write() const;
	void changeData(string name, string sername);
	void SetPrice(double price);
	int GetID();
};

