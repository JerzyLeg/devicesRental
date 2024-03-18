#pragma once
#include <string>
using namespace std;

//enum DeviceType
//{
//	MIERNIKI,REJESTRATORY,CHARAKTEROGRAFY,DETEKTORY
//};
/**
 * \brief   Klasa reprezentujca urzadzenie.
 *
 * \details Wirtualna klasa bazowa.
 */
class Device
{
protected:
	std::string name{};
	std::string model{};
	int channelsCount{ -1 };
	int resolution{ -1 };
	double price{ -1 };
	size_t ID{ 0 };

public:
	/**
* \brief		Konstruktor.
*
* \details		Konstruktor parametryczny klasy bazowej, dzieki funkcji Device::generateID() ustawia rowniez prywatne pole ID.
*
* \param[in]	name			nazwa.
* \param[in]	model			model.
* \param[in]	channelsCount	liczba kanalow.
* \param[in]	resolution		rozdzielczosc.
* \param[in]	price			cena.
* \see			Device::generateID().
*
* \return		urzadzenie
*
*/
	Device(std::string name,string model, int channelsCount, int resolution, double price);
	/**
* \brief   Uchwyt do ID.
*
* \details Funkcja daje dostep do prywatnego pola ID.
*
* \return	numer identyfikacyjny urzadzenia.
*
*/
	size_t getID();
	/**
* \brief   Uchwyt do Name.
*
* \details Funkcja daje dostep do prywatnego pola name.
*
* \return	nazwa urzadzenia.
*
*/
	string getName();
	friend ostream& operator<<(ostream& os, Device* dev);
	/**
* \brief		Funkcja, zapisujaca parametry do stringa.
*
* \details		Funkcja po kolei wpisuje do stringa parametry obiektu (nazwa, model...).
*
* \return		ciag znakow, urzadzenie i jego parametry.
*
*/
	virtual string toString();
	/**
* \brief		Funkcja zliczajaca cene.
*
* \details		Funkcja mnozy cene za wypozyczenie przez domyslny podatek (*1.0) urzadzenia bazowego.
*
*
* \return		cena za 1-dniowe wypozyczenie.
*
*/
	virtual float calculatePrice();

private:
	/**
* \brief		Funkcja generujaca numer identyfikacyjny i ustawiajaca pole ID.
*
* \details		Funkcja generuje unikalny kod dla kazdego z 4 urzadzen.
*
*/
	void generateID();
};

