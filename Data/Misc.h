#pragma once

#include <string>

class Misc
{
public:
	//Gibt die Anzahl der Ziffern einer Zahl an
	unsigned getNumberOfDigits(unsigned i);

	//Wandelt eine Zahl in einen String um. Zahlen erhalten entsprechende Dezimalpunkte alle 3 Stellen
	std::string turnNumberIntoString(unsigned n);
};

