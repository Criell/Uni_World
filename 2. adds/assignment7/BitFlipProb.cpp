#include "BitFlipProb.h"

BitFlipProb::BitFlipProb(){
	p = (std::rand() % 100)*0.01;
	//std::cout << p << std::endl;
}

// Return the square value of x
std::string BitFlipProb::mutate (Individual ADN, int k)
{
	for (int i = 0; i < ADN.getLength(); i++){
		if (p > 0.5){
			ADN.flipBit(i);
		}
	}
	return ADN.getString();
}

BitFlipProb::~BitFlipProb(){}



