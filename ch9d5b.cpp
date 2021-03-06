#include "std_lib_facilities.h"

enum class Month
{
 jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


Month returnMonth(int month);

class Date
{
public:
 Date(int y, Month m, int d);
 int day() const { return d; };  //const member: can't modify
 Month month() const { return m; }
 int year() const { return y; }

 void add_day(int n);
 void add_month(int n);
 void add_year(int n);

 bool lastDay = false;
 bool endYear = false;
private:
 int y;
 Month m;
 int d;
};


Date today(1978, Month::jun, 25);
Date tomorrow(today);

Date::Date(int y, Month m, int d)
{
 if (y < 1900 || y > 2022)
  cout << "Error, invalid year." << endl;
 else if (static_cast<int>(m) < 1 || static_cast<int>(m) > 12)
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
 //if day goes above 31, increase month, set day to 1
 //if month goes above 12, increase year, set month to 1
 for (int i = 0; i < n; ++i)
 {
  //wrap days
  if (Date::d == 31)
   lastDay = true;
  Date::d = (Date::d == 31) ? 1 : ++Date::d;  //if day is equal to 31, make it 1, otherwise ++

  if (lastDay)
  {
   //wrap month
   lastDay = false;
   int mon = (static_cast<int>(Date::m) == 12) ? 1 : (static_cast<int>(Date::m) + 1); //if month is equal to 12, make it 1, otherwise ++
   Date::m = returnMonth(mon);
   if (static_cast<int>(Date::m) == 12)
    endYear = true;

   if (endYear)
   {
    //just increase year by one
    endYear = false;
    ++Date::y;
   }

  }
  
 }
}

void Date::add_month(int n)
{
 for (int i = 0; i < n; ++i)
 {
  //if month is equal to 12, make it 1, otherwise ++
  int mon = (static_cast<int>(Date::m) == 12) ? 1 : (static_cast<int>(Date::m) + 1);
  Date::m = returnMonth(mon);
  if (static_cast<int>(Date::m) == 12)
   endYear = true;

  if (endYear)
  {
   //just increase year by one
   endYear = false;
   ++Date::y;
  }
 }
}

void Date::add_year(int n)
{
 for (int i = 0; i < n; ++i)
  ++Date::y;
}

//switch to return correct type of Month
Month returnMonth(int month)
{
 switch (month)
 {
 case 1:
  return Month::jan;
  break;
 case 2:
  return Month::feb;
  break;
 case 3:
  return Month::mar;
  break;
 case 4:
  return Month::apr;
  break;
 case 5:
  return Month::may;
  break;
 case 6:
  return Month::jun;
  break;
 case 7:
  return Month::jul;
  break;
 case 8:
  return Month::aug;
  break;
 case 9:
  return Month::sep;
  break;
 case 10:
  return Month::oct;
  break;
 case 11:
  return Month::nov;
  break;
 case 12:
  return Month::dec;
  break;
 default:
  cout << "Bad month" << endl;
 }
}

//print to screen
ostream& operator<<(ostream& os, Date& d)
{
 return os << d.day() << ", " << static_cast<int>(d.month()) << ", " << d.year() << endl;
}

int main()
{
 
 tomorrow.add_day(1);
 tomorrow.add_month(2);
 tomorrow.add_year(5);

 //print out results
 cout << "Today: " << today << endl;
 cout << "Tomorrow: " << tomorrow << endl;

 keep_window_open();

 return 0;
}

