#include <iostream>
#include <vector>
using namespace std;

typedef enum {RED=0, BLACK=1} Color_Type;

template<class Type>
class RBTree;

template<class Type>
class rb_iterator;

//ÿ���Ժ�ɫ�ڵ���룬��Ϊ��ɫ������ܲ���Ҫ���������Ǻ�ɫ����ÿ�ζ��õ���
template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
	friend class rb_iterator<Type>;
public:
	RBTreeNode(const Type &d=Type())
		: data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr), color(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode<Type> *leftChild;
	RBTreeNode<Type> *rightChild;
	RBTreeNode<Type> *parent;
	Color_Type color;
};

////////////////////////////////////////////////////////////////////////
template<class Type>
class rb_iterator
{
	typedef rb_iterator<Type> self;
public:
	rb_iterator(RBTreeNode<Type> *p, RBTreeNode<Type> *nil, RBTreeNode<Type> *enode)
		: node(p), NIL(nil), end_node(enode)
	{}
	Type& operator*()
	{
		return node->data;
	}
	RBTreeNode<Type>* operator->()
	{
		return node;
	}

	self& operator++()
	{
		increment();
		return *this;
	}
	self operator++(int);
	self& operator--()
	{
		decrement();
		return *this;
	}
	self operator--(int);

	bool operator==(self & it)
	{
		return node == it.node;
	}
	bool operator!=(self & it)
	{
		return node != it.node;
	}
protected:
	void increment()
	{
		if (node->rightChild != NIL)
		{
			node = node->rightChild;
			if (node == end_node)
				return;
			while (node->leftChild != NIL)
				node = node->leftChild;
		}
		else
		{
			RBTreeNode<Type> *pr = node->parent;
			while (node == pr->rightChild)
			{
				node = pr;
				pr = node->parent;
			}
			node = pr;
		}
	}
	void decrement()
	{
		if (node->leftChild != NIL)
		{
			node = node->leftChild;
			while (node->rightChild != NIL)
				node = node->rightChild;
		}
		else
		{
			RBTreeNode<Type> *pr = node->parent;
			while (node == pr->leftChild)
			{
				node = pr;
				pr = node->parent;
			}
			node = pr;
		}
	}
private:
	RBTreeNode<Type> *node;
	RBTreeNode<Type> *NIL;
	RBTreeNode<Type> *end_node;
};

/////////////////////////////////////////////////////////////////////




template<class Type>
class RBTree
{
public:
	typedef rb_iterator<Type> iterator;
	RBTree() : NIL(_Buynode()), root(NIL), end_node(_Buynode())
	{
		NIL->parent = NIL->leftChild = NIL->rightChild = nullptr;
		NIL->color = BLACK;
		end_node->leftChild = end_node->rightChild = end_node->parent = nullptr;
	}
public:
	iterator begin()
	{
		RBTreeNode<Type> *p = root;
		while (p!=NIL && p->leftChild!=NIL)
			p = p->leftChild;
		return iterator(p, NIL, end_node);
	}
	iterator end()
	{
		return iterator(end_node, NIL, end_node);
	}
	void set_endnode()
	{
		RBTreeNode<Type> *p = root;
		while (p!=NIL && p->rightChild!=NIL)
			p = p->rightChild;
		p->rightChild = end_node;
		end_node->parent = p;
	}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
protected:
	bool Insert(RBTreeNode<Type> *&t, const Type &x);
	void Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
protected:
	void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
	void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
protected:
	RBTreeNode<Type>* _Buynode(const Type &x = Type())
	{
		RBTreeNode<Type> *s = new RBTreeNode<Type>(x);
		s->leftChild = s->rightChild = NIL;
		return s;
	}
private:
	RBTreeNode<Type> *NIL;
	RBTreeNode<Type> *root;
	RBTreeNode<Type> *end_node;
};

template<class Type>
bool RBTree<Type>::Insert(RBTreeNode<Type> *&t, const Type &x)
{
	//1 ����bst�Ĺ����������
	RBTreeNode<Type> *pr = NIL;
	RBTreeNode<Type> *s = t;
	while (s != NIL)
	{
		if (x == s->data)
			return false;
		pr = s;
		if (x < s->data)
			s = s->leftChild;
		else
			s = s->rightChild;
	}
	s = _Buynode(x);
	if (pr == NIL)//�����Ϊ���ڵ�
	{
		t = s;
		t->parent = NIL;
	}
	else if (x < pr->data)
		pr->leftChild = s;
	else
		pr->rightChild = s;
	s->parent = pr;

	//2 ����ƽ��
	Insert_Fixup(t, s);
	return true;
}

template<class Type>
void RBTree<Type>::Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
{
	while (x->parent->color == RED)
	{
		RBTreeNode<Type> *s;//�岮�ڵ�
		if (x->parent == x->parent->parent->leftChild)//���֧
		{
			s = x->parent->parent->rightChild;
			if (s->color == RED)
			{
				//״����  ֻ��Ҫ������ɫ������Ҫ��ת
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			else if (x == x->parent->rightChild)
			{
				//״���� ���󵥺��ҵ�������״��һ�����ҵ�
				x = x->parent;
				LeftRotate(t, x);
			}
			//״��һ
			x->parent->color = BLACK;       //��X����ɫ
			x->parent->parent->color = RED; //��G����ɫ
			RightRotate(t, x->parent->parent);
		}
		else//�ҷ�֧
		{
			s = x->parent->parent->leftChild;
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			else if (x == x->parent->leftChild)
			{
				x = x->parent;
				RightRotate(t, x);
			}
			x->parent->color = BLACK;
			x->parent->parent->color = RED;
			LeftRotate(t, x->parent->parent);
		}
	}
	t->color = BLACK;
}

template<class Type>
void RBTree<Type>::LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->rightChild;
	p->rightChild = s->leftChild;
	if (s->leftChild != NIL)
		s->leftChild->parent = p;
	s->parent = p->parent;
	if (p->parent == NIL)//���p�Ǹ��ڵ�
		t = s;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->leftChild = p;
	p->parent = s;
}

template<class Type>
void RBTree<Type>::RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->leftChild;
	p->leftChild = s->rightChild;
	if (s->rightChild != NIL)
		s->rightChild->parent = p;
	s->parent = p->parent;
	if (p->parent == NIL)
		t = s;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->rightChild = p;
	p->parent = s;
}

int main()
{
	vector<int> v = {10, 7, 4, 20, 15, 11, 12, 13};
	RBTree<int> rb;
	for (const auto &e : v)
		rb.Insert(e);
	rb.set_endnode();
	auto it = rb.begin();
	while (it != rb.end())
	{
		cout << *it << " ";
		++it;
	}
	return 0;
}