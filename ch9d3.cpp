#include "std_lib_facilities.h"

class Date
{
private:
 int y, m, d;
public:
 Date(int y, int m, int d);
 void add_day(int n);

 int month() { return m; }
 int day() { return d; }
 int year() { return y; }
};

//intialise dates
Date today(1978, 6, 25);
Date tomorrow(today);

//Date Constructor
Date::Date(int y, int m, int d)
{
 if (y < 1900 || y > 2022)
  cout << "Error, invalid year." << endl;
 else if (m < 1 || m > 12)
  cout << "Error, invalid month." << endl;
 else if (d < 1 || d > 31)
  cout << "Error, invalid day." << endl;
 else
 {
  Date::y = y;
  Date::m = m;
  Date::d = d;
 }

 return;
}

//increment date by n days
void Date::add_day(int n)
{

Date::d += n;

	if (Date::d > 31){
		Date::m++;
		Date::d -= 31;
		if(Date::m > 12){
			Date::y++;
			Date::m -=12;
		}
	}
 
  
}

//print to screen
ostream& operator<<(ostream& os, Date& d)
{
 return os << d.day() << ", " << d.month() << ", " << d.year() << endl;
}

int main()
{
 //increase day by one
 tomorrow.add_day(1);

 //print out results
 cout << "Today: " << today << endl;
 cout << "Tomorrow: " << tomorrow << endl;

 keep_window_open();

 return 0;
}

