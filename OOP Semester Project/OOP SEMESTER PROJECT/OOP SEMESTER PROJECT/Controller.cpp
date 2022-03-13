#include "Controller.h"
#include"FieldPlayer.h"
#include"Coach.h"
using namespace std;

Controller::Controller(Repository& repo)
{
	this->repo = repo;
}
vector<Staff*>Controller:: getAllData() const
{
	return repo.getAllData();
}
void Controller::addStaffMember( string name, int trophies, int medals, int wins, int goals,int rating,string tactics ,string type)
{	Staff* newStaffObject = nullptr;
	if (type == "FieldPlayer")
	{

		newStaffObject = new FieldPlayer( name,  trophies,  medals,  wins,  goals,  rating);
			
	}
	else if (type == "Coach")
	{
		newStaffObject = new Coach(name, trophies, medals, wins,tactics);
		
	}

	this->repo.addStaffMember(newStaffObject);
}
int Controller::sizeController()
{
	return repo.sizeRepo();
}