#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	//v.reserve(100);
	vector<int>::iterator it = v.begin();
	//it = it + 2;
	//v.insert(v.begin()+2, 2);
	//v.erase(v.begin());
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	return 0;
}

//int main()
//{
//	vector<int> v(10, 6);
//	for (auto x : v)
//	{
//		cout << typeid(x).name();
//	}
//	return 0;
//}

//int main()
//{
//	vector<int> v(5, 3);
//	v.reserve(100);
//	cout << v[4] << endl;
//	return 0;
//}

//void main()
//{
//	vector<int> v;
//	v.reserve(100);
//	for (int i = 0; i<100; ++i)
//	{
//		cout << "capacity = " << v.capacity() << endl;
//		v.push_back(i);
//	}
//}

//void Print(vector<int> &v)
//{
//	for (int i = 0; i<v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//}


//void main()
//{
//	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v(ar, ar + 10);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//	v.resize(5, 3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//}

//void main()
//{
//	int ar[3] = { 1, 2, 3 };
//	vector<int> v(ar, ar + 3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//	v.reserve(10);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(100);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(50);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//}

//void main()
//{
//	vector<int> v;
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(1);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(2);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(4);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(5);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(6);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(7);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//}

//int main()
//{
//	vector<int> v1;
//	vector<int> v2(10, 5);
//	vector<int> v3(v2);
//	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v4(ar, ar + 10);
//	cout << v4.size() << endl;
//	vector<int> v5(v4.begin(), v4.end());
//	cout << v5.size();
//	char * str = "hello bit!";
//	vector<char> v6(str, str + 3);
//	for (int i = 0; i < v6.size(); ++i)
//		cout << v6[i];
//	return 0;
//}