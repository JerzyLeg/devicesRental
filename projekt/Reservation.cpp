#include "Reservation.h"
#include "Device.h"
#include "User.h"
#include <iostream>
using namespace std;

Reservation::Reservation(User* user, Device* device, Date date, int duration)
{
	this->user = user;
	this->device = device;
	//this->data_str = date;
	this->date = Date(date);
	this->duration = duration;
	this->userID = user->getID();
	this->deviceID = device->getID();
	this->ID = generateID();
}

Reservation::Reservation(size_t userID, size_t deviceID, string date, int duration)
{
	this->userID = userID;
	this->deviceID = deviceID;
	//this->data_str = date;
	this->date = Date(date);
	this->duration = duration;
	this->ID = generateID();
}

Reservation::Reservation()
{
}

string Reservation::toCSV()
{
	return date.toString() + "," + to_string(duration) + "," + to_string(this->deviceID) + "," + to_string(this->userID);
}

string Reservation::toString()
{
	return "data: " + date.toString() + " ilosc dni: " + to_string(duration) + " urzadzenie: " + this->device->getName() + " uzytkownik: [" + this->user->toString() + "]" + " cena za wypozyczenie: " + to_string(this->getFullPrice());
}

void Reservation::setUser(User* user)
{
	this->user = user;
}

void Reservation::setDevice(Device* device)
{
	this->device = device;
}

float Reservation::getFullPrice()
{
	return device->calculatePrice() * this->duration;
}

size_t Reservation::generateID()
{
	auto tmp = std::hash<std::string>{}(this->toCSV());
	this->ID = tmp;
	cout <<"reservationID: " << tmp << endl;
	return tmp;
}

ofstream& operator<<(ofstream& of, Reservation& res)
{
	//of << res.device;
	return of;
}
