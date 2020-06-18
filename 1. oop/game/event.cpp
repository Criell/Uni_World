#include <cstdlib>
#include <string>
#include <iostream>

//#include "location.h"
#include "creature.h"
#include "player.h"
#include "item.h"
#include "event.h"

using namespace std;

bool event::check_action = false;

event::event()
{
	eventType = "None";
	eventName = "None";
}

// event::event(string terrain) // event should only be used when the event needs no methods
// {
// 	// int r = rand() % 3 + 1;

// 	// if (terrain == "Plains") {
// 	// 	switch(r) {
// 	// 	case 1:
// 	// 		eventType = "Grass Fire";
// 	// 		break;
// 	// 	case 2:
// 	// 		eventType = "Wolfpack";
// 	// 		break;
// 	// 	case 3:
// 	// 		eventType = "Nothing";
// 	// 		break;
// 	// 	}
// 	// } else if (terrain == "Hills") {
// 	// 	switch(r) {
// 	// 	case 1:
// 	// 		eventType = "Rockslide";
// 	// 		break;
// 	// 	case 2:
// 	// 		eventType = "Bear";
// 	// 		break;
// 	// 	case 3:
// 	// 		eventType = "Nothing";
// 	// 		break;
// 	// 	}
// 	// } else if (terrain == "Desert") {
// 	// 	switch(r) {
// 	// 	case 1:
// 	// 		eventType = "Sandstorm";
// 	// 		break;
// 	// 	case 2:
// 	// 		eventType = "Snake";
// 	// 		break;
// 	// 	case 3:
// 	// 		eventType = "Nothing";
// 	// 		break;
// 	// 	}
// 	// }
// 	// else {
// 	// 	eventType = "Nothing";
// 	// }

// }

string event::getEventType(){
	return eventType;
}

void event::setEventType(string type){
	eventType = type;
}

string event::getEventName(){
	return eventName;
}
	
void event::setEventName(string name){
	eventName = name;
}

event::~event() {}



	fight::fight()
	{
		setEventType("Fight");
		numberOfEnemies = 1;
		creatures[0] = new creature("Wolf", 2, 8);
	}

	fight::fight(string terrain) : event() // eg so different types of enemies spawn in different numbers
	{
		setEventType("Fight");
		int xCoords[10];
		int yCoords[10];
		int random = rand()%6;

		if (random < 4)
		{
			numberOfEnemies = 2;

			for (int i = 0; i < numberOfEnemies; ++i)
			{
				xCoords[i] = (rand()%8)+4;
				yCoords[i] = (rand()%7);
			}

			while( ((xCoords[1]==xCoords[0]) && (yCoords[1]==yCoords[0])) )
			{
				xCoords[1] = (rand()%8)+4;
				yCoords[1] = (rand()%7);
			}

			creatures[0] = new creature( "Wolf", xCoords[0], yCoords[0] );
			creatures[1] = new creature( "Wolf", xCoords[1], yCoords[1] );
		}
		else
		{
			numberOfEnemies = 1;
			creatures[0] = new creature( "Wolf", (rand()%8)+4, (rand()%7) );
		}
	}

	creature** fight::getCreatureList()
	{
		return creatures;
	}

	int fight::getNumberOfEnemies()
	{
		return numberOfEnemies;
	}

	bool fight::allDead()
	{
		for (int i = 0; i < numberOfEnemies; ++i)
		{
			if ( (creatures[i]->isAlive()) )
			{
				return false;
			}
		}
		
		return true;

	}

	fight::~fight(){}




	// inventory::inventory(string name, string type, player gameplayer) : event(name, "inventory"){}

	// void inventory::eventBehaviour(){
	// 	// if (check_action == false){
	// 		random = rand()%70;
	// 	// 	if (random>=0 & ramdom <10)
	// 	// 		healing_herbs I1;
	// 	// 	else if  ((random>10) & (ramdom <20))
	// 	// 		poisons I1; 
	// 	// 	else if  ((random>20) & (ramdom <30))
	// 	// 		live_potions I1; 
	// 	// 	else if  ((random>30) & (ramdom <40))
	// 	// 		strength_potions I1; 
	// 	// 	else if  ((random>40) & (ramdom <50))
	// 	// 		wealth I1("money"); 
	// 	// 	else if  ((random>50) & (ramdom <60))
	// 	// 		increase_speed I1; 
	// 	// 	else if ((random>=70)
	// 	// 		Increase_range I1; 

	// 	// 	cout << "You find this item for your inventory:";
	// 	// 	cout << I1.getType() << endl; 
	// 	// 	cout << "Do you want to keep it? (y/n): ";
	// 	// 	cin >> y_n;

	// 	// 	if (y_n =='y'){
	// 	// 		gameplayer.AddInventory(I1);
	// 	// 		check_action == true;
	// 	// 	}	
	// 	// }
	// }

	inventory::~inventory(){}


	// equipment::equipment(string name, string type, player gameplayer): event(name, "equipment"){}
	
	// void equipment::eventBehaviour(){
	// 	// if (check_action == false){

	// 	 	random = rand()%40;

	// 	// 	if (random>=0 & ramdom <10)
	// 	// 		longsword E1;
	// 	// 	else if  ((random>10) & (ramdom <20))
	// 	// 		halberd E1; 
	// 	// 	else if  ((random>20) & (ramdom <30))
	// 	// 		dagger E1; 
	// 	// 	else if  ((random>30) & (ramdom <40))
	// 	// 		armor E1;  

	// 	// 	cout << "You find this item for your equipment:";
	// 	// 	cout << E1.getType() << endl; 
	// 	// 	cout << "Do you want to keep it? (y/n): ";
	// 	// 	cin >> y_n;

	// 	// 	if (y_n =='y'){
	// 	// 		gameplayer.AddEquipment(I1);
	// 	// 		check_action == true;
	// 	// 	}
	// 	// }
	// }
	
	 equipment::~equipment(){}
	

	// treasure::treasure(string name, string type, player gameplayer): event(name, "treasure"){}

	// void treasure::eventBehaviour(){
	// 	 random = rand()%1000;
	// 	// cout << "You find a treasure of coins. Value: " << random;
	// 	// gameplayer.setCoins(random); 
	// }
	
	// treasure::~treasure(){}


	// experience::experience(string name, string type, player gameplayer): event(name, "experience"){}

	// void experience::eventBehaviour(){
	// 	 random = rand()%1000;
	// 	// cout << "You got some experience. Points: " << random;
	// 	// gameplayer.setPoints(random); 
	// }
	
	 experience::~experience(){}




