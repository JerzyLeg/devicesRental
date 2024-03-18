#pragma once
#include "Device.h"
/**
 * \brief		Klasa reprezentujaca przyrzad pomiarowy - curve tracer.
 *
 * \details		Klasa dziedziczy cechy po klasie Device.
 */
class Recorder:public Device
{
	int	parameter4;
public:
	/**
* \brief		Konstruktor.
*
* \details		Konstruktor za pomoca listy inicjalizacyjnej odwoluje sie do konstruktora klasy bazowej.
*
* \param[in]	parameter4			unikalny parametr.
* \see			Device::Device(std::string name,string model, int channelsCount, int resolution, double price).
*
* \return		obiekt.
*
*/
	Recorder(std::string name,std::string model, int channelsCount, int resolution, double price,int parameter4);
	friend ostream& operator<<(ostream& os, Recorder* rec);
	/**
* \brief		Funkcja, zapisujaca parametry do stringa.
*
* \details		Funkcja po kolei wpisuje do stringa parametry obiektu (nazwa, model..., unikalny parametr) odwolujac sie do funkcji toString() klasy Device.
*
* \see			Device::toString().
*
* \return		ciag znakow, urzadzenie i jego parametry.
*
*/
	string toString();
	/**
* \brief		Funkcja zliczajaca cene.
*
* \details		Funkcja mnozy cene za wypozyczenie przez podatek od konkretnego urzadzenia.
*
*
* \return		cena za 1-dniowe wypozyczenie.
*
*/
	float calculatePrice() override;
};

