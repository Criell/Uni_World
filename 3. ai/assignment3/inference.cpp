#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Wlikehood.h"

//Likelihood weighted sampling method
std::vector<double> LW_Sampler (std::vector<int>U, int N);
void WeightedCoin(std::vector<int> U);

//Gibbs sampling method
std::vector<double> GIBBS_Sampler(std::vector<int>U, int N);
int Random_GIBBS(std::vector<int>U, std::vector<int>R);
std::vector<double> Markov_blanket(std::vector<int>U, std::vector<int>R, int i);

//Generate true or false with the given probability
double RandomSample (double True);


int main (int argc,char *argv[]){

    srand((unsigned)time(0)); 
    
    //Read and store the input from the parameter file 
    std::ifstream fp;
    fp.open(argv[1]);
    std::string line;
    getline(fp,line);
    
    // Generate the vector U with the observation variables
    std::vector<int> U;
    std::stringstream linestream( line );
    int temp;
    int evidence = 0;
    while ( linestream >> temp ){
        U.push_back(temp);
        evidence++;
    }

    //Number of samples
    int N = 20000;
    
    //Use the observation variables to generate N likelihood weighted samples
    std::vector<double> Final_LW_P;
    Final_LW_P = LW_Sampler (U,N);
    printf("%.3f %.3f Likelohood\n", Final_LW_P[0], Final_LW_P[1]);
    
    //Use the observation variables to generate N GIBBS samples
    std::vector<double> Final_GB_P;
    Final_GB_P = GIBBS_Sampler (U,N);
    printf("%.3f %.3f Gibbs\n ", Final_GB_P[0], Final_GB_P[1]);
   
    return 0;
}

//Generate true or false with the given probability
double RandomSample (double True){
    int R;
    double sample = ((rand()%10)+1)*0.1;
    if ( sample <= True){
        R = 1;
    } else {
        R = 0;
    }
    return R;
}

/*****LIKELIHHOD WEIGHTED SAMPLING METHOD*****/


//library of hash tables of every loop of RT|U0..UT
Wlikehood globalSystem;

void WeightedCoin(std::vector<int> U){

    //Store in a vector Histori_R a coin toss probability 
    std::vector<int> Histori_R;
    Histori_R.push_back(RandomSample(0.2));
    for (int i = 1; i < U.size(); i++){
        if ( Histori_R[i-1] == 1 ){
            Histori_R.push_back(RandomSample(0.7));    
        } else if ( Histori_R[i-1] == 0 ){
            Histori_R.push_back(RandomSample(0.3)); 
        }   
    }

    int key = 1;
    int RT = 0; 
    double w = 1;

    //Calculate the probability of RT|U0…UT using U and Histori_R 
    int N = U.size()-1;
    key = pow(10,N+1);
   
    for (int i = 0; i < N+1; i++){
        if ((U[i] == 1) && (Histori_R[i] == 1)) {
            key = key + pow(10,N-i);
            w = w * 0.9;
        }
        else if ((U[i] == 1) && (Histori_R[i] == 0)){
            w = w * 0.2;
        }
        else if ((U[i] == 0) && (Histori_R[i] == 1)){
            key = key + pow(10,N-i);
            w = w * 0.1;
        } 
        else if ((U[i] == 0) && (Histori_R[i] == 0)){
            w = w * 0.8;
        }
        
        if ((U[N] == 1) && (Histori_R[N] == 1))
            RT = 1;
        if ((U[N] == 0) && (Histori_R[N] == 1))
            RT = 1;
    } 

    //created the hash table or increase the count of the key
    globalSystem.intoTable(key, RT, w); 
}

//loops N creating tables or increase the count 
std::vector<double> LW_Sampler (std::vector<int>U, int N){
    std::vector<double> LW_P;
    for (int i = 0; i < N; i++){
        //Calculate the likelihood weighted for every N.
        WeightedCoin(U);
    }
    LW_P = globalSystem.GetlFinalWeight();
    double alpha = 1 / ((LW_P[0]) + (LW_P[1])); 
    std::vector<double> Final_LW_P;
    Final_LW_P.push_back(alpha * (LW_P[0]));
    Final_LW_P.push_back(alpha * (LW_P[1]));
    return Final_LW_P;
}

/*****GIBBS SAMPLING METHOD*****/


std::vector<double> Markov_blanket(std::vector<int>U, std::vector<int>R, int i){
    //Random choose to change R0…RT with Markov_blanket method
    std::vector<double> MB_P;
    double ValueT1, ValueT2, ValueT3; 
    double ValueF1, ValueF2, ValueF3; 
    if (R[i-1] == 1){ ValueT1 = 0.7;
    } else { ValueT1 = 0.3; }
    if (R[i-1] == 1){ ValueF1 = 0.3;
    } else { ValueF1 = 0.7; }
    if (U[i] == 1){ ValueT2 = 0.9;
    } else { ValueT2 = 0.1; } 
    if (U[i] == 1){ ValueF2 = 0.2; 
    } else { ValueF2 = 0.8; }
    if (R[i+1] == 1){ ValueT3 = 0.7;
    } else { ValueT3 = 0.3; }
    if (R[i+1] == 1){ ValueF3 = 0.3;
    } else { ValueF3 = 0.7; }
    double MB_T = ValueT1 * ValueT2 * ValueT3;
    double MB_F = ValueF1 * ValueF2 * ValueF3;
    double alpha = 1 / ((MB_T) + (MB_F));
    MB_T = MB_T * alpha;
    MB_F = MB_F * alpha;
    MB_P.push_back(MB_T);
    MB_P.push_back(MB_F);
    return MB_P;
}

int Random_GIBBS(std::vector<int>U, std::vector<int>R){
    //Probability of RT|U0…UT using my U and Histori_R
    std::vector<double> MB_P;
    int new_R;
    double true_P;
    double ValueT1, ValueT2, ValueT3; 
    double ValueF1, ValueF2, ValueF3;
    double alpha; 
    //Probability of R0|U0 using my U and Histori_R
    if (U[0] == 1){ ValueT2 = 0.9;
    } else { ValueT2 = 0.1; } 
    if (U[0] == 1){ ValueF2 = 0.2; 
    } else { ValueF2 = 0.8; }
    if (R[1] == 1){ ValueT3 = 0.7;
    } else { ValueT3 = 0.3; }
    if (R[1] == 1){ ValueF3 = 0.3;
    } else { ValueF3 = 0.7; }
    alpha = 1 / ((ValueT2 * ValueT3) + (ValueF2*ValueF3));
    true_P = (ValueT2 * ValueT3) * alpha;
    
    //Random choose to change of not using the previous probability
    new_R = RandomSample(true_P);
    R[0] = new_R;
    int Psize = U.size()-1;

    //Random choose to change R0…RT with Markov_blanket method
    for (int i = 1; i < Psize; i++){
        MB_P = Markov_blanket(U, R, i);
        true_P = MB_P[0];
        //Random choose to change of not using the previous probability
        new_R = RandomSample(true_P);
        R[i] = new_R;    
    }

    //Probability of RT|UT using my U and Histori_R
    if (R[Psize-1] == 1){ ValueT1 = 0.7;
    } else { ValueT1 = 0.3; }
    if (R[Psize-1] == 1){ ValueF1 = 0.3;
    } else { ValueF1 = 0.7; }
    if (U[Psize] == 1){ ValueT2 = 0.9;
    } else { ValueT2 = 0.1; } 
    if (U[Psize] == 1){ ValueF2 = 0.2; 
    } else { ValueF2 = 0.8; }
    alpha = 1 / ((ValueT1 * ValueT2) + (ValueF1*ValueF2));
    true_P = (ValueT1 * ValueT2) * alpha;
    
    //Random choose to change of not using the previous probability
    new_R = RandomSample(true_P);
    R[Psize] = new_R;
    return R[Psize];
}

std::vector<double> GIBBS_Sampler(std::vector<int>U, int N){
    //Store in a vector Histori_R a coin toss probability 
    std::vector<int> Histori_R;
    Histori_R.push_back(RandomSample(0.2));
    for (int i = 1; i < U.size(); i++){
        if ( Histori_R[i-1] == 1 ){
            Histori_R.push_back(RandomSample(0.7));    
        } else if ( Histori_R[i-1] == 0 ){
            Histori_R.push_back(RandomSample(0.3)); 
        }   
    }

    int count_t = 0;
    int count_f = 0;
    for (int i = 0; i < N; i++){
        ////Calculate Gibbs for every N
        int RT = Random_GIBBS(U, Histori_R);

         //Keep track of how many times RT was true or false
        if (RT == 1){
            count_t++;
        } else if (RT == 0){
            count_f++;
        }
    }
    std::vector<double> Final_GB_P;
    double temp = (count_t + count_f);
    Final_GB_P.push_back(count_t/temp);
    Final_GB_P.push_back(count_f/temp);
    return Final_GB_P;
}

/*****FILTERING METHOD*****/

std::vector<double> Filtering (std::vector<double>PT_0, std::vector<double>PT_S, std::vector<double>PT_O, std::vector<int>U){
    std::vector<double> Update;
    Update.push_back(PT_0[0]);
    Update.push_back(PT_0[1]);
    double TableP_T = PT_S[0];
    double TableP_F = PT_S[1];
    double ObsP_T = PT_O[0];
    double ObsP_F = PT_O[1];
    std::vector<double> Prediction;
    Prediction.push_back(1.0);
    Prediction.push_back(1.0);
    double temp_t;
    double temp_f;
    double alpha;
    for (int i = 0; i < U.size(); i++)
    {
        if (U[i] == 1){
            Prediction[0] = ((Update[0] * TableP_T) + (Update[1] * TableP_F));
            Prediction[1] = ((Update[1] * TableP_T) + (Update[0] * TableP_F));
            temp_t = ObsP_T * Prediction[0];
            temp_f = ObsP_F * Prediction[1];
            alpha = 1/(temp_t + temp_f);
            Update[0] = temp_t * alpha;             
            Update[1] = temp_f * alpha;
        }
    }

    return Update;
}

std::vector<double>  ProbTables (double PT, double PF){
    std::vector<double> PTables;
    PTables.push_back(PT);
    PTables.push_back(PF);    
    return PTables;   
}
