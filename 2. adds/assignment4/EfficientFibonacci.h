#ifndef EFFICIENTFIBONACCI_H
#define EFFICIENTFIBONACCI_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <vector>


class EfficientFibonacci
{
public:
	EfficientFibonacci();						
	int Eff_Fibo(int n);
	~EfficientFibonacci();						

private:
	std::vector <int> pre_number;
};

#endif //EFFICIENTFIBONACCI_H
