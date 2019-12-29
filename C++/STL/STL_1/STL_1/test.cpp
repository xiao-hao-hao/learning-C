#include <iostream>
#include <assert.h>
using namespace std;

template<class _Ty>
class list
{
public:
	//类型的萃取
	typedef size_t size_type;
	typedef size_t difference_type;
	typedef _Ty* pointer;
	typedef const _Ty* const_pointer;
	typedef _Ty &reference;
	typedef const _Ty& const_reference;
	typedef _Ty value_type;

public:
	struct _Node;
	typedef _Node* _Nodeptr;
	struct _Node
	{
		_Nodeptr _Next, _Prev;
		_Ty _Value;
	};
	struct _Acc
	{
		typedef _Node* &_Nodepref;
		typedef _Ty &_Vref;
		static _Nodepref _Next(_Nodeptr _P)
		{
			return ((_Nodepref)(*_P)._Next);
		}
		static _Nodepref _Prev(_Nodeptr _P)
		{
			return ((_Nodepref)(*_P)._Prev);
		}
		static _Vref _Value(_Nodeptr _P)
		{
			return ((_Vref)(*_P)._Value);
		}
	};
//内部类，迭代器
public:
	class iterator
	{
	public:
		iterator() : _Ptr(NULL)
		{}
		iterator(_Nodeptr _P) : _Ptr(_P)
		{}
	public:
		_Ty& operator*() const
		{
			return (_Acc::_Value(_Ptr));
		}
		iterator& operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return (*this);
		}
		iterator operator++(int)
		{
			iterator _Tmp = *this;
			++*this;
			return (_Tmp);
		}
		iterator& operator--()//前置减减，指针指向前一个节点
		{
			_Ptr = _Acc::_Prev(_Ptr);
			return (*this);//this是一个指针，*this是this所指的对象
		}
		iterator operator--(int)
		{
			iterator _Tmp = *this;
			--*this;
			return (_Tmp);
		}
		bool operator==(const iterator& _X) const
		{
			return (_Ptr == _X._Ptr);
		}
		bool operator!=(const iterator& _X) const
		{
			return (!(*this == _X));
		}
		_Nodeptr _Mynode()
		{
			return _Ptr;
		}
	protected:
		_Nodeptr _Ptr;
	};
public:
	explicit list() : _Head(_Buynode()), _Size(0)//构造函数
	{}
public:
	iterator begin()
	{
		return iterator(_Acc::_Next(_Head));//拷贝构造无名临时对象
	}
	iterator end()
	{
		return iterator(_Head);
	}
public:
	void push_back(const _Ty &_X)
	{
		insert(end(), _X);
	}
	void push_front(const _Ty &_X)
	{
		insert(begin(), _X);
	}
public:
	iterator insert(iterator _P, const _Ty& _X = _Ty())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Value(_S) = _X;
		++_Size;
		return (iterator(_S));
	}
protected:
	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof (_Node));
		_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
		return (_S);
	}
private:
	_Nodeptr _Head;
	size_type _Size;
};

int main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);
	mylist.push_front(10);
	list<int>::iterator it = mylist.begin();
	while (it != mylist.end())
	{
		cout << *it << "-->";
		++it;
	}
	cout << "Over." << endl;
	return 0;
}