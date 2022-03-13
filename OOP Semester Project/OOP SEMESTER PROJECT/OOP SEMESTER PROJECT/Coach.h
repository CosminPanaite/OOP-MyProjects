#pragma once
#include<cstring>
#include<string>
using namespace std;

#include"Staff.h"
class Coach :public Staff
{

protected:
	string tactics;
	

public:
	///A derived class from staff
	/// It inherits Staff's attributes
	/// It has 1 new param
	/// @param tactics means the plans for a game of a coach
	string getTactics()const {
		return this->tactics;
		
	}
	void setTactics(string newT)
	{
		tactics = newT;
	}
	Coach(); 
	Coach(string n, int tr, int med, int w,string tactics);
	~Coach();
	string toString();
};

