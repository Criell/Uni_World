#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class creature {
public:
	creature();
	creature(std::string Name, int newXcoord, int newYcoord);
	~creature();
	void takeDamage(int damage);
	void setName(std::string Name);
	std::string getName();
	void setHp(int HP);
	int getHp();
	void setAtk(int ATK);
	int getAtk();
	void setDef(int DEF);
	int getDef();
	bool isAlive();
	int getID();

	virtual void move(int xChange, int yChange); // only for testing right now
	virtual bool takeTurn(int playerXcoord, int playerYcoord, creature** creature, int numberOfCreatures);
	int getXcoord();
	int getYcoord();
private:
	static int ID;
	int creatureID;
	std::string name;
	int hp;
	int atk;
	int def;
	int xCoord, yCoord;
	bool alive;
	int speed;
	int range;
};

#endif // CREATURE_H
