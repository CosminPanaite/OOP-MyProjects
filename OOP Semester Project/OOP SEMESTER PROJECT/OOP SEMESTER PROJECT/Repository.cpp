#include "Repository.h"
#include<vector>
#include"Staff.h"
#include "Coach.h"
#include "FieldPlayer.h"


/*
* add a new object to the vector
*/
void Repository::addStaffMember(Staff* newStaff) {

    this->data.push_back(newStaff);
    saveToFile();
}

/*
* get all elements from the repository which is a vector
*
*/
vector<Staff*> Repository::getAllData() const {
    return this->data;
}

Repository::Repository(const string& fileNameIn, const string& fileNameOut) {
    this->fileNameIn = fileNameIn;
    this->fileNameOut = fileNameOut;
    loadFromFile();
}

/*
* The update functions with the aid of the setters
*
*/
void Repository::EditElementByName(string name, int trophies, int medals, int wins) {
    for (Staff* s : this->data) // to go through directly my vector
    {
        if (s->getName() == name)
            s->setMedals(medals);
        s->setWins(wins);
        s->setTrophies(trophies);
    }

}

void Repository::loadFromFile() {
    ifstream f(fileNameIn);
    string line;
    string delimiter = ",";
    int position = 0;
    if (f.is_open()) {
        while (getline(f, line)) {
            position = line.find(delimiter); /// the first position of the comma in the line

            string type = line.substr(0, position); /// I copy the type of the Staff Object
            line = line.erase(0, position + 1);
            if (type == "Coach") {
                Staff* staff = nullptr;
                position = line.find(delimiter);
                string name = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                int trophies = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                int medals = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                int wins = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string tactics = line;
                line = line.erase(0, position + 1);

                staff = new Coach(name, trophies, medals, wins, tactics);
                data.push_back(staff);


            }
            else if (type == "Field Player") {
                Staff* staff = nullptr;
                position = line.find(delimiter);
                string name = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                int trophies = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                int medals = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                int wins = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                int goals = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                int rating = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);


                staff = new FieldPlayer(name, trophies, medals, wins, goals, rating);
                data.push_back(staff);
            }
        }
    }
    f.close();
}


/*
* here is removing by ID
*/
void Repository::removeByName(string name) {
    int pos = -1;
    for (int i = 0; i < data.size() && pos == -1; i++) // to go through directly my vector
    {
        if (data[i]->getName() == name) {
            pos = i;


        }

    }
    if (pos != -1) {
        data.erase(data.begin() + pos);
    }
}

/*
* size for repository
*/
int Repository::sizeRepo() {
    return data.size();

}


void Repository::saveToFile() {
    ofstream g(fileNameOut);
    if (g.is_open()) {
        for (Staff* staff : getAllData())
            g << staff->toString() << endl;
    }
    g.close();
}