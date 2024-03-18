#pragma once
#include <string>
using namespace std;
/**
 * \brief   Klasa reprezentujaca uzytkownika.
 *
 * \details Klasa przechowuje parametry uzytkownika: ID uzytkownika, nazwe uzytkownika oraz email uzytkownika.
 */
class User
{
	string username_{};
	string email_{};
	size_t ID{ 0 };
public:
	/**
* \brief		Konstruktor.
*
* \details		Konstruktor parametryczny, dzieki funkcji User::generateID() ustawia rowniez prywatne pole ID.
*
* \param[in]	username		nazwa uzytkownika.
* \param[in]	email			email.
* \see			User::generateID().
*
* \return		uzytkownik.
*
*/
	User(string, string);
	/**
* \brief		Funkcja, zapisujaca parametry do stringa.
*
* \details		Funkcja po kolei wpisuje do stringa podpisane naglowkami username oraz email.
*
* \return		ciag znakow, parametry uzytkownika.
*
*/
	string toString();
	/**
* \brief   Uchwyt do ID.
*
* \details Funkcja daje dostep do prywatnego pola ID.
*
* \return	numer identyfikacyjny uzytkownika.
*
*/
	size_t getID();
	/**
* \brief		Funkcja, zapisujaca parametry do stringa.
*
* \details	    Funkcja po kolei wpisuje do stringa parametry uzytkownika, sa oddzielone przecinkami.
*
* \return		ciag znakow, dane uzytkownika.
*
*/
	string toCSV();
	/**
* \brief   Uchwyt do username_.
*
* \details Funkcja daje dostep do prywatnego pola username_.
*
* \return	nazwa uzytkownika.
*
*/
	string& username();
	/**
* \brief   Uchwyt do username_.
*
* \details Funkcja daje dostep do prywatnego pola email_.
*
* \return	email uzytkownika.
*
*/
	string& email();
private:
	/**
* \brief		Funkcja generujaca numer identyfikacyjny i ustawiajaca pole ID.
*
* \details		Funkcja generuje unikalny kod dla kazdego stworzonego uzytkownika.
*
*/
	void generateID();
};

