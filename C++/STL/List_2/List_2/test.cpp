#include <iostream>
#include <assert.h>
using namespace std;

namespace bit
{
	template<typename T>
	struct ListNode
	{
		ListNode(const T &val = T())
			: _Next(nullptr)
			, _Prev(nullptr)
			, _Value(val)
		{}
		ListNode<T> *_Next;
		ListNode<T> *_Prev;
		T            _Value;
	};

	template<typename T>
	class ListIterator
	{
		typedef ListIterator self;
	public:
		ListIterator()
			: _Ptr(nullptr)
		{}
		ListIterator(ListNode<T> *P)
			: _Ptr(P)
		{}
		~ListIterator()
		{}
	public:
		T& operator*()
		{return _Ptr->_Value;}
		const T& operator*()const
		{return _Ptr->Value;}
		T* operator->()
		{
			//return &**this;
			return &(_Ptr->_Value);
		}
		self& operator++()
		{
			_Ptr = _Ptr->_Next;
			return *this;
		}
		self operator++(int)
		{
			//self tmp = (*this)._Ptr;//调用用listnode指针构造对象的拷贝构造函数
			self tmp = *this;//调用默认的拷贝构造函数
			++*this;
			return tmp;
		}
		self& operator--()
		{
			_Ptr = _Ptr->_Prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp = *this;
			--*this;
			return tmp;
		}
		bool operator==(const self &P)
		{return _Ptr == P._Ptr;}
		bool operator!=(const self &P)
		{return !(_Ptr == P._Ptr);}
	public:
		ListNode<T>* Mynode()
		{return _Ptr;}
	private:
		ListNode<T> *_Ptr;
	};

	template<typename T>
	class list
	{
		typedef ListNode<T>* PNode;
	public:
		typedef ListIterator<T> iterator;
		typedef const ListIterator<T> const_iterator;
	public:
		list()
			: _Head(_Buynode())
			, _Size(0)
		{}
		list(size_t n, const T &value = T())
			: _Head(_Buynode())
			, _Size(0)
		{
			while (n--)
				push_back(value);
		}
		list(T *first, T *last)
			: _Head(_Buynode())
			, _Size(0)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		typedef iterator _It;
		list(_It first, _It last)
			: _Head(_Buynode())
			, _Size(0)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T> &lt)
			: _Head(_Buynode())
			, _Size(0)
		{
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		list<T>& operator=(const list<T> &lt)
		{
			if (this != &lt)
			{
				list<T> tmp(lt);
				swap(emp);
			}
			return *this;
		}
		~list()
		{
			clear();
			delete _Head;
			_Head = nullptr;
		}
	public:
		size_t size()const
		{return _Size;}
		bool empty()const
		{return _Size == 0;}
	public:
		iterator begin()
		{return iterator(_Head->_Next);}
		const_iterator begin()const
		{return const_iterator(_Head->_Next);}
		iterator end()
		{return iterator(_Head);}
		const_iterator end()const
		{return const_iterator(_Head);}
	public:
		void push_back(const T &val)
		{insert(end(), val);}
		void push_front(const T &val)
		{insert(begin(), val);}
		T& front()
		{
			assert(!empty());
			return *begin();
		}
		const T& front()const
		{
			assert(!empty());
			return *begin();
		}
		T& back()
		{
			assert(!empty());
			return *--end();
		}
		const T& back()const
		{
			assert(!empty());
			return *--end();
		}
		void swap(list<T> &lt)
		{
			std::swap(_Head, lt._Head);
			std::swap(_Size, lt._Size);
		}
		void clear()
		{
			while (size() != 0)
				erase(begin());
			//erase(begin(), ens());
		}
	public:
		iterator insert(iterator pos, const T &val)
		{
			PNode _S = new ListNode<T>(val);
			PNode _P = pos.Mynode();
			_S->_Next = _P;
			_S->_Prev = _P->_Prev;
			_S->_Prev->_Next = _S;
			_S->_Next->_Prev = _S;
			++_Size;
			return iterator(_S);
		}
		iterator erase(iterator pos)
		{
			PNode p = pos++.Mynode();
			p->_Prev->_Next = p->_Next;
			p->_Next->_Prev = p->_Prev;
			delete p;
			--_Size;
			return pos;
		}
	private:
		PNode _Buynode(const T &val = T())
		{
			PNode _S = new ListNode<T>(val);
			_S->_Next = _S->_Prev = _S;
			return _S;
		}
	private:
		ListNode<T> *_Head;
		size_t       _Size;
	};
}

int main()
{
	int ar[] = { 1, 2, 3, 4, 5 };
	const bit::list<int> mylist1(ar, ar + 5);
	//bit::ListIterator<int> it1 = mylist1.begin();
	bit::list<int>::iterator it1 = mylist1.begin();
	//cout << it1->_Value << endl;
	//auto it1 = mylist1.begin();
	cout << typeid(mylist1.begin()).name();
	//*it1 = 666;
	//bit::list<int> mylist2(5, 6);
	//bit::list<int> mylist3(mylist1.begin(), mylist1.end());
	////bit::list<int> mylist3(mylist1);
	for (const auto &e : mylist1) //begin() end() ++
		cout << e << "-->";
	cout << "Over." << endl;
	//cout << &mylist1 << endl;
	return 0;
}