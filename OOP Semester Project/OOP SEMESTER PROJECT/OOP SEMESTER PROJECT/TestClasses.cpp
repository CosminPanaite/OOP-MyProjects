#include "TestClasses.h"
#include<assert.h>
#include"Coach.h";
#include"Controller.h";
#include"FieldPlayer.h";
#include"Staff.h";
#include"Repository.h";
#include<string>
using namespace std;

void TestClasses::testClasses() {
    Staff staff("Mourinho", 23, 42, 1000);
    Staff staff2("Flick", 6, 7, 95);
    Staff stafff3("Guardiola", 33, 52, 1203);
    FieldPlayer player1("Deco", 10, 14, 403, 100, 9);
    FieldPlayer player2("Drogba", 30, 44, 903, 800, 10);
    Coach c1("Nagelsman", 2, 3, 199, "Counter-Attack");
    assert(c1.getName() == "Nagelsman");
    assert(c1.getWins() == 199);
    assert(c1.getTactics() == "Counter-Attack");
    assert(c1.getTrophies() == 2);
    staff.setMedals(43);
    assert(staff.getMedals() == 43);
    staff.setMedals(43);
    assert(staff.getMedals() == 43);
    staff2.setMedals(10);
    assert(staff2.getMedals() == 10);
    assert(player2.getGoals() == 800);
    assert(player2.getWins() == 903);
    player2.setGoals(801);
    player2.setGoals(802);
    player2.setGoals(803);
    player2.setGoals(804);
    assert(player2.getGoals() == 804);
}

void TestClasses::testRepo() {
    Staff* newStaff = nullptr;
    Staff* newStaff2 = nullptr;
    Staff* newStaff3 = nullptr;
    newStaff = new Staff("Dany", 20, 21, 201);
    newStaff->setName("Dany");
    newStaff->setTrophies(20);
    newStaff->setWins(201);
    newStaff->setMedals(23);
    newStaff = new Coach("Dany", 20, 21, 201, "Counter Attack");
    Repository repo;
    repo.addStaffMember(newStaff);
    assert(repo.sizeRepo() == 1);
    repo.addStaffMember(newStaff2);
    assert(repo.sizeRepo() == 2);
}


void TestClasses::testCtrl() {
    Controller ctrl;
    ctrl.addStaffMember("Dave", 23, 30, 500, 604, 10, "counter-attack", "Coach");
    assert(ctrl.sizeController() == 1);
}

void TestClasses::runAll() {
    testClasses();
    testRepo();
    testCtrl();
    cout << "All tests have passed successfully!" << endl << endl;

}