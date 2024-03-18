#pragma once
#include "Device.h"
#include "User.h"
#include "Date.h"
/**
 * \brief   Klasa reprezentujaca rezerwacje.
 *
 * \details Klasa posiada wszystkie parametry rezerwacji, ID usera, ID urzadzenia, czas wypozyczenia.
 */
class Reservation
{
	User* user{ nullptr };
	Device* device{ nullptr };
	//string data_str;
	Date date;
	int duration;
	
public:
	size_t userID;
	size_t deviceID;
	size_t ID;
public:
	/**
* \brief		Konstruktor.
*
* \details		Konstruktor parametryczny, ustawiajacy pointery na usera oraz urzadzenia, a takze date i okres czasu.
*
* \param[in]	user			pointer na usera.
* \param[in]	device			pointer na urzadzenie.
* \param[in]	date			data rozpoczecia rezerwacji.
* \param[in]	duration		okres czasu wypozyczenia.
*
* \return		rezerwacja.
*
*/
	Reservation(User* user, Device* device, Date date, int duration);
	/**
* \brief		Konstruktor.
*
* \details		Konstruktor parametryczny, ustawiajacy ID usera oraz urzadzenia, a takze date i okres czasu.
*
* \param[in]	userID			unikalny numer identyfikacyjny.
* \param[in]	deviceID		numer identyfikacyjny urzadzenia.
* \param[in]	date			data rozpoczecia rezerwacji.
* \param[in]	duration		okres czasu wypozyczenia.
*
* \return		rezerwacja.
*
*/
	Reservation(size_t userID, size_t deviceID, string date, int duration);
	/**
* \brief		Konstruktor domyslny.
*
* \return		rezerwacja.
*
*/
	Reservation();
	friend ofstream& operator<<(ofstream& of, Reservation& res);
	/**
* \brief		Funkcja, zapisujaca parametry do stringa.
*
* \details	    Funkcja po kolei wpisuje do stringa parametry rezerwacji z podpisami.
*
* \return		ciag znakow, dane rezerwacji.
*
*/
	string toString();
	/**
* \brief		Funkcja, zapisujaca parametry do stringa.
*
* \details	    Funkcja po kolei wpisuje do stringa parametry rezerwacji, sa oddzielone przecinkami.
*
* \return		ciag znakow, dane rezerwacji.
*
*/
	string toCSV();
	/**
* \brief		Setter dla usera.
*
* \details	    Funkcja ustawia wskaznik na usera.
* \param[in]	wskaznik na uzytkownika.
*
*/
	void setUser(User *user);
	/**
* \brief		Setter dla urzadzenia.
*
* \details	    Funkcja ustawia wskaznik na urzadzenie.
* \param[in]	wskaznik na urzadzenie.
*
*/
	void setDevice(Device *device);
	/**
* \brief		Funkcja zliczajaca calkowita cene z jednej rezerwacji.
* 
* \details		Funkcja przemnaza cene za wypozyczenie(na 1 dzien) przez ilosc dni, jest to mozliwe poprzez ustawienie wskaznika na konkretne urzadzenie i wyliczenie ceny dla niego.
* \see			CurveTracer::calculatePrice().
* \see			Recorder::calculatePrice().
* \see			Gauge::calculatePrice().
* \see			Detector::calculatePrice().
* 
* \return		calkowita cena za wypozyczenie.
*/
	float getFullPrice();
private:
	/**
* \brief		Funkcja generujaca numer identyfikacyjny i ustawiajaca pole ID.
*
* \details		Funkcja generuje unikalny kod dla kazdej stworzonej rezerwacji.
*
*/
	size_t generateID();
};