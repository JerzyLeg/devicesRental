#include "Device.h"
#include <iostream>

Device::Device(std::string name, string model, int channelsCount, int resolution, double price)
{
	this->name = name;
	this->model = model;
	this->channelsCount = channelsCount;
	this->resolution = resolution;
	this->price = price;

	this->generateID();
}

size_t Device::getID()
{
	return this->ID;
}

string Device::getName()
{
	return this->name;
}

//Device::~Device()
//{
//}

ostream& operator<<(ostream& os, Device* dev)
{
	os << " nazwa: " << dev->name << " model: " << dev->model << " liczba kanalow: " << dev->channelsCount << " rozdzielczosc: " << dev->resolution << " cena: " << dev->price;
	return os;
}

string Device::toString()
{
	return " nazwa: " + this->name + " model: " + this->model + " liczba kanalow: " + to_string(this->channelsCount) + " rozdzielczosc: " + to_string(this->resolution) + " cena: " + to_string(this->price);
}

float Device::calculatePrice()
{
	return this->price * 1.0;
}

void Device::generateID()
{
	this->ID = std::hash<std::string>{}(this->toString());
	cout << "deviceID: " << this->ID << endl;
}
