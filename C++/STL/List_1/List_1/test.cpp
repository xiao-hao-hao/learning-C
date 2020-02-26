#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto pos = find<list<int>::iterator, int>(l.begin(), l.end(), 8);
	l.insert(pos, 666);
	for (auto &e : l)
	{
		cout << e << " ";
	}
	return 0;
}

/*
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	list<int> l1;
	list<int>::iterator it1 = l.begin();
	//const list<int> l1(10, 2);
	//list<int>::iterator it4 = l1.rbegin();
	//cout << typeid(l1).name() << endl;
	//cout << l1.empty() << endl;
	//cout << l.empty() << endl;
	//cout << l1.size() << endl;
	//cout << l.size() << endl;
	//cout << l1.front() << endl;
	//cout << l1.back() << endl;
	//cout << l.front() << endl;
	//cout << l.back() << endl;
	//while (it1 != l.end())
	//{
	//	*it1 += 2;
	//	cout << *it1 << " ";
	//	++it1;
	//}
	//cout << endl;
	//list<int>::reverse_iterator it2 = l.rbegin();
	//while (it2 != l.rend())
	//{
	//	cout << *it2 << " ";
	//	++it2;
	//}
	//cout << endl;
	//auto it3 = l.rbegin();
	//while (it3 != l.rend())
	//{
	//	cout << *it3 << " ";
	//	++it3;
	//}
	//cout << endl;
	return 0;
}

/*
int main()
{
	list<int> l1;
	list<int> l2(4, 100);
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(l3);
	for (const auto &e : l4)
		cout << e << " ";
	cout << endl;
	list<int>::iterator it1 = l4.begin();
	for (; it1 != l4.end(); ++it1)
		cout << *it1 << " ";
	cout << endl;
	auto it2 = l4.begin();
	for (; it2 != l4.end(); ++it2)
		cout << *it2 << " ";
	cout << endl;
	return 0;
}
*/