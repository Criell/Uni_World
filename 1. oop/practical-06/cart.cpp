#include <iostream>
#include <string>
#include "meerkat.h"
#include "cart.h"

using namespace std;

// implementation of the cart constructor
cart::cart() {
	check_full = true; 
	Meerkat_Add = new meerkat[4];
}

//implementation of a static variable
int i = 0;

// implementation of the default cart destructor
bool cart::addMeerkat(meerkat cat)
{
	if (i<=3)
	{
		Meerkat_Add[i] = cat;
		i++;
		check_full = true;
		return check_full;
	}
	
	if (i==4)
	{
		check_full = false;
		emptyCart();
		return check_full;
	}	
}


bool cart::getCheck()
{
	return check_full;
}


void cart::emptyCart()
{
	if (check_full == false)
	{ 
		delete [] Meerkat_Add;
	}
}


void cart::printMeerkats()
{
	for (int j=0 ; j<i ; j++)
	{
		cout << Meerkat_Add[j].getName() << " " << Meerkat_Add[j].getAge() << endl;
	}
}

// implementation of the default cart destructor
cart::~cart() {
}