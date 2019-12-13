#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream &out, const Date &dt);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
};

Date::Date(int year, int month, int day)
	: _year(year)
	, _month(month)
	, _day(day)
{}

Date::Date(const Date &d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date &d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

bool Date::operator==(const Date &d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date &d)const
{
	//return _year != d._year || _month != d._month || _day != d._day;
	return !(*this == d);
}

bool Date::operator>(const Date &d)const
{
	if (_year != d._year)
		return _year > d._year;
	if (_month != d._month)
		return _month > d._month;
	if (_day != d._day)
		return _day > d._day;
	return false;
}

bool Date::operator<=(const Date &d)const
{
	return !(*this > d);
}

bool Date::operator<(const Date &d)const
{
	if (_year != d._year)
		return _year < d._year;
	if (_month != d._month)
		return _month < d._month;
	if (_day != d._day)
		return _day < d._day;
	return false;
}

bool Date::operator>=(const Date &d)const
{
	return !(*this < d);
}

ostream& operator<<(ostream &out, const Date &dt)
{
	out << dt._year << "Äê" << dt._month << "ÔÂ" << dt._day << "ÈÕ";
	return out;
}

bool IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

int GetDayByYearMonth(int year, int month)
{
	int day[13] = { 29, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2)
	{
		if (IsLeap(year))
			month = 0;
	}
	return day[month];
}

Date Date::operator+(int days)
{
	
}

Date Date::operator-(int day)
{
	
}

Date& Date::operator++()
{}

Date Date::operator++(int)
{}

int main()
{
	Date dt1(2019, 12, 9);
	Date dt2(2019, 12, 9);
	if (dt1 == dt2)
		cout << "dt1 = dt2" << endl;
	if (dt1 != dt2)
		cout << "dt1 != dt2" << endl;
	if (dt1 > dt2)
		cout << "dt1 > dt2" << endl;
	if (dt1 <= dt2)
		cout << "dt1 <= dt2" << endl;
	if (dt1 < dt2)
		cout << "dt1 < dt2" << endl;
	if (dt1 >= dt2)
		cout << "dt1 >= dt2" << endl;
	//cout << dt1 << endl;
	return 0;
}