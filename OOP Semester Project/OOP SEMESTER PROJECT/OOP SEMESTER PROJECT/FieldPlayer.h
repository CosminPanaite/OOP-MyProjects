#pragma once
#include"Staff.h"
#include<string>
enum  PlayerPositions {
	goalkeeper = 1, defender = 2, midfielder = 3, striker = 4
	
};
class FieldPlayer:public Staff
{
protected:
	int goals;
	int rating;
public:
	///A derived class from staff
	/// It inherits Staff's attributes
	/// It has 2 new paramas
	/// @param goals the goals scored by a player
	/// @param rating is the rating obtained by a player
	/// @see also getters/setters/operators / constructor and destructors
	FieldPlayer();
	inline int getGoals()const {
		return this->goals;
	}
	inline int getRating()const {
		return this->rating;
	}
	void setGoals(int newGoals) {
		this->goals = newGoals;

	}
	void setRating(int newRating) {
		this->rating=newRating;

	}
	string toString();
	FieldPlayer(string name, int trophies, int medals, int wins, int goals, int rating);
	~FieldPlayer();
	
};

