#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "creature.h"

using namespace std;

// methods and attributes of this class should be mostly virtual, as subclasses should define what an item can do
// (apart from maybe throwAway, not pickUp however, as it should be related to event or location)

class player;

class item
{		   
public:
	item();
	item(string Name, string Type);
	void printItemDetails();
	string getType();
	string getName();
	~item();

private:
	string itemName;
	string itemType;
	static int ID;
	int id;
};


// weapon subclass
	class weapon : public item
	{
	public:
		weapon(string name);
		int getDamage();
		void setDamage(int d);
		virtual void useWeapon() = 0;
		~weapon();

	private:
		int damage;
			
	};

	// weapon types
		class longsword : public weapon
		{
		public:
			longsword();
			void useWeapon();
			~longsword();
		};

		class halberd : public weapon
		{
		public:
			halberd();
			void useWeapon();
			~halberd();
		};

		class dagger : public weapon
		{
		public:
			dagger();
			void useWeapon();
			~dagger();
		};


// armor subclass
	class armor : public item
	{
	public:
		armor();
		int getDefence();
		~armor();

	private:
		int def;
	};


// inventory subclass
	class healing_herbs : public item{
	public:
		healing_herbs();	
		void item_use(player gamePlayer, int heal);
		~healing_herbs();
	};
			
	class poisons : public item{
	public:
		poisons();
		void item_use(player gamePlayer,int hurt);
		~poisons();
	};

	class live_potions : public item{
	public:
		live_potions();
		void item_use(player gamePlayer);
		~live_potions();
	};	

	class strength_potions : public item{
	public:
		strength_potions();
		void item_use(player gamePlayer);
		~strength_potions();
	};	

	class increase_speed : public item{
	public:
		increase_speed();
		void item_use(player gamePlayer, int fast);
		~increase_speed();
	};	 
	
	class Increase_range : public item{
	public:
		Increase_range();
		void item_use(player gamePlayer, int space);
		~Increase_range();
	};	

	class wealth : public item{	
	public:
		wealth(string name); 
		void item_use(player gamePlayer,int money);
		~wealth();
	};

#endif //ITEM