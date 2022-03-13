#include "Request.h"



Request::Request()
{
    this->loger.log("Default constructor");

}



Request::Request(int id, int price, char subject, bool status)
{
}



int Request::get_id()
{
    return this->id;
}



int Request::get_price()
{
    return this->price;
}



char Request::get_subject()
{
    return this->subject;
}



bool Request::get_status()
{
    return this->status;
}