#include <iostream>
#include <vector>
#include <stack>
#include <vld.h>
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
	void TreeDestroy()
	{
		TreeDestroy(root);
	}
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x);
	bool Remove(AVLNode<Type> *&t, const Type &key);
	void TreeDestroy(AVLNode<Type> *&t);//销毁一颗二叉树
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
	stack<AVLNode<int>*> st;
	while (p != nullptr)//寻找删除位置
	{
		if (key == p->data)//找到后停止搜索
			break;
		pr = p;
		st.push(pr);
		if (key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if (p == nullptr)//未找到删除节点，删除失败
		return false;
	//如果被删节点有两个子女，转换为删有一个子女或者没有子女的节点
	if (p->leftChild!=nullptr && p->rightChild!=nullptr)//被删节点有两个子女
	{
		pr = p;
		st.push(pr);
		q = p->rightChild;
		while(q->leftChild != nullptr)//在p的右树找p的直接后继
		{
			pr = q;
			st.push(pr);
			q = q->leftChild;
		}
		p->data = q->data;//将p的直接后继的值赋给p
		p = q;//将删除p转化为删除q
	}
	if (p->leftChild != nullptr)//被删节点p只有一个子女q
		q = p->leftChild;
	else
		q = p->rightChild;
	//p为被删节点，q为删除节点的子女节点
	if (pr == nullptr)//被删节点为根节点，此时不需要调整
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
			//如果q为空，pr没有右孩子，左孩子没有孩子，那么会无法区分删除哪边
			//if (pr->rightChild == q)//修改父节点的平衡因子
			//	--(pr->bf);
			//else
			//	++(pr->bf);
			if (p->data < pr->data)
				++(pr->bf);
			else
				--(pr->bf);
			if (pr->bf==1 || pr->bf==-1)//（1)|bf|=1  不需要进行平衡调整
				break;
			//if (pr->bf == 0) (2)继续考察节点pr的父节点的平衡状态
			if (pr->bf != 0)//(3) |bf|=2
			{
				if (pr->bf < 0)
					q = pr->leftChild;//用q指示较高的子树
				else
					q = pr->rightChild;
				if (q->bf == 0)//1
				{
					if (pr->bf < 0)
					{
						RotateR(pr);//要注意pr是转后新的父节点
						pr->bf = 1;
						pr->rightChild->bf = -1;
					}
					else
					{
						RotateL(pr);
						pr->bf = -1;
						pr->leftChild->bf = 1;
					}
					if (!st.empty())//在没有调整到根节点的时候链接
					{
						AVLNode<Type> *ppr = st.top();
						if (ppr->data > pr->data)
							ppr->leftChild = pr;
						else
							ppr->rightChild = pr;//旋转后新根与上层链接
					}
					break;
				}
				if ((q->bf)*(pr->bf) > 0)//  2  pr和q的平衡因子同号
				{
					if (q->bf > 0)//同为正
						RotateL(pr);
					else//同为负
						RotateR(pr);
				}
				else//  3  pr和q的平衡因子异号
				{
					if (q->bf > 0)
						RotateLR(pr);   //  <
					else
						RotateRL(pr);  //  >
				}
				if (!st.empty())//在没有调整到根节点的时候链接
				{
					AVLNode<Type> *ppr = st.top();
					if (ppr->data > pr->data)
						ppr->leftChild = pr;
					else
						ppr->rightChild = pr;//旋转后新根与上层链接
				}
			}
			q = pr;//用于下一次父节点出栈调整平衡因子
		}
		if (st.empty())
			t = pr;//调整到了树的根节点
	}
	delete p;
	return true;
}

//销毁与遍历操作类似，但是如果采用先序遍历或者中序遍历，销毁根节点后就找不到左右孩子
//在销毁的时候需要保存左右孩子的地址，因此采用后序遍历销毁一颗二叉树，按照左孩子右孩
//子根节点的顺序销毁,最后将根节点指向空，防止成为野指针
template<class Type>
void AVLTree<Type>::TreeDestroy(AVLNode<Type> *&t)
{
	if (t == nullptr)
		return;
	TreeDestroy(t->leftChild);
	TreeDestroy(t->rightChild);
	delete t;
	t = nullptr;
}

int main()
{
	vector<int> v = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int> avl;
	for (const auto &e : v)
		avl.Insert(e);
	avl.Remove(14);
	avl.Remove(16);
	avl.Remove(15);
	avl.Remove(26);
	avl.Remove(18);
	avl.TreeDestroy();
	return 0;
}