#pragma once
#include <vector>
#include "Device.h"
#include "CurveTracer.h"
#include "Detector.h"
#include "Gauge.h"
#include "Recorder.h"
#include "ReservationManager.h"

using namespace std;
/**
 * \brief   Klasa obslugujaca pliki.
 *
 * \details Klasa posiada statyczne funkcje, ktore zapisuja dane do plikow i wczytuja je z plikow.
 */
class FileManager
{
	/*static char* devicesFilePath{ "listaUrzadzen.csv" };*/
public:
	static void loadState();
	/**
* \brief   Zapisywanie listy rezerwacji.
*
* \details Statyczna funkcja dzieki ReservationManager::getReservations() ma dostep do zlozonych rezerwacji i za pomoca funkcji Reservation::toCSV zapisuje je do pliku wyjsciowego.

*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor rezerwacji.
* \see ReservationManager::getReservations().
* \see Reservation::toCSV.
*
*/
	static void saveReservations(ReservationManager&);
	/**
* \brief   Zapisywanie rezerwacji.
*
* \details Statyczna funkcja sczytuje linia po lini parametry oddzielone przecinkiem z pliku z lista rezerwacji i zapisuje je do wektora rezerwacji.
*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor rezerwacji.
* \see ReservationManager::getReservations().
*
*/
	static void loadReservations(ReservationManager&);
	/**
* \brief   Ladowanie urzadzen.
*
* \details Statyczna funkcja wywoluje funkcje FileManager::loadDevices(string sciezka), ktora sczytuje urzadzenia i ich parametry, a nastepnie zapisuje je do wektora urzadzen.
*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor rezerwacji.
* \see ReservationManager::getDevices().
* \see FileManager::loadDevices(string sciezka).
*
*/
	static void loadDevices(ReservationManager&);
	/**
* \brief   Ladowanie uzytkownikow.
*
* \details Statyczna funkcja sczytuje linia po lini parametry oddzielone przecinkiem z pliku z lista uzytkownikow i zapisuje je do wektora uzytkownikow.
*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor rezerwacji.
* \see ReservationManager::getUsers().
*
*/
	static void loadUsers(ReservationManager&);
	/**
* \brief   Zapisywanie uzytkownika.
*
* \details Statyczna funkcja dopisuje uzytkownikow do pliku przy uzyciu funckji User::toCSV().

*
* \param[in/out]	User&			klasa reprezentujaca uzytkownika.
* \see User::toCSV().
*
*/

	static void saveUsers(ReservationManager&);
private:
	/**
* \brief   Ladowanie urz¹dzeñ.
*
* \details Statyczna funkcja sczytuje urzadzenia i ich parametry, a nastepnie zapisuje je do wektora urzadzen.
*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor rezerwacji.
*
* \return	wektor urzadzen.
*/
	static vector<Device*> loadDevices(string sciezka);
	/**
* \brief   Zapisywanie uzytkownika.
*
* \details Statyczna funkcja zapisuje uzytkownika do pliku przy uzyciu funckji User::toCSV().

*
* \param[in/out]	User&			klasa reprezentujaca uzytkownika.
* \see User::toCSV().
*
*/
	static void saveUser(User&);
};
