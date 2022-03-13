#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ifstream f("dates.txt");
#include "UI.h"
#include"Controller.h";

UI::UI(Controller& ctrl)
{
	this->ctrl = ctrl;
}
void UI::displayAll()
{
	for (Staff* s : ctrl.getAllData())
		cout << s->toString()<<" "<<endl;
}
void UI::readForAdd() {
	string name;
	int trophies, medals, wins, goals, rating;
	string tactics;
	string type;
	cout << "Give type:" << endl;
	cin >> type;
	cout << "Give name:" << endl;
	cin >> name;
	cout << "Give medals:" << endl;
	cin >> medals;
	cout << "Give wins:" << endl;
	cin >> wins;
	cout << "Give goals:" << endl;
	cin >> goals;
	cout << "Give rating:" << endl;
	cin >> rating;
	cout << "Give tactics:" << endl;
	cin >> tactics;
	cout << "Give trophies:" << endl;
	cin >> trophies;
	ctrl.addStaffMember(name, trophies, medals, wins, goals, rating, tactics, type);
}
void UI::addFromFile() {

}
void UI::saveInFile()
{
	Repository repo;
	vector<Staff*> allObjects = repo.getAllData();

	string fileName = "data.out.txt";

	ofstream out(fileName);

	for (Staff* s : allObjects) {
		string stringVehicle = s->toString();
		out << stringVehicle;

	}cout << "Saved in a new file! " << endl;

}

void UI::showMenu()
{
	cout << "MY MENU OF FUNCTIONS: \n";
	cout << "1. Display all staff members: \n";
	cout << "2. Add a staff member \n";
	cout << "3. Remove a staff member\n";
	cout << "4. Print vehicles from a given year\n";
	cout << "5. Save staff members  to a file\n";
	cout << "6. Load data into repository from a file\n";
	cout << "7. Edit(Update) staff  by goals\n";
	cout << "0. Exit\n";
	cout << ">>";
}

void UI::runConsole()
{
	while (true)
	{
		showMenu();
		int option;
		cin >> option;
		if (option == 1)
		{
			displayAll();
		}
		else if (option == 2)
		{	
			readForAdd();
		}
		else if (option == 3)
		{
			//addFromFile();
		}

		else {
			cout << "Voila! This is the end!";
			break;
		}
	}
}