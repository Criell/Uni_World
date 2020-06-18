#include "Mutator.h"
#include "Individual.h"

Mutator::Mutator(){}

int Mutator::circles (int k, int l){
	if (k < l){
		return k;
	}
	else{
		circles(k-l,l);
	}
}

Mutator::~Mutator(){}
