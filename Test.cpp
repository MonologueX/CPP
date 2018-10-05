#include <iostream>
#include <windows.h>
using namespace std;

class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour)
		, _minute(minute) 
		, _second(second)
	{
		cout << "Time()" << endl;
	}

	Time(const Time& t)
	{
		cout << "Time(const Time& t)" << endl;
	}
	Time& operator=(const Time& t)
	{
		cout << "Time& operator=(const Time& t)" << endl;
		return *this;
	}
private:
	int _hour;
	int _minute;
	int _second;
	
};
class Date
{
public:
	Date(int year, int month, int day, const Time& t)
	{
		_year = year;
		_month = month;
		_day = day;
		_t = t;
	}

	//Date(int year, int month, int day, const Time& t)
	//	: _year(year)
	//	, _month(month)
	//	, _day(day) 
	//	, _t(t)
	//{

	//}
protected:
	int _year;
	int _month;
	int _day;
	Time _t;
};


int main()
{
	Time t(0, 0, 0);
	Date d1(2018, 9, 6, t);
	system("pause");
	return 0;
}