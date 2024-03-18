#include "ReservationManager.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool ReservationManager::reserve(Reservation& reservation)
{
	reservations.push_back(reservation);
	return true;
}

void ReservationManager::cancel(Reservation& reservation)
{
	int licznik{ 0 };
	for (auto& res : this->reservations)
	{
		if (res.ID == reservation.ID)
		{
			this->reservations.erase(reservations.begin() + licznik);
		}
		licznik++;
	}
}

void ReservationManager::saveReservationsForUser(User* user)
{
	/*string nazwa = user->username;*/
	ofstream plik;
	plik.open("rezerwacjeDlaUzytkownika" + user->username() +".csv");
	for (auto& res : this->reservations)
	{
		if (res.userID == user->getID())
		{
			if (plik.is_open())
			{
				plik << res.toString() << endl;
			}
		}
	}
}

void ReservationManager::saveReservationsForDevice(Device* device)
{
	ofstream plik;
	plik.open("rezerwacjeDlaUrzadzenia" + device->getName() + ".csv");
	for (auto& res : this->reservations)
	{
		if (res.deviceID == device->getID())
		{
			plik << res.toString() << endl;
		}
	}
}

vector<Reservation>& ReservationManager::getReservations()
{
	return this->reservations;
}

vector<Device*>& ReservationManager::getDevices()
{
	return this->devices;
}

vector<User*>& ReservationManager::getUsers()
{
	return this->users;
}

void ReservationManager::listUsers()
{
	int licznik{ 0 };
	for (auto& user : this->users)
	{
		cout << "numer uzytkownika: " << licznik;
		cout << user->toString() << endl;
		licznik++;
	}
}

User* ReservationManager::addUser(User* user)
{
	for (auto& element : this->users)
	{
		if (element->getID() == user->getID())
		{
			delete user;
			return element;
		}
	}

	this->users.push_back(user);
	return user;
}

void ReservationManager::listDevices()
{
	int licznik = 0;
	for (auto& element : this->devices)
	{
		cout << "numer urzadzenia: " << licznik;
		cout << element->toString() << endl;
		licznik++;
	}
}

void ReservationManager::init()
{
	for (auto& rezerwacja : this->reservations)
	{
		for (auto& user : this->users)
		{
			if (rezerwacja.userID == user->getID())
			{
				rezerwacja.setUser(user);
			}

		}
		for (auto& device : this->devices)
		{
			if (rezerwacja.deviceID == device->getID())
			{
				rezerwacja.setDevice(device);
			}
		}
	}
}
