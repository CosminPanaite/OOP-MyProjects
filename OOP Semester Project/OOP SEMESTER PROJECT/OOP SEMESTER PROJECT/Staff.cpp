#include"Staff.h";
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
unsigned int Staff::number = 0;
Staff::Staff()
{
	this->name = "";
	this->trophies = 0;
	this->medals = 0;
	this->wins = 0;
}
Staff::Staff(string name, int trophies, int medals, int wins)
{
	number++;
	this->ID = number;
	this->name = name;
	this->trophies = trophies;
	this->medals = medals;
	this->wins = wins;

}

string Staff::toString()
{
	return "A staff member with " + this->name+" with "+ to_string(this->trophies) +" trophies , " + to_string(this->medals) + " medals and "+ to_string(this->wins)+ " wins" ;
}


