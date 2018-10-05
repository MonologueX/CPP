#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:

	void show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	int GetMonthDay(int year, int month)
	{
		static int MonthDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0)
			|| (year % 400 == 0))
			return 29;
		return MonthDay[month];
	}

	Date(int year = 2018, int month = 9, int day = 7)
	{
		//cout << "Date(int year = 2018, int month = 9, int day = 7)" << endl;
		if (year > 1900 && month <= 12 && month > 0
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			/*assert(false);*/
			cout << year << "-" << month << "-" << day;
			cout << "是非法日期" << endl;
		}
	}

	//Date d3(d1)
	Date(const Date& d)
	{
		//cout << "Date(const Date& d)" << endl;
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	//d2 = d1
	Date operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	~Date()
	{
		/*cout << this << endl;
		cout << "~Date()" << endl;*/
	}
	//运算符重载
	bool operator>(const Date& d)
	{
		if ((_year > d._year) 
			|| (_year == d._year && _month >d._month)
			|| (_year == d._year && _month >d._month && _day >d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator>=(const Date& d)
	{ 
		return *this > d || *this == d;
	}

	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	Date operator+(int day)
	{
		if (day < 0)
		{
			return (*this - (-day));
		}
		Date ret(*this);

		/*if (day < 0)
		{
			return *this - (-_day);
		}*/

		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}

	Date operator-(int day)
	{
		if (day < 0)
		{
			return (*this + (-day));
		}
		Date ret(*this);
		ret._day -= day;
		while (ret._day <= 0)
		{
			--ret._month;
			if (ret._month == 0)
			{
				ret._year--;
				ret._month = 12;
			}

			ret._day += GetMonthDay(ret._year, ret._month);
		}
		return ret;
	}

	Date operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}

	Date operator-=(int day)
	{
		/**this = *this - day;*/
		Date ret = *this;
		*this = ret - day;
		return *this;
	}

	int operator-(const Date& d)
	{
		int flag = 1;
		Date d1 = *this;
		Date d2 = d1;
		Date* max = &d1;
		Date* min = &d2;
		if (*this < d)
		{
			max = (Date*)&d;
			min = this;
			flag = -1;
		}

		int days = 0;
		while (*min < *max)
		{
			*min += 1;
			++days; 
		}
		return days * flag;
	}

	Date operator++()
	{
		*this += 1;
		return *this;
	}

	Date operator++(int)	//后置
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	Date operator--()
	{
		*this -= 1;
		return *this;
	}

	Date operator--(int)	//qian置
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}
private:
	int _year;
	int _month;
	int _day;
};

//void TestDate()
//{
//	Date d1(2018, 6, 6);
//	cout << &d1 << endl;
//	d1.show();
//	//Date d2(2019, 2, 29);
//	Date d3;
//	cout << &d3 << endl;
//	d3.show();
//
//}

//void TestDate()
//{
//	Date d1(2018, 6, 6);
//
//	d1.show();
//	//Date d2(2019, 2, 29);
//	Date d3;
//	d3.show();
//
//	Date d4(d1);
//	d4.show();
//}

//void TestDate()
//{
//	Date d1(2018, 6, 6);
//	Date d2;
//	Date d3;
//	d2 = d1;
//}

//void TestDate()
//{
//	Date d1(2018, 6, 6);
//	Date d2 = d1 + 500;
//	d2.show();
//}

//void TestDate()
//{
//	Date d1(2018, 6, 6);
//	Date d2 = d1 + (-500);
//	d2.show();
//	/*Date d3 = d1 - (-500);
//	d3.show();*/
//	d2 += 500;
//	d2.show();
//}

void TestDate()
{
	Date d1(1998, 12, 7);
	Date d2(2018, 9, 7);
	cout << d2 - d1 << endl;
}