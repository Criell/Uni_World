#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <stdlib.h>

class Individual
{
public:
	Individual();
	Individual(std::string binary);
	Individual(int length);
	int getBit(int pos);
	std::string getString();
	void setString(std::string newbinary);
	void flipBit(int pos);
	int getMaxOnes();
	int getLength();
	~Individual();

private:
	std::string binaryString;

};

#endif //INDIVIDUAL_H
