#include "std_lib_facilities.h"


struct Date
{
 int y;  //year
 int m;  //month
 int d;  //day
};

Date today;
Date tomorrow;


void init_day(Date& dd, int y, int m, int d)
{
 if (y < 1900 || y > 2022)
  cout << "Error, invalid year." << endl;
 else if (m < 1 || m > 12)
  cout << "Error, invalid month." << endl;
 else if (d < 1 || d > 31)
  cout << "Error, invalid day." << endl;
 else
 {
  dd.y = y;
  dd.m = m;
  dd.d = d;
 }

 return;
}

//increment date by n days
void add_day(Date date, Date& dd_copy, int n)
{
date.d += n;
 if (date.d > 31){
		date.m++;
		date.d -= 31;
		if(date.m > 12){
			date.y++;
			date.m -=12;
		}
	}

 //assign tomorrow with copy of modified today
 dd_copy = date;
}

//print to screen
ostream& operator<<(ostream& os, const Date& d)
{
 return os << d.d << ", " << d.m << ", " << d.y << endl;
}

int main()
{
 //initialise today with June 25 1978
 init_day(today, 1978, 6, 25);

 //assign by copying and increase by 1 day
 add_day(today, tomorrow, 1);

 //print out results
 cout << "Today: " << today << endl;
 cout << "Tomorrow: " << tomorrow << endl;

 keep_window_open();

 return 0;
}
