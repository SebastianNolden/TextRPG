#include "Misc.h"
#include <math.h>

unsigned Misc::GetNumberOfDigits(unsigned i) {
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

