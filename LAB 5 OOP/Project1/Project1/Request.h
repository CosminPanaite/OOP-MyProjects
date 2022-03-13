#pragma once
#include <string>



struct date {
    int year;
    int month;
    int day;
};




class Request
{
protected:



    int id;
    int price;
    char subject;
    bool status;
    date the_date;
    Logger loger;
    std::string url;



protected:
    std::string url;



public:
    Request();
    Request(int id, int price, char subject, bool status);



    int get_id();
    int get_price();
    char get_subject();
    bool get_status();




};
