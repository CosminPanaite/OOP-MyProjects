#include "FieldPlayer.h"
#include<iostream>
#include<string>
using namespace std;
FieldPlayer::FieldPlayer(string name, int trophies, int medals, int wins,int goals, int rating):Staff( name,  trophies,  medals,  wins) {
	this->goals = goals;
	this->rating = rating;
}
FieldPlayer::FieldPlayer():Staff()
{
	this->goals = 0;
	this->rating = 0;
}
FieldPlayer::~FieldPlayer()
{

}
string FieldPlayer::toString()
{
	return Staff::toString() + " with a number of  " +to_string( this->goals)+" goals and rating " + to_string(this->rating) ;
}