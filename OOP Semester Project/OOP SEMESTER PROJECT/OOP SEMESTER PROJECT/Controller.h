#pragma once
#include "Repository.h"
#include"Staff.h "
#include <string>
class Controller
{
private:
	Repository repo;
public:
	Controller()=default;
	Controller(Repository& repo);
	~Controller()=default;
	vector<Staff*> getAllData() const;
	void addStaffMember( string name,int trophies,int medals,int wins, int goals, int rating, string tactics,string type);
	void removeByGoals(int id);
	void EditElementByName(int newTrophies, int newWins, int newGoals);
	int sizeController();
};
