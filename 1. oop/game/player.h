#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <stdlib.h>

#include "item.h"
#include "creature.h"

using namespace std;

class player 
{

public:
	
	player();
	
	//Declaration of the get and set of the privated variables
	int getHP();
	void setHP(int h);
	
	int getMaxHP();
	void setMaxHP(int mh);

	int getForce();
	void setForce(int f);

	int getMaxForce();
	void setMaxForce(int mf);

	int atack (weapon current, creature enemy);
	void takeDamage(armor current, int damage);

	int	getSpeed();
	void setSpeed(int s);
		
	int	getRange();
	void setRange(int r);

	int getPoints();
	void setPoints(int p);

	int getCoins();
	void setCoins(int c);
	
	void setNum_Equipment(int E);
	void setNum_Inventory(int I);

	//Declaration of the funtion that add equiment items to the array currentEquiament in player
	//using a variable as a counter from 0 to the lenght of the array (3)
	void AddEquipment(item newEquipment);
	//Change 1 item of 1 position of the array currentEquiament in player
	void ChangeEquipment(item newEquipment, int PosEquipment);
	//Empty 1 space of 1 position of the array currentEquiament in player
	void EmptyEquipment(int PosEquipment);
	//Print the current items of the array currentEquiament in player
	void PrintCurrentEquipment();
	//Return the item of the array currentEquiament in player located in the position given
	item GetPosEquipment(int PosEquipment);
	
	//Declaration of the funtion that add inventary items to the array currentInventary in 
	//using a variable as a counter from 0 to the lenght of the array (7)
	void AddInventory(item newInventory);
	//Change 1 item of 1 position of the array currentInventory in player
	void ChangeInventory(item newInventory, int PosInventory);
	//Print the current items of the array currentInventory in player
	void EmptyInventory(int PosInventory);
	//Print the current items of the array currentInventory in player
	void PrintCurrentInventory();
	//Return the item of the array currentInventory in player located in the position given
	item GetPosInventory(int PosInventory);

	~player();

private:
	//health
	int hp;
	int maxHP;
	bool alive;

	//fight
	int force;
	int maxForce;
	
	int atk;
  	int	def;

  	int	speed;
 	int	range;

  	//event
	int points;
	int coins;

	//keep track of the current position in the array
	int num_Equipment; 
	item *currentEquipment;
	static int counter_Equipment;
	//keep track of the current position in the array

	int num_Inventory;
	item *currentInventory;
	static int counter_Inventory;

	item empty;
};

#endif // PLAYER_H
