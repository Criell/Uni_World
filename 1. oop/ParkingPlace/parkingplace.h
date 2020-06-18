#ifndef PARKINGPLACE_H
#define PARKINGPLACE_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class ParkingPlace
{
	public:
		ParkingPlace(string o, string a, string t, string v);
		void setOwner(string o);
		string getOwner();
		string getAddress();
		string getType();
		string getVehicleType();
		void setPrice(int p);
		int getPrice();
		~ParkingPlace();

	protected:
		string owner;
		string address;
		string type;
		string vehicle_type;

	private:
		int price;
		static bool nextFree;
};

#endif //PARKINGPLACE_H

