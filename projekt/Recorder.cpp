#include "Recorder.h"
#include <iostream>

Recorder::Recorder(std::string name, string model, int channelsCount, int resolution, double price, int parameter4) : Device(name, model, channelsCount, resolution, price) 
{
	this->parameter4 = parameter4;
}

string Recorder::toString()
{
	return Device::toString() + "extra param: " + to_string(this->parameter4);
	//return " nazwa " + this->name + " model: " + this->model + " liczba kanalow: " + to_string(this->channelsCount) + " rozdzielczosc: " + to_string(this->resolution) + " cena: " + to_string(this->price) + "extra param: " + to_string(this->parameter4);
}

float Recorder::calculatePrice()
{
	return this->price * 1.12;
}

ostream& operator<<(ostream& os, Recorder* rec)
{
	os << (Device*)rec << "parametr4: " << rec->parameter4;
	return os;
}
