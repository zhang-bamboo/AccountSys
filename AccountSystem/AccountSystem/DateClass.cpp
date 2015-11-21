#include"DateClass.h"
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

static const int DAYS[] ={ 31,28,31,30,31,30 ,31,30 ,31,30 ,31,30 };
static const int LEAP_DAYS[] ={ 31,29,31,30,31,30 ,31,30 ,31,30 ,31,30 };
static const string WEEK_DAY[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
static int daysInMonth(int m,int y);
static bool IsLeapYear(int y);
static int toweek(int year, int month, int day);
static bool IsValidDate(int y, int m, int d);

Date::Date(int y,int m,int d) throw(std::invalid_argument) try
{
	if (!IsValidDate(y, m, d))
		throw std::invalid_argument("invalid argument for Date::Date");
	year = y;
	month = m;
	day = d;
}
catch (std::invalid_argument e) {
	cout << e.what() << endl;
}

Date::Date()
{
}

Date::~Date()
{
	year = 0;
	month = 0;
	day = 0;
}
void Date::setDate(int y,int m,int d) throw(std::invalid_argument)
{
	if (!IsValidDate(y, m, d))
		throw std::invalid_argument("invalid argument for Date::Date");
	year = y;
	month = m;
	day = d;
}
int Date::getYear() const
{
	return year;
}
int Date::getMonth() const
{
	return month;
}
int Date::getDay() const
{
	return day;
}
void Date::incrementDate()
{
	day++;
	if (day > daysInMonth(month,year))
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}
void Date::decrementDate()
{
	day--;
	if (day < 1)
	{
		month--;
		if (month < 1)
		{
			month = 12;
			year--;
		}
		day = daysInMonth(month,year);
	}
}
void Date::showWeek()
{
	cout << WEEK_DAY[toWeek()] << endl;
}
int Date::toWeek() const
{
	int week_firstday = ((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1) % 7;
	int days = 0;
	for (int i = 1;i < month;i++)
		days += daysInMonth(i, year);
	days += day;
	int week = (week_firstday + days - 1) % 7;
	return(week);
}

//zeller formula
/*int Date::toweek()
{
	int w, c, y, m, d;
	c = year / 100;
	y = year % 100;
	m = month;
	d = day;
	if (month == 1 || month == 2)
	{
		c = (year - 1) / 100;
		y = (year - 1) % 100;
		m = month + 12;
	}
	w = (c / 4) - 2 * c + y + (y / 4) + (13 * (m + 1) / 5) + d - 1;
	while (w < 0)
		w += 7;
	return(w % 7);
}*/

void Date::displayDate() const
{
	printf("%d-%d-%d ", year, month, day);
}

bool Date::operator==(Date & anotherDate)
{
	if (year == anotherDate.year&&month == anotherDate.month&&day == anotherDate.day)
		return true;
	return false;
}
bool Date::operator>(Date & anotherDate)
{
	if (year > anotherDate.year)
		return true;
	else if (year < anotherDate.year)
		return false;
	else if (month > anotherDate.month)
		return true;
	else if (month < anotherDate.month)
		return false;
	else if (day > anotherDate.day)
		return true;
	else
		return false;
}
bool Date::operator>=(Date & anotherDate)
{
	if (*this > anotherDate || *this == anotherDate)
		return true;
	return false;
}
bool Date::operator<(Date & anotherDate)
{
	if (year < anotherDate.year)
		return true;
	else if (year > anotherDate.year)
		return false;
	else if (month < anotherDate.month)
		return true;
	else if (month > anotherDate.month)
		return false;
	else if (day < anotherDate.day)
		return true;
	else
		return false;
}

bool Date::operator<=(Date & anotherDate)
{
	if (year < anotherDate.year)
		return true;
	else if (year > anotherDate.year)
		return false;
	else if (month < anotherDate.month)
		return true;
	else if (month > anotherDate.month)
		return false;
	else if (day <= anotherDate.day)
		return true;
	else
		return false;
}
static int daysInMonth(int month,int year)
{
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		return 31;
	case 4:case 6:case 9:case 11:
		return 30;
	case 2:
		if (IsLeapYear(year))
			return 29;
		return 28;
	default:
		return 0;
	}	
}

static bool IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0)
		return true;
	else
		return false;
}
static bool IsValidDate(int y, int m, int d)
{
	if (y <1 || m > 12 || m < 1)
		return false;
	else if (d < 1 || d>daysInMonth(m,y))
		return false;
	else
		return true;
}

