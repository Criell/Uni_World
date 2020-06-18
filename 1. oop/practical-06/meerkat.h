#ifndef MEERKAT_H
#define MEERKAT_H

#include <iostream>
#include <string>
#include "meerkat.h"

using namespace std;

// Class definition for a meerkat
class meerkat
{
    public:
        meerkat();
        void setName(string meerName);
        std::string getName();
        void setAge(int meerAge);
        int getAge();
        ~meerkat();

    private:
        std::string name;
        int age;
};

#endif //MEERKAT_H
