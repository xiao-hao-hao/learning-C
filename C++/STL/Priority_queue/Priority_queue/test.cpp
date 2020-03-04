#include <iostream>
#include <queue>
#include <assert.h>
#include <vector>
using namespace std;

//class Date
//{
//public:
//	Date()
//	{}
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1 = 2018;
//	return 0;
//}

//namespace bit
//{
//	template<class T, class Cont = vector<T>, class Pred = less<T> >
//	class priority_queue
//	{
//	public:
//		typedef T value_type;
//		typedef size_t size_type;
//		explicit priority_queue(const Pred &pr = Pred())
//		{
//			make_heap(c.begin(), c.end());
//		}
//		priority_queue(const value_type *first, const value_type *last)
//		{
//			while (first != last)
//				c.push_back(*first++);
//			make_heap(c.begin(), c.end());
//		}
//		bool empty() const
//		{return c.empty();}
//		size_type size() const
//		{return c.size();}
//		value_type& top()
//		{
//			assert(!empty());
//			return c.front();
//		}
//		void push(const value_type &x)
//		{
//			c.push_back(x);
//			push_heap(c.begin(), c.end());
//		}
//		void pop()
//		{
//			pop_heap(c.begin(), c.end());
//			c.pop_back();
//		}
//	private:
//		Cont c;
//		Pred comp;
//	};
//}

//int main()
//{
//	int ar[] = { 5, 7, 8, 2 };
//	//bit::priority_queue<int> pq;
//	bit::priority_queue<int> pq(ar, ar + 4);
//	//pq.push(5);
//	//pq.push(7);
//	//pq.push(8);
//	//pq.push(2);
//	cout << pq.size() << endl;
//	cout << pq.top() << endl;
//	pq.pop();
//	cout << pq.size() << endl;
//	cout << pq.top() << endl;
//	return 0;
//}

//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}
//
//
//int main()
//{
//
//	return 0;
//}



//
//int main()
//{
//	vector<int> v = { 5, 7, 8, 2, 9, 3, 1, 0 };
//	priority_queue<int> pq;
//	for (const auto &e : v)
//	{
//		pq.push(e);
//	}
//	pq.pop();
//	cout << pq.size() << endl;
//	return 0;
//}