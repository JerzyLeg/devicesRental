#include "CurveTracer.h"
#include <iostream>
#include "Device.h"

CurveTracer::CurveTracer(std::string name, string model, int channelsCount, int resolution, double price, int parameter1) : Device(name, model, channelsCount, resolution, price)
{
	this->parameter1 = parameter1;
}

string CurveTracer::toString()
{
	return Device::toString() + "extra param: " + to_string(this->parameter1);
	//return " nazwa: " + this->name + " model: " + this->model + " liczba kanalow: " + to_string(this->channelsCount) + " rozdzielczosc: " + to_string(this->resolution) + " cena: " + to_string(this->price) + "extra param: " + to_string(this->parameter1);
}

float CurveTracer::calculatePrice()
{
	return this->price * 1.1;
}

ostream& operator<<(ostream& os, CurveTracer* cur)
{
	os << static_cast<Device*>(cur) << "parametr1: " << cur->parameter1;
	return os;
}
