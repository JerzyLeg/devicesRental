// wypozyczalnia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "FileManager.h"
#include "Date.h"
#include "Reservation.h"
#include "User.h"
#include "ReservationManager.h"
#include "CLineHelper.h"

using namespace std;

int main()
{
	ReservationManager reservationManager;
	FileManager::loadDevices(reservationManager);
	FileManager::loadUsers(reservationManager);
	FileManager::loadReservations(reservationManager);
	reservationManager.init();

	while (true)
	{
		cout << "0 - dodaj rezerwacje" << endl;
		cout << "1 - anuluj rezerwacje" << endl;
		cout << "2 - zapisz do pliku wszystkie rezerwacje danego uzytkownika" << endl;
		cout << "3 - zapisz do pliku wszystkie rezerwacje na dane urzadzenie" << endl;
		cout << "4 - zapisz i zakoncz program" << endl;

		string choiceStr;
		int choice;
		cout << "Co chcesz zrobic? Podaj numer Twojego wyboru." << endl;
		cin >> choiceStr;
		try {
			choice = stoi(choiceStr);
		}
		catch (exception e)
		{
			cout << "indeks wyboru jest liczba calkowita" << endl;
			continue;
		}

		if (choice > 4 || choice < 0)
		{
			cout << "podaj indeks wyboru z zakresu 0-4" << endl;
			continue;
		}

		if (choice == 0) {
			string usernameTmp;
			string emailTmp;;
			cout << "username: ";
			cin >> usernameTmp;
			cout << "email: ";
			cin >> emailTmp;
			auto user = new User(usernameTmp, emailTmp);
			user = reservationManager.addUser(user);
			auto device = CLineHelper::chooseDevice(reservationManager);
			auto date = CLineHelper::pickDate();
			auto duration = CLineHelper::pickDuration();
			auto reservation = Reservation(user, device, date, duration);
			reservationManager.reserve(reservation);
			cout << "urzadzenie zostalo zarezerwowane" << endl;
		}

		if (choice == 1) {
			auto rezerwacja = CLineHelper::chooseReservation(reservationManager);
			reservationManager.cancel(rezerwacja);
			cout << "rezerwacja zostala anulowana" << endl;
		}

		if (choice == 2) {
			auto user = CLineHelper::chooseUser(reservationManager);
			reservationManager.saveReservationsForUser(user);
			cout << "zapisano!" << endl;
		}

		if (choice == 3) {
			auto device = CLineHelper::chooseDevice(reservationManager);
			reservationManager.saveReservationsForDevice(device);
			cout << "zapisano!" << endl;
		}

		if (choice == 4) {
			FileManager::saveReservations(reservationManager);
			FileManager::saveUsers(reservationManager);

			break;
		}
	}

	return 0;
}
