#include "Rearrange.h"

Rearrange::Rearrange(){}

// Return the square value of x
std::string Rearrange::mutate (Individual ADN, int k)
{
	int start = 0;
	if (k == 0){
		start = ADN.getLength();
	}
	else if (k <= ADN.getLength()){
		start = k;
	}
	else {
		start = circles (k, ADN.getLength());
	}

	std::string ADNnew;
	ADNnew = ADN.getString().substr(start-1,ADN.getLength());
	ADNnew = ADNnew + ADN.getString().substr(0,start-1);

	return ADNnew;
}

Rearrange::~Rearrange(){}
