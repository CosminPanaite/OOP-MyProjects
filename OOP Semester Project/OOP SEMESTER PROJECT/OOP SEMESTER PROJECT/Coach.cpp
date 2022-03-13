#include "Coach.h"
Coach::Coach() :Staff()
{
	this->tactics = "";
}
Coach::~Coach() {

}
Coach::Coach(string n, int tr, int med, int w, string tactics) :Staff(n, tr, med, w) {
	
	this->tactics = tactics;
}
string Coach::toString() {
	return Staff::toString() + " with tactics " + this->tactics;
}