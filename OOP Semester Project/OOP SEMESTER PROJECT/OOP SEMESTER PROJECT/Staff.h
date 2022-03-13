#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Staff
{


protected:
	string name;
	int trophies;
	int medals;
	int wins;
	unsigned int ID;
	static unsigned int number;
public:
	/// A base class which has another 2 derived classes
	/// @param trophies is the number of throphies of a member
	/// @param wins is the number of throphies of a member
	/// @param medals is the  of throphies of a member
	/// @ID IS UNIQUE
	/// @see also getters/setters/operators / constructor and destructors
	Staff();
	Staff(string name, int trophies, int medals, int wins);

	virtual  string toString();
	virtual void setTrophies(int newTrophies)
	{
		this->trophies = newTrophies;
	}
	virtual void setMedals(int newMedals)
	{
		this->medals = newMedals;
	}
	virtual void setWins(int newWins)
	{
		this->wins = newWins;
	}
	virtual	void setName(string newName)
	{
		this->name = newName;
	}
	int getTrophies()const{
		return this->trophies;
	}
	int getMedals()const
	{
		return this->medals;
	}
	int getWins()const
	{
		return this->wins;
	}
	string getName()const {
		return this->name;
	}
	
	virtual ~Staff()=default;
	friend istream& operator >>(istream& ist, const Staff& s);
	bool operator ==(const Staff& s);
	friend istream& operator >>(istream& is, const Staff& s);
};

