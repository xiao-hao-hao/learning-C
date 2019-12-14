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
	int operator-(const Date& d)const;
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
	out << dt._year << "年" << dt._month << "月" << dt._day << "日";
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
	Date tmp = *this;
	int mdays = GetDayByYearMonth(tmp._year, tmp._month);
	while (days + tmp._day > mdays)
	{
		++tmp._month;
		if (tmp._month > 12)
		{
			tmp._month = 1;
			++tmp._year;
		}
		days -= mdays;
		mdays = GetDayByYearMonth(tmp._day, tmp._month);
	}
	tmp._day += days;
	return tmp;
}

/*
Date Date::operator-(int day)
{
	Date tmp = *this;
	if (day < tmp._day)
		tmp._day -= day;

}
*/

int Date::operator-(const Date& d)const
{
	Date tmp1, tmp2;
	int count = 0;
	if (*this < d)
	{
		tmp1 = *this;
		tmp2 = d;
	}
	else
	{
		tmp1 = d;
		tmp2 = *this;
	}
	while (tmp1 < tmp2)
	{
		++tmp1;
		++count;
	}
	return count;
}

Date& Date::operator++()//前置++
{
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	++(*this);
	return tmp;
}

Date& Date::operator--()//前置--
{
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int)//后置--
{
	Date tmp = *this;
	--(*this);
	return tmp;
}

int main()
{
	Date dt1(0000, 12, 9);
	Date dt2(1258951, 12, 9);
	//++dt1;//dt1.operator++()
	dt1++;//dt1.operator++(int)
	cout << dt1 - dt2 << endl;
	cout << dt1 << endl;
	return 0;
}

/*
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

*/