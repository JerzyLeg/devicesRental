#pragma once
#include "Reservation.h"
#include "ReservationManager.h"
/**
 * \brief   Klasa odpowiadajaca za wybory uzytkownika.
 *
 * \details Klasa zawiera statyczne metody, ktore pozwalaj uzytkownikowi dokonac roznych wyborow, np. wybor daty, wybor urzadzenia, wybor konkretnej rezerwacji.
 */
class CLineHelper
{
public:
	/**
* \brief   Wybor rezerwacji.
*
* \details Funkcja wyswietla w konsoli wszystkie istniejace rezerwacje, uzytkownik wybiera jedna z nich, po to, zeby pozniej przy uzyciu funkcji cancel() ja anulowac.
*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor rezerewacji.
* \see ReservationManager::cancel(Reservation& reservation).
*
* \return			rezerwacja.
*
*/
	static Reservation chooseReservation(ReservationManager&);
	/**
* \brief   Wybor Usera.
*
* \details Funkcja wyswietla w konsoli wszystkich istniejacych uzytkownikow, uzytkownik wybiera jednego konkretnego, dla ktorego pozniej przy uzyciu funkcji ReservationManager::saveReservationsForUser(User *user) zostanie zapisana do pliku lista jego rezerwacji.
*
*
*
*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor wskaznikow na uzytkownikow.
*
* \see		saveReservationsForUser(User *user).
*
* \return	wskaznik na uzytkownika.
*
*/
	static User* chooseUser(ReservationManager&);
	/**
* \brief   Wybor urzadzenia.
*
* \details Funkcja wyswietla w konsoli 4 rozne urzadzenia, uzytkownik wybiera jedno.
*
*
*
*
* \param[in/out]	ReservationManager&			klasa zawierajaca wektor wskaznikow na urzadzenia.
*
* \see		ReservationManager::saveReservationsForDevice(Device *device).
* \see		ReservationManager::reserve(Reservation& reservation).
* \return	wskaznik na urzadzenie
*/
	static Device* chooseDevice(ReservationManager&);

	/**
* \brief   Wybor daty.
*
* \details Funkcja zapisuje date podana przez uzytkownika, sprawdzajac jej poprawnosc.
*
* \return	struktura data.
*
*/
	static Date pickDate();
	/**
* \brief   Wybor dlugosci wypozyczenia.
*
* \details Funkcja zapisuje ilosc dni podane przez uzytkownika, sprawdzajac poprawnosc wpisanego parametru.
*
* \return	czas trwania (ilosc dni) wypozyczenia.
*
*/
	static int pickDuration();


};

