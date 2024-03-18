#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <sstream>


vector<Device*> FileManager::loadDevices(string sciezka)
{
	ifstream plik_wejsciowy;
	string line;
	vector<Device*>devices;
	plik_wejsciowy.open(sciezka);

	if (plik_wejsciowy.is_open())
	{
		int licznik_lini{ 0 };

		while (getline(plik_wejsciowy, line))
		{
			licznik_lini++;
			if (licznik_lini == 1)
			{
				continue;
			}

			//cout << line << endl;
			istringstream ss(line);
			string komorka;
			int licznik = 0;
			Device* ptr = nullptr;
			string Name;
			string Model;
			int ChannelsCount;
			int Resolution;
			int Price;
			vector<string> Parameter(4);
			while (getline(ss, komorka, ','))
			{
				//std::cout << komorka << '\n';
				switch (licznik)
				{
				case 0:
					Name = komorka;
					break;
				case 1:
					Model = komorka;
					break;
				case 2:
					ChannelsCount = stoi(komorka);
					break;
				case 3:
					Resolution = stoi(komorka);
					break;
				case 4:
					Price = stoi(komorka);
					break;
				case 5:
					Parameter[0] = komorka;
					break;
				case 6:
					Parameter[1] = komorka;
					break;
				case 7:
					Parameter[2] = komorka;
					break;
				case 8:
					Parameter[3] = komorka;
					break;
				}
				licznik++;
			}
			if (Name == "curve tracer")
				ptr = new CurveTracer(Name, Model, ChannelsCount, Resolution, Price, stoi(Parameter[0]));
			if (Name == "detector")
				ptr = new Detector(Name, Model, ChannelsCount, Resolution, Price, stoi(Parameter[1]));
			if (Name == "gauge")
				ptr = new Gauge(Name, Model, ChannelsCount, Resolution, Price, stoi(Parameter[2]));
			if (Name == "recorder")
				ptr = new Recorder(Name, Model, ChannelsCount, Resolution, Price, stoi(Parameter[3]));
			
			devices.push_back(ptr);
		}
	}
	return devices;
}

void FileManager::saveReservations(ReservationManager& rm)
{
	auto reservations = rm.getReservations();
	ofstream outfile;
	outfile.open("listaRezerwacji.csv");

	if (outfile.is_open())
	{
		for (auto reservation : reservations) {
			outfile << reservation.toCSV() << endl;
		}
	}
}

void FileManager::loadReservations(ReservationManager& rm)
{
	rm.getReservations().clear();

	ifstream plik;
	string line;
	plik.open("listaRezerwacji.csv");
	if (plik.is_open())
	{
		while (getline(plik, line))
		{
		
			istringstream ss(line);
			string komorka;
			vector<string> singleReservation;
			while (getline(ss, komorka, ','))
			{
				singleReservation.push_back(komorka);
			}
			Reservation reservation(stoull(singleReservation[3]), stoull(singleReservation[2]), singleReservation[0], stoi(singleReservation[1]));
			rm.getReservations().push_back(reservation);
		}
	}
}

void FileManager::loadDevices(ReservationManager& rm)
{
	//auto devices = rm.getDevices();
	rm.getDevices() = FileManager::loadDevices("spisUrzadzen.csv");
}

void FileManager::loadUsers(ReservationManager& rm)
{
	ifstream plik;
	string line;
	plik.open("listaUzytkownikow.csv");
	if (plik.is_open())
	{
		while (getline(plik, line))
		{
			istringstream ss(line);
			string komorka;
			vector<string> singleUser;
			while (getline(ss, komorka, ','))
			{
				singleUser.push_back(komorka);
			}
			User* user = new User(singleUser[0],singleUser[1]);
			rm.getUsers().push_back(user);
			/*rm.getUsers().emplace_back(singleUser[0], singleUser[1]);*/
		}
	}
}

void FileManager::saveUsers(ReservationManager& rm)
{
	auto users = rm.getUsers();
	ofstream plik;
	plik.open("listaUzytkownikow.csv");
	for (auto user : users)
	{
		if (plik.is_open())
		{
			plik << user->toCSV() << endl;
		}
	}
}

void FileManager::saveUser(User& user)
{
	ofstream plik;
	plik.open("listaUzytkownikow.csv", ios::app);
	if (plik.is_open())
	{
		plik << user.toCSV() << endl;
	}
}
