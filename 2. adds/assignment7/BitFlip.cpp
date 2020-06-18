#include "BitFlip.h"

BitFlip::BitFlip(){}

// Return the square value of x
std::string BitFlip::mutate (Individual ADN, int k){
	if (k == 0 ){
		ADN.flipBit(ADN.getLength());
	}
	else if (k <= ADN.getLength()){
		ADN.flipBit(k-1);
	}
	else{
		int newk = 0;
		newk = circles (k, ADN.getLength());
		ADN.flipBit(newk-1);
	}
	return ADN.getString();
}

BitFlip::~BitFlip(){}

