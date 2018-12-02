#include "Misc.h"
#include <math.h>
#include <string>

unsigned Misc::getNumberOfDigits(unsigned i) {
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

std::string Misc::turnNumberIntoString(int n) {
	bool negative(false);

	if (n < 0) {
		n = -n;
		negative = true;
	}

	int digits = getNumberOfDigits(n);
	int i(1), p(1), v(1);
	std::string num, temp;


	for (int check(0); digits > check; ++check) {
		num = std::to_string(n / (i * 1) % 10) + temp;
		temp = num;
		i = i * 10;
		if (check < digits-1 && ((v / (3 * p) ) == 1 )) {
			num = "," + temp;
			temp = num;
			p = p + 1;
		}
		v = v + 1;
	}
	if (negative == true) {
		num = "-" + num;
	}

	return num;
}