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
	int bf;//平衡因子 0 -1 1 -2 2
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

//方法实现
template<class Type>
void AVLTree<Type>::RotateL(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subL = ptr;//对于左单旋转，父节点将会成为中间节点的左子树
	ptr = ptr->rightChild;//中间节点
	subL->rightChild = ptr->leftChild;//把中间节点的左子树接到左上角节点的右边
	ptr->leftChild = subL;//把左上角节点接到中间节点的左边
	ptr->bf = subL->bf = 0;//修改平衡因子
}
template<class Type>
void AVLTree<Type>::RotateR(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subR = ptr;//对于右单旋转，父节点将会成为中间节点的右子树
	ptr = ptr->leftChild;//中间节点
	subR->leftChild = ptr->rightChild;//把中间节点的右子树接到右上角节点的左边
	ptr->rightChild = subR;//把右上角节点接到中间节点的右边
	ptr->bf = subR->bf = 0;
}

template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
{
	//1、节点的插入，按照bst规则
	AVLNode<Type> *pr = nullptr;//pr代表当前节点的父节点
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
	//判断是否插入的为根节点
	if (pr == nullptr)//如果插入的是根节点，则不用调整平衡因子
	{
		t = p;
		return true;
	}
	//链接节点
	if (pr->data > x)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//平衡调整
	while (!st.empty)
	{
		pr = st.top();
		st.pop();
		if (p == pr->leftChild)//插入左子树，平衡因子减1
			--(pr->bf);
		else//插入右子树，平衡因子加1
			++(pr->bf);
		if (pr->bf == 0)//如果插入新节点后新节点的根节点平衡因子为0，则整个树不用调整
			break;
		if (pr->bf==1 || pr->bf==-1)//如果插入节点的父节点平衡因子为1或-1，则该节点不用调整
			p = pr;
		else
		{
			//旋转调整
			if (pr->bf > 0)//根据平衡因子判断插入的节点的路径上的不平衡节点的旋转方式
			{
				if (p->bf > 0)//左单旋转的情况，p->bf不可能等于0
					RotateL(pr);
				else//先右后左的情况
					RotateRL(pr);
			}
			else
			{
				if (p->bf < 0)//右单旋转的情况，p->bf不可能等于0
					RotateR(pr);
				else//先左后右的情况
					RotateLR(pr);
			}
			break;//调整完毕，退出循环
		}
	}
	//重新对pr链接父节点,调整完后，pr已经成为新的父节点
	if (st.empty())//栈为空，说明pr成为新的根节点
		t = pr;
	else
	{
		AVLNode<Type> *ppr = st.top();//将新的父节点的父节点出栈
		if (ppr->data > pr->data)//将新的父节点链接到树中
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