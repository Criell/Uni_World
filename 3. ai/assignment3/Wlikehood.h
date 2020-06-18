#include "Liketable.h"

#ifndef WLIKEHOOD_H
#define WLIKEHOOD_H

// Library for Hashtables of the Likelihood weighted sampling method
class Wlikehood{

private:
	//Array of random a set of samples  
    LikeTable table[999];
    //Track number of tables
    int index;

public:

	//Constructor
    Wlikehood(){
        index = 0; 
    }

    //Destructor
    ~Wlikehood(){}

    //Generate a table por every loop of RT|U0..UT
    void intoTable(int key, int RT, double weight){
        bool newT = true;

        //if the table exist the inner count increase 
        for (int i = 0; i < index; i++){
            if(key == table[i].getKey()){
                table[i].plusCount();
                newT = false;
            }
        }

        //if the key is new generate the new table
        if (newT){
            table[index] = LikeTable(key, RT, weight);
            index++;
        }

    }

    //loop all the tables and generate the weight of RT|U0..UT = true and RT|U0..UT 
    std::vector<double> GetlFinalWeight () {
        std::vector<double> weight;
        double Tweight = 0.0;
        double Fweight = 0.0;
        for (int i = 0; i < index; i++){
            if (table[i].getRT() == 1){
                Tweight = Tweight + (table[i].getCount() * table[i].getWeight());
            }
            else if (table[i].getRT() == 0){
                Fweight = Fweight + (table[i].getCount() * table[i].getWeight());
            }
        }

        //Generate the final weight for True and for False
        weight.push_back(Tweight);
        weight.push_back(Fweight);
        return weight;
    }
};

#endif