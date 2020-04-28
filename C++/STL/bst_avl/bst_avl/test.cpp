#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class Type>
class BSTree;

template<class Type>
class BSTNode
{
	friend class BSTree<Type>;
public:
	BSTNode(Type d=Type(), BSTNode<Type> *left=nullptr, BSTNode<Type> *right=nullptr)
		: data(d), leftChild(left), rightChild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type> *leftChild;
	BSTNode<Type> *rightChild;
};

template<class Type>
class BSTree//����������
{
public:
	BSTree() : root(nullptr)
	{}
public:
	Type& Max()const
	{
		return Max(root);
	}
	Type& Min()const
	{
		return Min(root);
	}
	void InOrder()const
	{
		InOrder(root);
	}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
	BSTNode<Type>* Search(const Type &key)
	{
		return Search(root, key);
	}
protected:
	Type& Max(BSTNode<Type> *t)const
	{
		assert(t != nullptr);
		while (t->rightChild != nullptr)
			t = t->rightChild;
		return t->data;
	}
	Type& Min(BSTNode<Type> *t)const
	{
		assert(t != nullptr);
		while (t->leftChild != nullptr)
			t = t->leftChild;
		return t->data;
	}
	void InOrder(BSTNode<Type> *t)const
	{
		if (t != nullptr)
		{
			InOrder(t->leftChild);
			cout << (t->data).first << " : " << (t->data).second << endl;
			InOrder(t->rightChild);
		}
	}
	BSTNode<Type>* Search(BSTNode<Type> *t, const Type &key)
	{
		if (t == nullptr)
			return nullptr;
		if (key < t->data)
			return Search(t->leftChild, key);
		else if (key > t->data)
			return Search(t->rightChild, key);
		else
			return t;
	}
	bool Insert(BSTNode<Type> *&t, const Type &x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if (x < t->data)
			return Insert(t->leftChild, x);
		else if (x > t->data)
			return Insert(t->rightChild, x);
		else
			return false;
	}
	bool Remove(BSTNode<Type> *&t, const Type &key)
	{
		if (t == nullptr)
			return false;
		if (key < t->data)
			return Remove(t->leftChild, key);
		else if (key > t->data)
			return Remove(t->rightChild, key);
		else
		{
			if (t->leftChild!=nullptr && t->rightChild!=nullptr)
			{
				BSTNode<Type> *p = t->leftChild;
				while (p->rightChild != nullptr)
					p = p->rightChild;
				t->data = p->data;
				Remove(t->leftChild, p->data);
			}
			else
			{
				BSTNode<Type> *tmp = t;
				if (t->leftChild != nullptr)
					t = t->leftChild;
				else
					t = t->rightChild;
				delete tmp;
				return true;
			}
		}
	}
private:
	BSTNode<Type> *root;
};

int main()
{
	pair<string, string> v[] = {{"1.1", "Ԫ����"}, {"5.1", "�Ͷ���"}};
	int n = sizeof(v) / sizeof(v[0]);

	BSTree<pair<string, string> > bst;
	for (int i = 0; i < n; ++i)
		bst.Insert(v[i]);
	bst.InOrder();
	return 0;
}

//int main()
//{
//	vector<int> ar  = {2, 44, 5, 1, 9, 7};
//	BSTree<int> bst;
//	for (const auto &e : ar)
//		bst.Insert(e);
//	BSTNode<int>* pb = bst.Search(7);
//	bst.Remove(2);
//	return 0;
//}

//bool Remove(BSTNode<Type> *&t, const Type &key)
//{
//	if (t == nullptr)
//		return false;
//	if (key < t->data)
//		return Remove(t->leftChild, key);
//	else if (key > t->data)
//		return Remove(t->rightChild, key);
//	else
//	{
//		if (t->leftChild == nullptr && t->rightChild == nullptr)
//		{
//			delete t;
//			t = nullptr;
//		}
//		else if (t->leftChild != nullptr && t->rightChild == nullptr)
//		{
//			BSTNode<Type> *tmp = t;
//			t = t->leftChild;//t��leftChild����rightChild������
//			delete tmp;
//		}
//		else if (t->leftChild == nullptr && t->rightChild != nullptr)
//		{
//			BSTNode<Type> *tmp = t;
//			t = t->rightChild;
//			delete tmp;
//		}
//		else//��Ҫɾ���Ľڵ�������ӽڵ㶼��Ϊ��ʱ���ҵ��ýڵ������������ֵ
//		{
//			BSTNode<Type> *p = t->leftChild;
//			while (p->rightChild != nullptr)
//				p = p->rightChild;
//			t->data = p->data;//Ȼ���������ֵ����Ҫɾ���Ľڵ�
//			Remove(t->leftChild, p->data);//Ȼ���������а�������ֵ��ɾ��
//		}
//	}
//}
