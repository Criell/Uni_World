#include <iostream>
#include <string>
#include <cmath>

#include "creature.h"
//#include "location.h"

using namespace std;

int creature::ID = 0;

creature::creature() // testing only
{
	// name = "";
	// hp = 0;
	// atk = 0;
	// def = 0;
	// xCoord = 0;
	// yCoord = 0;
	// alive = false;
}

creature::creature(std::string Name, int newXcoord, int newYcoord) {
	name = Name;
	if (name == "Wolf")
	{
		hp = 12;
		atk = 3;
		def = 1;
		alive = true;
		speed = 1;
		range = 1;
	}
	else
	{
		hp = 0;
		atk = 0;
		def = 0;
		alive = false;
		speed = 1;
		range = 1;
	}
	creatureID = ID++;
	xCoord = newXcoord;
	yCoord = newYcoord;
}

creature::~creature() {

}

void creature::takeDamage(int damage)
{
	int afterDefence;
	if ((damage-def)<0)
	{
		afterDefence = 1;
	}
	else
	{
		afterDefence = (damage-def);
	}

	if ( (hp - afterDefence) <= 0 )
	{
		hp = 0;
		alive = false;
	}
	else
	{
		hp -= afterDefence;
	}
}
void creature::setName(std::string Name) {
	name = Name;
}

std::string creature::getName() {
	return name;
}

void creature::setHp(int HP) {
	hp = HP;
}

int creature::getHp() {
	return hp;
}

void creature::setAtk(int ATK) {
	atk = ATK;
}

int creature::getAtk() {
	return atk;
}

void creature::setDef(int DEF) {
	def = DEF;
}

int creature::getDef() {
	return def;
}

void creature::move(int xChange, int yChange)
{
	if ((xCoord + xChange) > 11) // 0 to 8
	{
		xCoord = 11;
	}
	else if ((xCoord + xChange) < 0)
	{
		xCoord = 0;
	}
	else
	{
		xCoord += xChange;
	}

	if ((yCoord + yChange) > 6) // 0 to 4
	{
		yCoord = 6;
	}
	else if ((yCoord + yChange) < 0)
	{
		yCoord = 0;
	}
	else
	{
		yCoord += yChange;
	}
}

bool creature::takeTurn(int playerXcoord, int playerYcoord, creature** creatures, int numberOfCreatures)
{
	int possibleNewX, possibleNewY; // to check if move is valid
	bool validMove = true; // if no move is valid, they will not take an action

	// melee unit AI
	for (int i = 1; i <= speed; ++i)
	{
		// checks if is inline with the player, and within range on that line
		if (  ( (abs(playerXcoord-xCoord) <= range) && (playerYcoord-yCoord == 0) )  ||  ( (abs(playerYcoord-yCoord) <= range) && (playerXcoord-xCoord == 0) )  )
		{
			if ( i == speed ) // only attack on last move
			{
				// do attack
			}
		}
		else
		{

			if (abs(playerXcoord-xCoord) >= abs(playerYcoord-yCoord))
			{
				if ( (playerXcoord-xCoord) != 0 )
				{
					possibleNewX = xCoord + (  (playerXcoord-xCoord) / (abs(playerXcoord-xCoord))  ); // xCoord + unit vector in direction towards player
				}
				else	
				{
					validMove = false;
				}
				
				for (int i = 0; i < numberOfCreatures; ++i)
				{
					if (  (creatures[i]->getXcoord() == possibleNewX) && (creatures[i]->getYcoord() == yCoord)  )
					{
						validMove =  false;
					}
				}

				if (validMove)
				{
					xCoord = possibleNewX;
					return true;
				}
				else
				{
					if ( (playerYcoord-yCoord) != 0 )
					{
						possibleNewY = yCoord + (  (playerYcoord-yCoord) / (abs(playerYcoord-yCoord))  ); // yCoord + unit vector in direction towards player
					}
					else	
					{
						return false;
					}

					for (int i = 0; i < numberOfCreatures; ++i)
					{
						if (  (creatures[i]->getYcoord() == possibleNewY) && (creatures[i]->getXcoord() == xCoord)  )
						{
							return false;
						}
					}
					yCoord = possibleNewY;
					return true;
				} // if first move is possible, then whether second move is possible - does neither if neither are

			}
			else
			{
				if ( (playerYcoord-yCoord) != 0 )
				{
					possibleNewY = yCoord + (  (playerYcoord-yCoord) / (abs(playerYcoord-yCoord))  ); // yCoord + unit vector in direction towards player
				}
				else	
				{
					validMove = false;
				}

				for (int i = 0; i < numberOfCreatures; ++i)
				{
					if (  (creatures[i]->getYcoord() == possibleNewY) && (creatures[i]->getXcoord() == xCoord)  )
					{
						validMove =  false;
					}
				}
				if (validMove)
				{
					yCoord = possibleNewY;
					return true;
				}
				else
				{
					if ( (playerXcoord-xCoord) != 0 )
					{
						possibleNewX = xCoord + (  (playerXcoord-xCoord) / (abs(playerXcoord-xCoord))  ); // xCoord + unit vector in direction towards player
					}
					else	
					{
						return false;
					}

					for (int i = 0; i < numberOfCreatures; ++i)
					{
						if (  (creatures[i]->getXcoord() == possibleNewX) && (creatures[i]->getYcoord() == yCoord)  )
						{
							return false;
						}
					}
					xCoord = possibleNewX;
					return true;
				} // if first move is possible, then whether second move is possible - does neither if neither are

			} // whether x or y is closer

		} // if/else for if attack is possible
	} // for i<=speed loop
	return false;
}

int creature::getID()
{
	return creatureID;
}

int creature::getXcoord()
{
	return xCoord;
}

int creature::getYcoord()
{
	return yCoord;
}

bool creature::isAlive()
{
	return alive;
}