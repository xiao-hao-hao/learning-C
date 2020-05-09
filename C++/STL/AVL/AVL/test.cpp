#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type d = Type(), AVLNode<Type> *left = nullptr, AVLNode<Type> *right = nullptr)
		:data(d), leftChild(left), rightChild(right), bf(0)
	{}
	~AVLNode()
	{}
private:
	Type data;
	int bf;//ƽ������ 0 -1 1 -2 2
	AVLNode<Type> *leftChild;
	AVLNode<Type> *rightChild;
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x);
protected:
	void RotateL(AVLNode<Type> *&ptr);
	void RotateR(AVLNode<Type> *&ptr);
private:
	AVLNode<Type> *root;
};

//����ʵ��
template<class Type>
void AVLTree<Type>::RotateL(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subL = ptr;//��������ת�����ڵ㽫���Ϊ�м�ڵ��������
	ptr = ptr->rightChild;//�м�ڵ�
	subL->rightChild = ptr->leftChild;//���м�ڵ���������ӵ����Ͻǽڵ���ұ�
	ptr->leftChild = subL;//�����Ͻǽڵ�ӵ��м�ڵ�����
	ptr->bf = subL->bf = 0;//�޸�ƽ������
}
template<class Type>
void AVLTree<Type>::RotateR(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subR = ptr;//�����ҵ���ת�����ڵ㽫���Ϊ�м�ڵ��������
	ptr = ptr->leftChild;//�м�ڵ�
	subR->leftChild = ptr->rightChild;//���м�ڵ���������ӵ����Ͻǽڵ�����
	ptr->rightChild = subR;//�����Ͻǽڵ�ӵ��м�ڵ���ұ�
	ptr->bf = subR->bf = 0;
}

template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
{
	//1���ڵ�Ĳ��룬����bst����
	AVLNode<Type> *pr = nullptr;//pr����ǰ�ڵ�ĸ��ڵ�
	AVLNode<Type> *p = t;
	stack<AVLNode<Type>*> st;
	while (p != nullptr)
	{
		if (x == p->data)
			return false;
		pr = p;
		st.push(pr);
		if (x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = new AVLNode<Type>(x);
	//�ж��Ƿ�����Ϊ���ڵ�
	if (pr == nullptr)//���������Ǹ��ڵ㣬���õ���ƽ������
	{
		t = p;
		return true;
	}
	//���ӽڵ�
	if (pr->data > x)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//ƽ�����
	while (!st.empty)
	{
		pr = st.top();
		st.pop();
		if (p == pr->leftChild)//������������ƽ�����Ӽ�1
			--(pr->bf);
		else//������������ƽ�����Ӽ�1
			++(pr->bf);
		if (pr->bf == 0)//��������½ڵ���½ڵ�ĸ��ڵ�ƽ������Ϊ0�������������õ���
			break;
		if (pr->bf==1 || pr->bf==-1)//�������ڵ�ĸ��ڵ�ƽ������Ϊ1��-1����ýڵ㲻�õ���
			p = pr;
		else
		{
			//��ת����
			if (pr->bf > 0)//����ƽ�������жϲ���Ľڵ��·���ϵĲ�ƽ��ڵ����ת��ʽ
			{
				if (p->bf > 0)//����ת�������p->bf�����ܵ���0
					RotateL(pr);
				else//���Һ�������
					RotateRL(pr);
			}
			else
			{
				if (p->bf < 0)//�ҵ���ת�������p->bf�����ܵ���0
					RotateR(pr);
				else//������ҵ����
					RotateLR(pr);
			}
			break;//������ϣ��˳�ѭ��
		}
	}
	//���¶�pr���Ӹ��ڵ�,�������pr�Ѿ���Ϊ�µĸ��ڵ�
	if (st.empty())//ջΪ�գ�˵��pr��Ϊ�µĸ��ڵ�
		t = pr;
	else
	{
		AVLNode<Type> *ppr = st.top();//���µĸ��ڵ�ĸ��ڵ��ջ
		if (ppr->data > pr->data)//���µĸ��ڵ����ӵ�����
			ppr->leftChild = pr;
		else
			ppr->rightChild = pr;
	}
	return true;
}

int main()
{
	vector<int> v = { 10, 7, 3, 5, 20, 13, 16, 19, 23, 14 };
	AVLTree<int> avl;
	for (const auto &e : v)
		avl.Insert(e);
	return 0;
}