#include <iostream>
#include <stdlib.h>

extern int diagonal(int array[4][4]);

int main()
{ 
    int array[4][4]={{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
  
    std::cout << "The sum is: "<<diagonal(array)<<"\n";
    
    return 0;
}
