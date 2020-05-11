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
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x);
	bool Remove(AVLNode<Type> *&t, const Type &key);
protected:
	void RotateL(AVLNode<Type> *&ptr);
	void RotateR(AVLNode<Type> *&ptr);
	void RotateLR(AVLNode<Type> *&ptr);
	void RotateRL(AVLNode<Type> *&ptr);
private:
	AVLNode<Type> *root;
};

//方法实现
template<class Type>
void AVLTree<Type>::RotateL(AVLNode<Type> *&ptr)//对于左单旋，中间节点肯定是父节点的右子节点
{     //因为父节点的平衡因子为2，新插入的节点只可能在它的右子树，所以插入路径应该走右子树
	AVLNode<Type> *subL = ptr;//对于左单旋转，父节点将会成为中间节点的左子树
	ptr = ptr->rightChild;//中间节点
	//因为中间节点的平衡因子大于0，所以插入路径一定是它的右子树，三个节点形成形状 "\"
	subL->rightChild = ptr->leftChild;//把中间节点的左子树接到左上角节点的右边
	ptr->leftChild = subL;//把左上角节点接到中间节点的左边
	ptr->bf = subL->bf = 0;//修改平衡因子，单旋转，最后的平衡因子是0，只修改不平衡位置的平衡因子，其他地方的不用改变
}
template<class Type>
void AVLTree<Type>::RotateR(AVLNode<Type> *&ptr)//对于右单旋，中间节点肯定是父节点的左子节点
{    //因为父节点的平衡因子为-2，新插入的节点只可能在它的左子树，所以插入路径应该走左子树
	AVLNode<Type> *subR = ptr;//对于右单旋转，父节点将会成为中间节点的右子树
	ptr = ptr->leftChild;//中间节点
	//因为中间节点的平衡因子小于0，所以插入路径一定是它的左子树，三个节点形成形状 "/"
	subR->leftChild = ptr->rightChild;//把中间节点的右子树接到右上角节点的左边
	ptr->rightChild = subR;//把右上角节点接到中间节点的右边
	ptr->bf = subR->bf = 0;
}
template<class Type>
void AVLTree<Type>::RotateLR(AVLNode<Type> *&ptr)//三个节点组成的形状为 <
{
	AVLNode<Type> *subL = ptr->leftChild;//旋转后的左子树
	AVLNode<Type> *subR = ptr;//旋转后的右子树
	ptr = subL->rightChild;//旋转后的父节点

	//先左转
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//subL bf
	if (ptr->bf == 1)//如果为1，说明插到右子树，没有节点要挂到subL的右树
		subL->bf = -1;
	else//否则，说明插到左子树，有节点要挂到subL的右树，平衡因子变为0
		subL->bf = 0;
	//后右转
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//subR bf
	if (ptr->bf == -1)//说明插到左边，没有节点挂到subR上
		subR->bf = 1;
	else//否则，说明有挂到subR的左子树上，平衡因子变为0
		subR->bf = 0;
	ptr->bf = 0;//根节点调整完了平衡因子都是0
}
template<class Type>
void AVLTree<Type>::RotateRL(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subL = ptr;
	AVLNode<Type> *subR = ptr->rightChild;
	ptr = subR->leftChild;
	//先右转
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//subR bf
	if (ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;
	//后左转
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//subL bf 根据新父节点旋转前的平衡因子三种情况来处理
	if (ptr->bf <= 0)//也是三种情况，和RotateLR判断一样，只是不同的写法
		subL->bf = 0;
	else
		subL->bf = -1;
	ptr->bf = 0;
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
	//pr->bf>0&&p->bf>0->'\' pr->bf>0&&p->bf<0->'>' 
	//pr->bf<0&&p->bf<0->'/' pr->bf<0&&p->bf>0->'<'
	while (!st.empty())
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
		else  //每次传入pr的引用，然后pr被改成旋转后新的父节点的指针
		{
			//旋转调整
			if (pr->bf > 0)//根据平衡因子判断插入的节点的路径上的不平衡节点的旋转方式
			{
				if (p->bf > 0)//左单旋转的情况，p->bf不可能等于0
					RotateL(pr);  //   \   
				else//先右后左的情况
					RotateRL(pr); //   >
			}
			else
			{
				if (p->bf < 0)//右单旋转的情况，p->bf不可能等于0
					RotateR(pr); //   /
				else//先左后右的情况
					RotateLR(pr);//    <
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

template<class Type>
bool AVLTree<Type>::Remove(AVLNode<Type> *&t, const Type &key)
{
	AVLNode<Type> *pr = nullptr, *p = t, *q = nullptr;
	int d;
	stack<AVLNode<int>*> st;
	while (p != nullptr)//寻找删除位置
	{
		if (key == p->data)//找到后停止搜索
			break;
		pr = p;
		st.push(pr);
		if (key > p->data)
			p = p->rightChild;
		else
			p = p->leftChild;
		if (p == nullptr)//未找到删除节点，删除失败
			return false;
		if (p->leftChild!=nullptr && p->rightChild!=nullptr)//被删节点有两个子女
		{
			pr = p;
			st.push(pr);
			while(q->rightChild != nullptr)//在p的左树找p的直接前驱
			{
				pr = q;
				st.push(pr);
				q = q->rightChild;
			}
			p->data = q->data;//将p的直接前驱的值赋给p
			p = q;//将删除p转化为删除q
		}
		if (p->leftChild != nullptr)//被删节点p只有一个子女q
			q = p->leftChild;
		else if (p->rightChild != nullptr)
			q = p->rightChild;
		if (pr == nullptr)//被删节点为根节点(此时树只有一个根节点或只有两个节点),此时不需要调整
			t = q;
		else//被删节点不是根节点
		{
			if (pr->leftChild == p)//链接
				pr->leftChild = q;
			else
				pr->rightChild = q;
			//重新平衡化调整
			while (!st.empty())
			{
				pr = st.top();//从栈中退出父节点
				st.pop();
				d = pr->bf;//将修改前的平衡因子记录下来
				if (pr->rightChild == q)//修改父节点的平衡因子
					--(pr->bf);
				else
					++(pr->bf);
				if (d == 0)//pr原来的平衡因子是0，结束平衡调整过程
					break;
				else if (d!=0 && pr->bf!=0)//节点pr的平衡因子原不为0，且较矮的子树被缩短
				{
					if (d > 0)//q指向pr较高子树根节点
						q = pr->rightChild;
					else
						q = pr->leftChild;
					if (q->bf==0 && d>0)
					{
						RotateL(pr);
					}
					else if (q->bf==0 && d<0)
					{
						RotateR(pr);
					}
				}
				q = pr;//用于下一次父节点出栈调整平衡因子
			}
		}
	}
	delete p;
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