#include <iostream>
#include <queue>
#include <assert.h>
#include <vector>
#include <functional>
using namespace std;


//void main()
//{
//vector<int> v = {5, 7, 8, 2, 9, 3, 1, 0};
//for(const auto &e : v)
//cout<<e<<" ";
//cout<<endl;
//make_heap(v.begin(), v.end(), greater<int>());//制作一个堆
//for(const auto &e : v)
//cout<<e<<" ";
//cout<<endl;
//v.push_back(6);
//push_heap(v.begin(), v.end(), greater<int>());
//for(const auto &e : v)
//cout<<e<<" ";
//cout<<endl;
//pop_heap(v.begin(), v.end(), greater<int>());
//for(const auto &e : v)
//cout<<e<<" ";
//cout<<endl;
//pop_heap(v.begin(), --v.end(), greater<int>());
//for(const auto &e : v)
//cout<<e<<" ";
//cout<<endl;
//}

namespace bit
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};
	template<class T>//仿函数(仿函数就是一个类，在这个类里仅仅是重载了一个小括号，仿函数只有一元仿函数和二元仿函数，根据参数个数确定)
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};
	template<class T, class Cont = vector<T>, class Pred = less<T> >
	class priority_queue
	{
	public:
		typedef T value_type;
		typedef size_t size_type;
		priority_queue()
		{}
		priority_queue(const value_type *first, const value_type *last)
		{
			while (first != last)
				c.push_back(*first++);
			int root = (c.size() - 1) / 2; //找到二叉树的最后面一个需要向下调的节点
			while (root >= 0)
				adjustdown(root--);
		}
		bool empty() const
		{
			return c.empty();
		}
		size_type size() const
		{
			return c.size();
		}
		value_type& top()
		{
			assert(!empty());
			return c.front();
		}
		const value_type& top() const
		{
			assert(!empty());
			return c.front();
		}
		void push(const value_type &x)
		{
			c.push_back(x);
			adjustup(c.size() - 1);
		}
		void pop()
		{
			std::swap(c.front(), c.back());
			c.pop_back();
			adjustdown(0);
		}
	protected:
		void adjustdown(int parent)
		{
			int child = 2 * parent + 1;
			while (child < c.size())
			{
				if (child + 1 < c.size() && comp(c[child], c[child + 1]))
					++child;
				if (comp(c[parent], c[child])) //-->comp.operator(c[parent], c[chid])
				{
					std::swap(c[parent], c[child]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
					break;
			}
		}
		void adjustup(int child)
		{
			int parent = (child - 1) / 2;
			while (child)
			{
				if (comp(c[parent], c[child]))
				{
					std::swap(c[parent], c[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}
	private:
		Cont c;
		Pred comp;
	};
}

int main()
{
	bit::priority_queue<int> pq;
	pq.push(1);
	pq.push(7);
	pq.push(2);
	pq.push(3);
	pq.push(9);
	pq.push(4);
	pq.push(5);
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	return 0;
}

//void main()
//{
//	int v[] = { 5, 7, 8, 2, 9, 3, 1, 0 };
//	int n = sizeof(v) / sizeof(v[0]);
//	bit::priority_queue<int, vector<int>, bit::greater<int> > pq(v, v + n);
//	while (!pq.empty())
//	{
//		cout << "top = " << pq.top() << endl;  //8  // 7
//		pq.pop();
//	}
//}

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