#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#ifndef LIKETABLE_H
#define LIKETABLE_H

//Hash table for a loop of RT|U0..UT
class LikeTable {
private:
    int key;
    int W;
    double value;
    int count; 
    
public:
    //Generic constructor 
    LikeTable() {};
    //Constructor 
    LikeTable(int Pkey, int RT, double Pvalue) {
        this->key = Pkey;
        this->W = RT;
        this->value = Pvalue;
        this->count = 1;
    }

    //Functions than get and set variables of the table
    int getKey() {
        return key;
    }
    void setWeight(double Pweight){
        this->value = Pweight;
    }
    double getWeight() {
        return value;
    }
    void plusCount(){
        count++;
    }
    int getCount(){
        return count;
    }
    int getRT() {
        return W;
    }

    //Destructor
    ~LikeTable() {};
};

#endif