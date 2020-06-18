#ifndef CART_H
#define CART_H

#include <iostream>
#include <string>
#include "meerkat.h"
#include "cart.h"

using namespace std;

// Class definition for a cart
class cart
{
    public:
        cart();
        bool addMeerkat(meerkat cat);
        void emptyCart();
        void printMeerkats();
        bool getCheck();
        ~cart();

    private:
        bool check_full;
        meerkat *Meerkat_Add;
};

#endif //CART_H
