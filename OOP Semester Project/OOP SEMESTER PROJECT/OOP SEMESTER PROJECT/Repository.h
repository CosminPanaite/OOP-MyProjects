#pragma once
#include <vector>
#include "Staff.h"
#include <string>

class Repository
{
private:
    std::vector<Staff*> data;
    string fileNameIn;
    string fileNameOut;
public:
    Repository() = default;

    Repository(const string & fileNameIn, const string & fileNameOut);

    ~Repository() = default;

    vector<Staff*> getAllData() const;

    void addStaffMember(Staff * newStaff);

    void removeByName(string name);

    void EditElementByName(string name, int trophies, int goals, int wins);

    void loadFromFile();

    void saveToFile();

    int sizeRepo();
};
