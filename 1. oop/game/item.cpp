#include <iostream>
#include <string>

//#include "function.h"
#include "item.h"
#include "player.h"
#include "creature.h"

using namespace std;

int item::ID = 0;

item::item() { 
	itemName = "Empty";
	itemType = "Item";
	id = ID;
	ID++;
}

//  later on, default item constructor should'nt be used directly
item::item(string Name, string Type){
	itemName = Name;
	itemType = Type;
	id = ID;
	ID++;
}

void item::printItemDetails()
{
	//std::cout << "You have " << aOrAn(itemType) << itemType << std::endl;
	std::cout << "ID " << id << std::endl;
}

string item::getType(){
	return itemType;
}

string item::getName(){
	return itemName;
}

// should only be used when item is irretrievable
item::~item(){}


	//Implementacion of child class weapon
	weapon::weapon(string name): item(name, "weapon"){
		damage = 1;
	}

	int weapon::getDamage(){
		return damage;
	}

	void weapon::setDamage(int d){
		damage = d;
	}

	weapon::~weapon(){}


		//Implementacion of child subclass
		longsword::longsword(): weapon("longsword"){}

		void longsword::useWeapon(){
			setDamage(4);
		}

		longsword::~longsword(){}


		//Implementacion of child subclass
		halberd::halberd(): weapon("halberd"){}

		void halberd::useWeapon(){
			setDamage(3);
		}

		halberd::~halberd(){}


		//Implementacion of child subclass
		dagger::dagger(): weapon("dagger"){

		}

		void dagger::useWeapon(){

			setDamage(2);
		}

		dagger::~dagger(){}




	//Implementacion of child class armor
	armor::armor(): item("armor", "item"){
		def = 2;
	}

	int armor::getDefence(){
		return def;
	}

	armor::~armor(){}



	//HealPlayer
	healing_herbs::healing_herbs(): item ("healing_herbs", "item"){

	}

	void healing_herbs::item_use(player gamePlayer, int heal){
		gamePlayer.setHP(gamePlayer.getHP() + 100);
		if (gamePlayer.getMaxHP() < gamePlayer.getHP()){
			gamePlayer.setHP(gamePlayer.getMaxHP());
		}
	}

	healing_herbs::~healing_herbs(){}


	//HurtPlayer
	poisons::poisons(): item("poisons", "item"){}

	void poisons::item_use(player gamePlayer,int hurt){
		gamePlayer.setHP(gamePlayer.getHP() - 100);
		if (gamePlayer.getHP() < 1){
			gamePlayer.~player();
		}
	}

	poisons::~poisons(){}


	//IncreaseHealth
	live_potions::live_potions(): item("live-potions", "item"){}
	
	void live_potions::item_use(player gamePlayer){
		if (gamePlayer.getPoints() == gamePlayer.getMaxHP() * 2){
			gamePlayer.setMaxHP(gamePlayer.getMaxHP() + 100);
		}
	}

	live_potions::~live_potions(){}
	

	//IncreaseForce
	strength_potions::strength_potions(): item("strength-potions", "item"){}
	
	void strength_potions::item_use(player gamePlayer){
		if (gamePlayer.getPoints() == gamePlayer.getMaxForce() * 2){
			gamePlayer.setMaxForce(gamePlayer.getMaxForce() + 100);
		}
	}
	
	strength_potions::~strength_potions(){}
	

	increase_speed::increase_speed(): item("increase-speed", "item"){}
	
	void increase_speed::item_use(player gamePlayer, int fast){
		gamePlayer.setSpeed(gamePlayer.getSpeed() + fast);
	}
	
	increase_speed::~increase_speed(){}
	

	Increase_range::Increase_range(): item("Increase-range", "item"){}
	
	void Increase_range::item_use(player gamePlayer, int space){
		gamePlayer.setRange(gamePlayer.getRange() + space);
	}
	
	Increase_range::~Increase_range(){}


	//IncreaseWealth
	wealth::wealth(string name): item(name, "item"){}
	
	void wealth::item_use(player gamePlayer, int money){
		gamePlayer.setCoins(gamePlayer.getCoins() + money);
	}
	
	wealth::~wealth(){}






