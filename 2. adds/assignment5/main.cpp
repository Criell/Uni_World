#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>

#include "ReduceGeneric.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"

#include "MapGeneric.h"
#include "MapTriple.h"
#include "MapSquare.h"
#include "MapAbsoluteValue.h"

#include "FilterGeneric.h"
#include "FilterOdd.h"
#include "FilterNonPositive.h"
#include "FilterForTwoDigitPositive.h"

int main()
{	

	//Take the input list of numbers as a string(temp)
	std::string input;
	std::getline(std::cin, input);

	input = input + " ";
	std::string temp = " ";

	std::vector<int>numbers;

	//convert to int the values in the input and store them in vector numbers
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (isdigit(input[i]) || input[i] == '-')
		{
			temp = temp + input[i];
		}

		if (input[i] == ' ')
		{
			std::stringstream intinput(temp);
			temp.clear();

			int tempint;
			intinput >> tempint;

			numbers.push_back(tempint);
		}
	}


	//created an object of every class and use them to call the generic functions


	//Take the input numbers and return the absolute value of them 
	MapAbsoluteValue MaVal;
	numbers = MaVal.map(numbers);

	//Take numbers and return the triple value of the input
	MapTriple MaT;
	numbers = MaT.map(numbers);

	MapSquare MaSqua;

	//Take numbers and return a new vector with the odd values of the input
	std::vector <int> oddNumbers;
	FilterOdd FigO;
	oddNumbers = FigO.filter(numbers);

	//Take the odd values and return newnumbers vector with only 2digits values
	std::vector <int> newNumbers;
	FilterForTwoDigitPositive FiTwo;
	newNumbers = FiTwo.filter(oddNumbers);

	FilterNonPositive FiNoP;


	//Take newnumbers and return and print a new vector with the minimum value
	std::vector <int> results;
	ReduceMinimum RedM;
	results = RedM.reduce(newNumbers);

	for(int i = 0; i < (int)results.size(); i++)
	{
		std::cout << results.at(i);
	}

	std::cout << " ";

	//Take newnumbers and return and print the result with the GCD value
	ReduceGCD RedG;
	results = RedG.reduce(newNumbers);

	for(int i = 0; i < (int)results.size(); i++)
	{
		std::cout << results.at(i) << std::endl;
	}

	return 0;
}
