#pragma once
#include<iostream>
#include<cstring>
#include"Controller.h"

class UI
{
private:
	Controller ctrl;
	void showMenu();
	
	void displayAll();
	void readForAdd();
	void addFromFile();
	void saveInFile();
public:
	
	UI()=default;
	UI(Controller &ctrl); // we give an adress of an object
	~UI()=default;

	void runConsole();
};
