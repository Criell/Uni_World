#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <curses.h>

#include "player.h"
#include "item.h"
#include "event.h"
#include "creature.h"



int main()
{
	int h = 0, mh = 0, f = 0, mf = 0, p = 500, c = 300;

	player gamePlayer;

	cout << gamePlayer.getHP() << endl;
	cout << gamePlayer.getMaxHP() << endl;
	cout << gamePlayer.getForce() << endl;
	cout << gamePlayer.getMaxForce() << endl;
	cout << gamePlayer.getPoints() << endl;
	cout << gamePlayer.getCoins() << endl;
	cout << endl;

	gamePlayer.setHP(h);
	gamePlayer.setMaxHP(mh);
	gamePlayer.setForce(f);
	gamePlayer.setMaxForce(mf);
	gamePlayer.setPoints(p);
	gamePlayer.setCoins(c);

	cout << gamePlayer.getHP() << endl;
	cout << gamePlayer.getMaxHP() << endl;
	cout << gamePlayer.getForce() << endl;
	cout << gamePlayer.getMaxForce() << endl;
	cout << gamePlayer.getPoints() << endl;
	cout << gamePlayer.getCoins() << endl;
	cout << endl;

	gamePlayer.PrintCurrentEquipment();
	cout << endl;
	gamePlayer.PrintCurrentInventory();
	cout << endl;

	
	healing_herbs i1; 
	poisons i2; 
	live_potions i3; 
	strength_potions i4; 
	wealth i5("money"); 
	increase_speed i6; 
	Increase_range i7; 
	wealth i8("treasure");

	gamePlayer.AddInventory(i1);
	gamePlayer.AddInventory(i2);
	gamePlayer.AddInventory(i3);
	gamePlayer.AddInventory(i4);
	gamePlayer.AddInventory(i5);
	gamePlayer.AddInventory(i6);
	gamePlayer.AddInventory(i7);
	gamePlayer.PrintCurrentInventory();
	cout << endl;

	gamePlayer.AddInventory(i8);
	gamePlayer.EmptyInventory(1);
	gamePlayer.ChangeInventory(i1, 2);
	gamePlayer.PrintCurrentInventory();
	cout << endl;	


	longsword e1; 
	halberd e2; 
	dagger e3;
	armor e4;

	gamePlayer.AddEquipment(e1);
	gamePlayer.AddEquipment(e2);
	gamePlayer.AddEquipment(e3);
	gamePlayer.PrintCurrentEquipment();
	cout << endl;

	gamePlayer.AddEquipment(e4);
	gamePlayer.EmptyEquipment(1);
	gamePlayer.ChangeEquipment(e1,2);
	
	gamePlayer.PrintCurrentEquipment();
 	cout << endl;
	
	item equipment [3] = {e1,e2,e3};
	item inventory [7] = {i1,i2,i3,i4,i5,i6,i7};

		
	
	return 0;
}