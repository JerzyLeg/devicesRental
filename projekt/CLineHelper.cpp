#include "CLineHelper.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
Reservation CLineHelper::chooseReservation(ReservationManager& rm)
{
	int licznik{ 0 };
	for (auto& res : rm.getReservations())
	{
		cout << "numer rezerwacji: " << licznik << " " << res.toString() << endl;
		licznik++;
	}
	cout << "wybierz numer rezerwacji, ktora chcesz anulowac" << endl;
	string indeksStr;
	int indeks;
	while (true)
	{
		//getline(cin, indeksStr);
		cin >> indeksStr;
		try {
			indeks = stoi(indeksStr);
		}
		catch (exception e) {
			cout << "podaj poprawny typ[czyli numer] rezerwacji" << endl;
			continue;
		}
		if (rm.getReservations().size() <= indeks || indeks < 0) {
			cout << "podaj poprawny numer rezerwacji" << endl;
			continue;
		}

		cout << "wybrana rezerwacja: " << rm.getReservations()[indeks].toCSV();
		return rm.getReservations()[indeks];
	}
}

User* CLineHelper::chooseUser(ReservationManager& rm)
{
	int licznik{ 0 };
	for (auto& user : rm.getUsers())
	{
		cout << "numer uzytkownika: " << licznik << " " << user->toString() << endl;
		licznik++;
	}
	cout << "wybierz numer uzytkownika " << endl;
	string indeksStr;
	int indeks;
	while (true)
	{
		cin >> indeksStr;
		try {
			indeks = stoi(indeksStr);
		}
		catch (exception e)
		{
			cout << "podaj numer [czyli liczbe] uzytkownika " << endl;
			continue;
		}
		if (rm.getUsers().size() <= indeks || indeks < 0)
		{
			cout << "podaj poprawny numer " << endl;
			continue;
		}
		cout << "wybrany uzytkownik: " << rm.getUsers()[indeks]->toString() << endl;
		return rm.getUsers()[indeks];
	}
}

Device* CLineHelper::chooseDevice(ReservationManager& rm)
{
	int licznik{ 0 };
	for (auto& device : rm.getDevices())
	{
		cout << "numer urzadzenia: " << licznik << " " << device->toString() << endl;
		licznik++;
	}
	cout << "wybierz numer urzadzenia " << endl;
	string indeksStr;
	int indeks;
	while (true)
	{
		cin >> indeksStr;
		try {
			indeks = stoi(indeksStr);
		}
		catch (exception e)
		{
			cout << "podaj numer [czyli liczbe] urzadzenia " << endl;
			continue;
		}
		if (rm.getDevices().size() <= indeks || indeks < 0)
		{
			cout << "podaj poprawny numer " << endl;
			continue;
		}
		cout << "wybrane urzadzenie: " << rm.getDevices()[indeks]->toString() << endl;
		return rm.getDevices()[indeks];
	}
}

Date CLineHelper::pickDate()
{
	string line;

	while (true) {
		cout << "Od kiedy chcesz wypozyczyc urzadzenie? (dd/mm/yyyy)" << endl;
		cin >> line;
		if (line.length() != 10) {
			cout << "nieprawidlowy format daty (za malo/duzo znakow)" << endl;
			continue;
		}

		vector<string> lines;
		istringstream ss(line);
		while (getline(ss, line, '/')) {
			lines.push_back(line);
		}

		if (lines.size() != 3) {
			cout << "nieprawid³owy format daty (za malo/duzo '/')" << endl;
			continue;
		}

		Date date;
		try {
			date.day = stoi(lines[0]);
			date.month = stoi(lines[1]);
			date.year = stoi(lines[2]);
		}
		catch (exception e) {
			cout << "nieprawid³owy format daty (blad parsowania )" << endl;
			continue;
		}

		if (!date.isValid()) {
			cout << "podana data poza zasiegiem" << endl;
			continue;
		}

		return date;

	}
}

int CLineHelper::pickDuration()
{

	string durationStr;
	int duration;
	while (true) {
		cout << "Na ile dni chcesz wypozyczyc urzadzenie?" << endl;

		cin >> durationStr;
		try {
			duration = stoi(durationStr);
		}
		catch (exception e)
		{
			cout << "ilosc dni powinna byc liczba calkowita" << endl;
			continue;
		}
		if (duration < 0)
		{
			cout << "ilosc dni musi byc wieksza od 0" << endl;
			continue;
		}
		return duration;
	}

}
