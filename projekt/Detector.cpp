#include "Detector.h"
#include <iostream>

Detector::Detector(std::string name, string model, int channelsCount, int resolution, double price, int parameter2) : Device(name, model, channelsCount, resolution, price)
{
	this->parameter2 = parameter2;
}

string Detector::toString()
{
	return Device::toString() + "extra param: " + to_string(this->parameter2);
	//return " nazwa " + this->name + " model: " + this->model + " liczba kanalow: " + to_string(this->channelsCount) + " rozdzielczosc: " + to_string(this->resolution) + " cena: " + to_string(this->price) + "extra param: " + to_string(this->parameter2);
}

float Detector::calculatePrice()
{
	return this->price * 1.15;
}

ostream& operator<<(ostream& os, Detector* det)
{
	os << (Device*)det << "parametr2: " << det->parameter2;
	return os;
}
