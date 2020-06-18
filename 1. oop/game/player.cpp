#include <iostream>
#include <string>
#include <stdlib.h>

#include "player.h"
#include "item.h"
#include "creature.h"

using namespace std;

int player::counter_Equipment = 0;
int player::counter_Inventory = 0;

//implementation of constructor 
player::player(){
	hp = 500;
	maxHP =500;
	bool alive = true;
	
	force = 50;
	maxForce = 50;
	
	int atk=1;
  	int	def=1;

  	int	speed=1;
 	int	range=1;

  	points = 0;
	coins = 0;

	num_Equipment = 3; 
	currentEquipment = new item[num_Equipment];

	for(int i = 0; i < num_Equipment; i++){
		currentEquipment[i] = empty;
	}

	num_Inventory = 7;
	currentInventory = new item[num_Inventory];

	for(int i = 0; i < num_Inventory; i++){
		currentInventory[i] = empty;
	}
}

int player::getHP(){
	return hp;
}

void player::setHP(int h){
	hp = h;
}

int player::getMaxHP(){
	return maxHP;
}

void player::setMaxHP(int mh){
	maxHP = mh;
}

int player::getForce(){
	return force;
}

void player::setForce(int f){
	force = f;
}

int player::getMaxForce(){
	return maxForce;
}

void player::setMaxForce(int mf){
	maxForce = mf;
}

int player::atack (weapon current, creature enemy){
	atk = (force + current.getDamage()) - enemy.getDef();
	return atk;
}

void player::takeDamage(armor current, int damage){
	def = current.getDefence();
	hp = (hp + def) - damage;

	if (hp <= 0){
		alive = false;
	}
}

int player::getSpeed(){
	return speed;
}

void player::setSpeed(int s){
	speed = s;
}

int	player::getRange(){
	return range;
}

void player::setRange(int r){
	range = r;
}

int player::getPoints(){
	return points;
}

void player::setPoints(int p){
	points = p;
}

int player::getCoins(){
	return coins;
}

void player::setCoins(int c){
	coins = c;
}

void player::setNum_Equipment(int E){
	num_Equipment = E;
}

void player::setNum_Inventory(int I){
	num_Inventory = I;
}

void player::AddEquipment(item newEquipment){
	if (counter_Equipment < num_Equipment){
		currentEquipment[counter_Equipment] = newEquipment;
		counter_Equipment++; 
	}
	else{
		counter_Equipment = 0;
		currentEquipment[counter_Equipment] = newEquipment;
	}
}

void player::ChangeEquipment(item newEquipment, int PosEquipment){
	if (PosEquipment < num_Equipment){
		currentEquipment[PosEquipment] = newEquipment;
	}
}

void player::EmptyEquipment(int PosEquipment){
	if (PosEquipment < num_Equipment){
		currentEquipment[PosEquipment] = empty;
	}
}

void player::PrintCurrentEquipment(){
	for(int i = 0; i < num_Equipment; i++){
		cout << currentEquipment[i].getName() << ", ";
		cout << currentEquipment[i].getType() << endl;
	}
}

item player::GetPosEquipment(int PosEquipment){
 	if (PosEquipment < num_Equipment){
 		return currentEquipment[PosEquipment];
 	}
 	else{
 		return currentEquipment[num_Equipment];
 	}
}

void player::AddInventory(item newInventory){
	if (counter_Inventory < num_Inventory){
		currentInventory[counter_Inventory] = newInventory;
		counter_Inventory++;
	}
	else{
		counter_Inventory = 0;
		currentInventory[counter_Inventory] = newInventory;
	}
}

void player::ChangeInventory(item newInventory, int PosInventory){
	if (PosInventory < num_Inventory){
		currentInventory[PosInventory] = newInventory;
	}
}

void player::EmptyInventory(int PosInventory){
	if (PosInventory < num_Inventory){
		currentInventory[PosInventory] = empty;
	}
}

void player::PrintCurrentInventory(){
	for(int i = 0; i < num_Inventory; i++){
		cout << currentInventory[i].getName() << ", ";
		cout << currentInventory[i].getType() << endl;
	}
}

item player::GetPosInventory(int PosInventory){
 	if (PosInventory < num_Inventory){
 		return currentInventory[PosInventory];
 	}
	else{
		return currentInventory[num_Inventory];
	}
}

player::~player(){}



