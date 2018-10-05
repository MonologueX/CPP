#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Data
{
public:
	Data()
	{
		_year = 1970;
		_month = 1;
		_day = 1;
		cout << "Data()" << endl;
	}
	Data(size_t year, size_t month, size_t day)
	{
		assert(!InvalidData(year, month, day));
		_year = year;
		_month = month;
		_day = day;
		cout << "Data(size_t year, size_t month, size_t day)" << endl;
	}
	Data(const Data& d)
	{
		cout << "Data(Data& d)" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//d1 = d3
	//d1 = d1
	Data& operator=(const Data& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}	
		return *this;
	}

	~Data()
	{
		cout << "~Data(Data& d)" << endl;
	}
public:
	void show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	size_t GetMonthDay(size_t year, size_t month)
	{
		assert(month > 0 && month <13);
		size_t MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int day = MonthDay[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
		{
			MonthDay[2] += 1;
		}
		return day;
	}

	bool InvalidData(size_t year, size_t month, size_t day)
	{
		if (year >= 1970 && month > 0 && month < 13 && day > 0 && GetMonthDay(year, month) >= day)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void SetData(size_t year, size_t month, size_t day)
	{
		if (!InvalidData(year, month, day))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
			cout << year << "-" << month << "-" << day << endl;
		}
	}

	bool operator==(const Data& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
//public:
private:
	size_t _year;
	size_t _month;
	size_t _day;
};

//void Test1()
//{
//	Data d1;
//	d1.show();
//	d1.SetData(2018, 9, 4);
//	d1.SetData(2018, 2, 29);
//	d1.show();
//}
//
//void Test2()
//{
//	Data d1;
//	d1.show();
//	Data d2(2018, 9, 4);
//
//	d2.show();
//}


class Array
{
public:
	Array(size_t n = 10)
	{
		_a = (size_t*)malloc(sizeof(size_t)*n);
	}
	~Array()
	{
		free(_a);
	}
private:
	size_t* _a;
};

//void Test3()
//{
//	Array aa(10);
//}

//bool operator==(const Data& d1, const Data& d2)
//{
//	return d1._year == d2._year 
//		&& d1._month == d2._month 
//		&& d1._day == d2._day;
//}

//void Test4()
//{
//	Data d1(2018, 6, 4);
//	Data d2(2018, 6, 6);
//	/*Data d2(d1);*/
//
//	cout << d1.operator==(d2) << endl;
//	cout << (d1 == d2) << endl;
//
//	d1.show();
//	d2.show();
//
//	//Array a1;
//	//Array a2(a1);
//}

void Test()
{
	Data d1(2018, 6, 5);
	Data d2(d1);
	
	d1.show();
	d2.show();

	Data d3(2018, 9, 4);

	d1 = d3;
	d1.show();
}