#include <iostream>
#include <vector>
using namespace std;

typedef enum {RED=0, BLACK=1} Color_Type;

template<class Type>
class RBTree;

//ÿ���Ժ�ɫ�ڵ���룬��Ϊ��ɫ������ܲ���Ҫ���������Ǻ�ɫ����ÿ�ζ��õ���
template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
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

template<class Type>
class RBTree
{
public:
	RBTree() : NIL(_Buynode()), root(NIL)
	{
		NIL->parent = NIL->leftChild = NIL->rightChild = nullptr;
		NIL->color = BLACK;
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
			x->parent->color = BLACK;       //p
			x->parent->parent->color = RED; //g
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
	return 0;
}