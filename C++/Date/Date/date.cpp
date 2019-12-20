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
public:
	int GetWeek();
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
	return (_year > d._year) || 
		(_year == d._year && _year > d._year) || 
		(_year == d._year && _year == d._year && _month > d._month);
	/*
	if (_year != d._year)
		return _year > d._year;
	if (_month != d._month)
		return _month > d._month;
	if (_day != d._day)
		return _day > d._day;
	return false;
	*/
}

bool Date::operator<=(const Date &d)const
{
	return !(*this > d);
}

bool Date::operator<(const Date &d)const
{
	return (_year < d._year) || 
		(_year == d._year && _month < d._month) || 
		(_year == d._year && _month == d._month && _day < d._day);//两个日期相比，只有这三种可能会使左边日期小于右边日期
	/*
	if (_year != d._year)
		return _year < d._year;
	if (_month != d._month)
		return _month < d._month;
	if (_day != d._day)
		return _day < d._day;
	return false;
	*/
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
	int day[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2)
	{
		if (IsLeap(year))
			month = 0;
	}
	return day[month];
}

int GetDayByYear(int year)
{
	if (IsLeap(year))
		return 366;
	return 365;
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
		mdays = GetDayByYearMonth(tmp._year, tmp._month);
	}
	tmp._day += days;
	return tmp;
}


Date Date::operator-(int days)
{
	int mdays;
	Date tmp = *this;
	while (tmp._day - days < 1)
	{
		--(tmp._month);
		if (tmp._month < 1)
		{
			tmp._month = 12;
			--(tmp._year);
		}
		mdays = GetDayByYearMonth(tmp._year, tmp._month);
		days -= mdays;
	}
	tmp._day -= days;
	return tmp;
}

int GetLastYearDays(int year, int month, int day)//获得一个日期最后一个不完整的年的天数
{
	int days = 0;
	for (int i = 1; i < month; ++i)
	{
		days += GetDayByYearMonth(year, i);
	}
	days += day;
	return days;
}

void Swap(const Date &dt1, const Date &dt2, Date &tmp1, Date &tmp2)
{
	if (dt1 < dt2)
	{
		tmp1 = dt1;
		tmp2 = dt2;
	}
	else
	{
		tmp1 = dt2;
		tmp2 = dt1;
	}
}

int Date::operator-(const Date& d)const
{

	Date tmp1, tmp2;//tmp1存放小日期
	int count = 0;//tmp2存放大日期
	Swap(*this, d, tmp1, tmp2);//tmp1存放小日期，tmp2存放大日期
	int last_year_days1 = GetLastYearDays(tmp1._year, tmp1._month, tmp1._day);
	int last_year_days2 = GetLastYearDays(tmp2._year, tmp2._month, tmp2._day);
	if (last_year_days2 >= last_year_days1)//将两个日期最后一年的天数相减，不够借位
		count = last_year_days2 - last_year_days1;
	else
	{
		count = GetDayByYear(tmp2._year - 1) - last_year_days1 + last_year_days2;
		--(tmp2._year);
	}

	for (int i = tmp1._year; i < tmp2._year; ++i)//将剩下的年相差的天数算出来
	{
		count += GetDayByYear(i);
	}

	/*
	while (tmp1 < tmp2)
	{
		++tmp1;
		++count;
	}
	*/
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

//W=(Y-1)+[(Y-1)/4]-[(Y-1)/100]+[(Y-1)/400]+D
//return W % 7
//D代表day在这一年的累计天数
//int Date::GetWeek()
//{
//	int D = GetLastYearDays(_year, _month, _day);
//	int W = (_year - 1) + (_year - 1) / 4 - (_year - 1) / 100 +
//		(_year - 1) / 400 + D;
//	return W % 7;
//}

int Date::GetWeek()
{
	int W = _day + 2 * _month + 3 * (_month + 1) / 5 + _year + _year / 4 
		- _year/100 + _year / 400 + 1;
	W = W % 7;
	return W % 7;
}

int main()
{
	Date dt1(2020, 3, 18);
	Date dt2(5258, 6, 29);
	//Date dt2(2019, 10, 30);
	//++dt1;//dt1.operator++()
	//dt1++;//dt1.operator++(int)
	//cout << dt1 - 21654 << endl;
	//cout << dt1 - dt2 << endl;
	cout << dt1.GetWeek() << endl;
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