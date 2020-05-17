#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

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


