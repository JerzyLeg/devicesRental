#include "Gauge.h"
#include <iostream>

Gauge::Gauge(std::string name, string model, int channelsCount, int resolution, double price, int parameter3) : Device(name, model, channelsCount, resolution, price)
{
	this->parameter3 = parameter3;
}

Gauge::~Gauge()
{
}

string Gauge::toString()
{	
	return Device::toString() + "extra param: " + to_string(this->parameter3);
	//return " nazwa " + this->name + " model: " + this->model + " liczba kanalow: " + to_string(this->channelsCount) + " rozdzielczosc: " + to_string(this->resolution) + " cena: " + to_string(this->price) + "extra param: " + to_string(this->parameter3);
}

float Gauge::calculatePrice()
{
	return this->price * 1.05;
}


ostream& operator<<(ostream& os, Gauge *gau)
{
	os << (Device*)gau << "parametr4: " << gau->parameter3;
	return os;
}
