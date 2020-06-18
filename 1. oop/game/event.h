#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>

#include "creature.h"
#include "player.h"
#include "item.h"

using namespace std;

class event {
public:
	event();
	event(string terrain);
	event(string name, string type);
	
	string getEventType();
	void setEventType(string type);	
	string getEventName();	
	void setEventName(string name);
	virtual void eventBehaviour() = 0;
	
	//Gave me a warning when the virtual classes had the cout;
	virtual creature** getCreatureList() = 0; //{std::cout<<"No creatures here!\n";}; // virtual functions shouldn't be needed, but outside combat maybe?
	virtual int getNumberOfEnemies() = 0; //{std::cout<<"No creatures here!\n";};
	virtual void test(){std::cout<<"u fucked up\n";}; // dummy function i used for testing if it was managing pointers properly

	~event();

private:
	static bool check_action;
	string eventType;
	string eventName;
};

	class fight : public event
	{
	public:
		fight();
		fight(std::string terrain);
		void eventBehaviour() = 0;
		creature** getCreatureList();
		int getNumberOfEnemies();
		bool allDead();
		void test(){std::cout<<"Test\n";creatures[0]->setName("asfahsufi");};
		~fight();

	private:
		int numberOfEnemies;
		creature* creatures[5]; // maximum of 5 I guess
	};

	//Finding inventory subclass
	class inventory : public event
	{
	public:
		inventory(string name, string type, player gameplayer);
		void eventBehaviour();
		~inventory();
	
	private:
		long random;
		char y_n;
	};

	//Finding Equipment subclass
	class equipment : public event
	{
	public:
		equipment(string name, string type, player gameplayer);
		void eventBehaviour();
		~equipment();

	private:
		long random;
		char y_n;
		
	};

	//Getting money subclass
	class treasure : public event
	{
	public:
		treasure(string name, string type, player gameplayer);
		void eventBehaviour();
		~treasure();

	private:
		long random;		
	};

	//Getting experience and points subclass
	class experience : public event
	{
		experience(string name, string type, player gameplayer);
		void eventBehaviour();
		~experience();

	private:
		long random;	
	};


#endif // EVENT_H