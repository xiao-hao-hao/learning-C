#include <iostream>
#include <forward_list>
#include <string>
#include <set>
#include <vector>
#include <list>
#include<map>
#include <functional>
using namespace std;


int main()
{
	map<int, int, greater<int>> ismap = { { 1, 1 }, { 2, 2 }, { 3, 3 } };
	auto ret = ismap.insert(make_pair(2, 666));
	cout << ret.first->first << "::" << (*(ret.first)).second << " " << ret.second << endl;
	map<int, int>::iterator it = ismap.begin();
	while (it != ismap.end())
	{
		cout << it->first << ":" << (*it).second << endl;
		++it;
	}
	return 0;
}

/*
int main()
{
	multimap<int, int, greater<int>> ismap = { { 1, 1 }, { 2, 2 }, { 3, 3 } , {3,3}, {3,3}, {3,5}, {4,6}};
	auto ret = ismap.insert(make_pair(2, 666));
	//cout << ret.first->first << "::" << *(ret.first).second << " " << ret.second << endl;
	map<int, int>::iterator it = ismap.begin();
	while (it != ismap.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		++it;
	}
	return 0;
}

/*
//at() 会检查边界
//[]   不会检查  ->键值不存在时，把数据插入
void main()
{
	//预判起始位置
	map<int, string> ismap = { { 1, "Student" }, { 1, "Student1" }, { 1, "Student2" }, { 2, "Teacher" }, { 3, "Friend" }, { 4, "Bit" } };
	//头插
	ismap.insert(ismap.begin(), make_pair(8, "服务"));
	//尾插
	ismap.insert(ismap.end(), make_pair(0, "666"));
	//在bit之前插入
	auto pos = ismap.find(4);
	if (pos != ismap.end())
	{
		ismap.insert(pos, make_pair(7, "学习"));
	}
	for (const auto &e : ismap)
		cout << e.first << " : " << e.second << endl;
}

/*
void main()
{
	map<int, string> ismap = { { 1, "Student" }, { 2, "Teacher" }, { 3, "Friend" }, { 4, "Bit" } };
	ismap[1] = "学生";  //[]
	ismap[2] = "老师";
	ismap[3] = "朋友";
	int key = 10;
	auto ret_it = ismap.find(key);
	if (ret_it != ismap.end())
	{
		//
	}
	else
		cout << "不存在." << endl;
	ismap[5] = "服务"; //数据插入  <5-服务>
	for (const auto &e : ismap)
		cout << e.first << " : " << e.second << endl;
}

/*
void main()
{
	map<int, string> ismap;
	pair<int, string> v[] = { { 3, "Friend" }, { 1, "Student" }, { 2, "Teacher" }, { 4, "Bit" } };
	int n = sizeof(v) / sizeof(v[0]);
	for (int i = 0; i<n; ++i)
		ismap.insert(v[i]);
	//auto it = ismap.begin();
	//it->first = 10;
	//it->second[0] = 's';
	//ismap[5];
	for (const auto &e : ismap)
	{
		//cout << typeid(e).name();
		cout << e.first << " : " << e.second << endl;
	}
	cout << ismap[5];
}

/*
class Foo
{
public:
	Foo(int n, double x) : m_n(n), m_x(x)
	{}
	int m_n;
	double m_x;
};
void main()
{
	vector<Foo> v;
	auto someIterator = v.begin();
	someIterator = v.emplace(someIterator, 42, 3.1416);        // 没有临时变量产生
	//v.insert(someIterator, Foo(42, 3.1416));
	//v.insert(someIterator, 42, 3.1416);
}

/*
void main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 13, 14, 4545 };
	set<int> s(iv.begin(), iv.end());
	pair<set<int>::iterator, bool> ret1 = s.emplace(100);
	pair<set<int>::iterator, bool> ret = s.insert(100);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//cout << *(ret.first) << ' ' << ret.second;
	if (s.find(14) == s.end())
		cout << "yes" << endl;
	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

/*
void main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 43, 43, 43, 43, 43, 43, 43, 14, 4545 };
	set<int> s(iv.begin(), iv.end());
	cout << "size = " << s.size() << endl;
	cout << "count = " << s.count(430) << endl;  //0  1
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	multiset<int> multis(iv.begin(), iv.end());
	cout << "multi size = " << multis.size() << endl;
	cout << "multi count = " << multis.count(43) << endl;  //0  1
	for (auto &e : multis)
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	set<int> s(iv.begin(), iv.end());
	set<int> s1 = {1, 2, 3, 4, 5};
	s1.swap(s);
	set<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//set<int>::reverse_iterator rit = s.rbegin();
	//while (rit != s.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	cout << s1.count(43);
	cout << endl;
}

/*
void main()
{
	list<int> mylist = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	list<int>::iterator it = mylist.begin();
	cout << *it << endl;
	*it = 1000;
	cout << *it << endl;
}

/*
void main()
{
	list<int> mylist;
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	const set<int> s(iv.begin(), iv.end());
	//s.erase(2);
	//s.insert(20);
	set<int>::const_iterator it = s.cbegin();
	//*it = 20;  //const  ==>
	while (it != s.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

/*
void main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	list<int> lt = {1, 2, 3, 4};
	//set<int> s(iv.begin(), iv.end());
	set<int> s(lt.begin(), lt.end());
	set<int> s1(s);
	for (const auto &e : s)
		cout << e << " ";
	cout << endl;
}


/*
void main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	set<int> s;
	set<int, greater<int>> s1 = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 }; //C++11
	for (const auto &e : s1)
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
pair<int, string> v1 = { 1, "abc" };  //值对
pair<int, string> v2 = { 2, "xyz" };
cout << v1.first << " : " << v1.second << endl;
pair<string, string> v3 = make_pair("1-1", "元旦节");
cout << v3.first << " : " << v3.second << endl;
}

/*
int main()
{
pair<int, int> a(1, 2);
return 0;
}

/*
void main()
{
forward_list<int> mylist;
for (int i = 1; i <= 10; ++i)
mylist.push_front(i);
//mylist.reverse();
for (const auto &e : mylist)
cout << e << "->";
cout << endl;
}
*/


