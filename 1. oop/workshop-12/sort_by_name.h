#ifndef SORT_BY_NAME_H
#define SORT_BY_NAME_H

#include <iostream>
#include <stdlib.h>

#include "animal.h"
#include "hunter.h"
#include "vegie.h"

using namespace std;

class sort_by_name
{
public:
	static void sort(animal **animals,int n);	

};

#endif //SORT_BY_NAME_H
