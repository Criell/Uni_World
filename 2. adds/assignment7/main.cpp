#include <iostream>
#include <stdlib.h>
#include <string>

#include "Individual.h"
#include "Mutator.h"
#include "Rearrange.h"
#include "BitFlip.h"
#include "BitFlipProb.h"

Individual* execute(Individual* indPtr, Mutator* mPtr, int k){
	std:: string offspring;
	offspring = mPtr-> mutate(*indPtr, k);
	Individual *pO1 = new Individual;
	pO1->setString(offspring);
	return pO1;
}

int main()
{	
	std::string binarystr1, binarystr2;
	int  k1,k2;
	std::cin >> binarystr1 >> k1 >> binarystr2 >> k2;

	Individual I1(binarystr1);
	Individual I2(binarystr2);

	BitFlip b1;
	binarystr1 = b1.mutate(I1, k1);
	std::cout << binarystr1 << " ";

	Rearrange r1;
	binarystr2 = r1.mutate(I2, k2);
	std::cout << binarystr2 << " ";

	I2.setString(binarystr2);
	std::cout << I2.getMaxOnes() << std::endl;

	return 0;
}
