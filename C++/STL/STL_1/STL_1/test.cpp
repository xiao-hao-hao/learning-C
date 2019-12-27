#include <iostream>
#include <assert.h>
using namespace std;

template<class _Ty>
class list
{
public:
	struct _Node;
	typedef _Node* _Nodeptr;
	struct _Node
	{
		_Nodeptr _Next, _Prev;
		_Ty _Value;
	};
private:
	_Nodeptr _Head;
	size_type _Size;
};


int main()
{
	list<int> mylist;
	return 0;
}