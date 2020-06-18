// functions to find min, max and sum of min and max in an array of int

// find the min in an array, or -1 if no numbers
int min_integer(int integers[],int length)
{
	if ( length < 1 ) return -1 ;		// check we have numbers

	int min = integers[0] ;			// assume first element might be the answer
	for ( int i = 1 ; i < length ; i++ )	// check all other numbers too
	{
		if ( integers[i] < min )	// if we have a new min, update the variable
		{
				min = integers[i] ;
		}
	}
	return min ;				// return the smallest value found
}


// find the max in an array, or -1 if no numbers
int max_integer(int integers[],int length)
{
	if ( length < 1 ) return -1 ;		// check we have numbers

	int max = integers[0] ;			// assume first element might be the answer
	for ( int i = 1 ; i < length ; i++ )	// check all other numbers too
	{
		if ( integers[i] > max )	// if we have a new max, update the variable
		{
			max = integers[i] ;
		}
	}
	return max ;				// return the smallest value found
}

// find the sum of the min and max in an array, or -1 if no numbers
int sum_min_and_max(int integers[],int length)
{
	if ( length < 1 ) return -1 ;		// check we have numbers

	// return the min + max
	return min_integer(integers,length) + max_integer(integers,length) ;
}
