#pragma once

#include <sstream>
#include <vector>
/**
 * \brief   Struktura obslugujaca daty.
 *
 */
struct Date
{
    int day, month, year;
    Date() {};
    /**
* \brief		Konstruktor.
*
* \details		Konstruktor parametryczny.
*
* \param[in]	dataStr			data(string).
*
* \return		Date            data(Date).
*
*/
    Date(string dataStr)
    {
        vector<string> lines;
        istringstream ss(dataStr);
        while (getline(ss, dataStr, '/')) {
            lines.push_back(dataStr);
        }
        this->day = stoi(lines[0]);
        this->month = stoi(lines[1]);
        this->year = stoi(lines[2]);
    }
    /**
* \brief		Funkcja, zapisujaca parametry do stringa.
*
* \details	    Funkcja zapisuje date w odpowiednim formacie.
*
* \return		string			ciag znakow, data(dzien/miesiac/rok).
*
*/
    string toString()
    {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
    /**
* \brief		Funkcja weryfikujaca podane daty.
*
* \details	    Funkcja sprawdza czy istnieje taki dzien,miesiac oraz czy rok nie jest przestarzaly.
*
* \return		false jesli ktorys z podanych parametrow jest nieprawidlowy/true.
*
*/
    bool isValid() {
        if (day < 1 || day > 31) return false;
        if (month < 1 || month > 12) return false;
        if (year < 2000 || year > 2050) return false;

        return true;
    }
};