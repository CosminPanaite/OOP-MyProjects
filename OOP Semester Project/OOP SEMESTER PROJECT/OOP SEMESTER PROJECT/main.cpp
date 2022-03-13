#include<iostream>
#include"UI.h"
#include"Repository.h"
#include"Controller.h"
#include"TestClasses.h"

using namespace std;

int main() {
    TestClasses testClasses;
    testClasses.runAll();

    Repository repo("D:\\OOP Semester Project\\OOP SEMESTER PROJECT\\OOP SEMESTER PROJECT\\Text_in.txt","D:\\OOP Semester Project\\OOP SEMESTER PROJECT\\OOP SEMESTER PROJECT\\Text_out.txt");
    Controller ctrl(repo);
    UI ui(ctrl);
    ui.runConsole();
}