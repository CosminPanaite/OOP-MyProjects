#include"Logger.h"
#include"Request.h"
#include"OnlineSesion.h"
#include"ScreenLogger"

int main()
{
	OnlineSession s;
	ScreenLogger l;
	s.set_logger(l);

}