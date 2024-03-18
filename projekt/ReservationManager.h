#pragma once
#include "Reservation.h"
#include <vector>

/**
 * \brief   Klasa obslugujaca rezerwacje.
 *
 * \details Klasa posiada wektory najwazniejszych skladowych wypozyczalni - rezerwacji, uzytkonikow i urzadzen oraz najwazniejsze metody umozliwiajace jej dzialanie.
 */
class ReservationManager
{
	std::vector<Reservation> reservations;
	std::vector<User*> users;
	std::vector<Device*> devices;
public:
	/**
* \brief		Funkcja rezerwujaca. 
*
* \details	    Funkcja zapisuje stworzona rezerwacje do wektora rezerwacji
* \param[in]	reservation&			stworzona rezerwacja.
* \return		true.
*
*/
	bool reserve(Reservation& reservation);
	/**
* \brief		Funkcja anulujaca.
*
* \details	    Funkcja przeszukuje wektor rezerwacji po numerach ID i usuwa rezerwacje, jesli ID sie zgadza.
* \param[in]	reservation&			wybrana rezerwacja.
*
*/
	void cancel(Reservation& reservation);
	/**
* \brief		Funkcja zapisujaca rezerwacje uzytkownika do pliku.
*
* \details	    Funkcja przeszukuje wektor rezerwacji po numerach ID uzytkownika i wywoluje funkcje Reservation::toString() do zapisu rezerwacji na danego uzytkownika.
* \param[in]	User*			wybrany uzytkownik.
* \see			Reservation::toString().
*/
	void saveReservationsForUser(User *user);
	/**
* \brief		Funkcja zapisujaca rezerwacje uzytkownika do pliku.
*
* \details	    Funkcja przeszukuje wektor rezerwacji po numerach ID urzadzen i wywoluje funkcje Reservation::toString() do zapisu rezerwacji na dane urzadzenie.
* \param[in]	Device*			wybrane urzadzenie.
* \see			Reservation::toString().
*/
	void saveReservationsForDevice(Device *device);
	/**
* \brief   Uchwyt do zbioru rezerwacji.
*
* \details Funkcja daje dostep do prywatnego pola wektor rezerwacji.
*
* \return	wektor rezerwacji.
*
*/
	vector<Reservation>& getReservations();
	/**
* \brief   Uchwyt do spisu urzadzen.
*
* \details Funkcja daje dostep do prywatnego pola wektor urzadzen.
*
* \return	wektor urzadzen.
*
*/
	vector<Device*>& getDevices();
	/**
* \brief   Uchwyt do listy uzytkownikow.
*
* \details Funkcja daje dostep do prywatnego pola wektor uzytkownikow.
*
* \return	wektor uzytkownikow.
*
*/
	vector<User*>& getUsers();
	/**
* \brief   Funkcja wyswietlajaca.
*
* \details Funkcja wyswietla w konsoli uzytkownikow wraz z przypisanym im numerem.
* \see User::toString().
*
*/
	void listUsers();
	/**
* \brief   Funkcja dodajace uzytkownikow.
*
* \details Funkcja przechodzi przez wektor uzytkownikow, jesli dane uzytkownika sa nowe, to zostaje dopisany do wektora uzytkownikow. 
* \return	uzytkownik;
*
*/
	User* addUser(User* user);
	/**
* \brief   Funkcja wyswietlajaca.
*
* \details Funkcja wyswietla w konsoli urzadzenia wraz z przypisanym im numerem.
* \see Device::toString().
*/
	void listDevices();
	/**
* \brief   Funkcja laczaca ID i pointery.
*
* \details Funkcja przechodzi przez rezerwacje, urzadzenia i uzytkownikow, gdy numery ID sie zgadzaja, to zostaja wywolane funkcje Reservation::SetUser(User* user) oraz Reservation::SetDevice(Device* device), ktore ustawiaja pointery(parametry rezerwacji)
* \see Reservation::SetUser(User* user).
* \see Reservation::SetDevice(Device* device).
*/
	void init();
};

