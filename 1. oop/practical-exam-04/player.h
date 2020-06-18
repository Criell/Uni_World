#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Player : public Person
{
public:
	Player(string n, int sl, int *list, int m);
	int searchGame(int x);
	int get_salary();
	~Player();

private:
	static int nextID;
	int *list_times;
	int number_games;

};

#endif //PLAYER_H