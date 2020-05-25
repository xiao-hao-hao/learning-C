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
	void TreeDestroy(AVLNode<Type> *&t);//����һ�Ŷ�����
protected:
	void RotateL(AVLNode<Type> *&ptr);
	void RotateR(AVLNode<Type> *&ptr);
	void RotateLR(AVLNode<Type> *&ptr);
	void RotateRL(AVLNode<Type> *&ptr);
private:
	AVLNode<Type> *root;
};

//����ʵ��
template<class Type>
void AVLTree<Type>::RotateL(AVLNode<Type> *&ptr)//�����������м�ڵ�϶��Ǹ��ڵ�����ӽڵ�
{     //��Ϊ���ڵ��ƽ������Ϊ2���²���Ľڵ�ֻ���������������������Բ���·��Ӧ����������
	AVLNode<Type> *subL = ptr;//��������ת�����ڵ㽫���Ϊ�м�ڵ��������
	ptr = ptr->rightChild;//�м�ڵ�
	//��Ϊ�м�ڵ��ƽ�����Ӵ���0�����Բ���·��һ���������������������ڵ��γ���״ "\"
	subL->rightChild = ptr->leftChild;//���м�ڵ���������ӵ����Ͻǽڵ���ұ�
	ptr->leftChild = subL;//�����Ͻǽڵ�ӵ��м�ڵ�����
	ptr->bf = subL->bf = 0;//�޸�ƽ�����ӣ�����ת������ƽ��������0��ֻ�޸Ĳ�ƽ��λ�õ�ƽ�����ӣ������ط��Ĳ��øı�
}
template<class Type>
void AVLTree<Type>::RotateR(AVLNode<Type> *&ptr)//�����ҵ������м�ڵ�϶��Ǹ��ڵ�����ӽڵ�
{    //��Ϊ���ڵ��ƽ������Ϊ-2���²���Ľڵ�ֻ���������������������Բ���·��Ӧ����������
	AVLNode<Type> *subR = ptr;//�����ҵ���ת�����ڵ㽫���Ϊ�м�ڵ��������
	ptr = ptr->leftChild;//�м�ڵ�
	//��Ϊ�м�ڵ��ƽ������С��0�����Բ���·��һ���������������������ڵ��γ���״ "/"
	subR->leftChild = ptr->rightChild;//���м�ڵ���������ӵ����Ͻǽڵ�����
	ptr->rightChild = subR;//�����Ͻǽڵ�ӵ��м�ڵ���ұ�
	ptr->bf = subR->bf = 0;
}
template<class Type>
void AVLTree<Type>::RotateLR(AVLNode<Type> *&ptr)//�����ڵ���ɵ���״Ϊ <
{
	AVLNode<Type> *subL = ptr->leftChild;//��ת���������
	AVLNode<Type> *subR = ptr;//��ת���������
	ptr = subL->rightChild;//��ת��ĸ��ڵ�

	//����ת
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//subL bf
	if (ptr->bf == 1)//���Ϊ1��˵���嵽��������û�нڵ�Ҫ�ҵ�subL������
		subL->bf = -1;
	else//����˵���嵽���������нڵ�Ҫ�ҵ�subL��������ƽ�����ӱ�Ϊ0
		subL->bf = 0;
	//����ת
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//subR bf
	if (ptr->bf == -1)//˵���嵽��ߣ�û�нڵ�ҵ�subR��
		subR->bf = 1;
	else//����˵���йҵ�subR���������ϣ�ƽ�����ӱ�Ϊ0
		subR->bf = 0;
	ptr->bf = 0;//���ڵ��������ƽ�����Ӷ���0
}
template<class Type>
void AVLTree<Type>::RotateRL(AVLNode<Type> *&ptr)
{
	AVLNode<Type> *subL = ptr;
	AVLNode<Type> *subR = ptr->rightChild;
	ptr = subR->leftChild;
	//����ת
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//subR bf
	if (ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;
	//����ת
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//subL bf �����¸��ڵ���תǰ��ƽ�������������������
	if (ptr->bf <= 0)//Ҳ�������������RotateLR�ж�һ����ֻ�ǲ�ͬ��д��
		subL->bf = 0;
	else
		subL->bf = -1;
	ptr->bf = 0;
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
	//pr->bf>0&&p->bf>0->'\' pr->bf>0&&p->bf<0->'>' 
	//pr->bf<0&&p->bf<0->'/' pr->bf<0&&p->bf>0->'<'
	while (!st.empty())
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
		else  //ÿ�δ���pr�����ã�Ȼ��pr���ĳ���ת���µĸ��ڵ��ָ��
		{
			//��ת����
			if (pr->bf > 0)//����ƽ�������жϲ���Ľڵ��·���ϵĲ�ƽ��ڵ����ת��ʽ
			{
				if (p->bf > 0)//����ת�������p->bf�����ܵ���0
					RotateL(pr);  //   \   
				else//���Һ�������
					RotateRL(pr); //   >
			}
			else
			{
				if (p->bf < 0)//�ҵ���ת�������p->bf�����ܵ���0
					RotateR(pr); //   /
				else//������ҵ����
					RotateLR(pr);//    <
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

template<class Type>
bool AVLTree<Type>::Remove(AVLNode<Type> *&t, const Type &key)
{
	AVLNode<Type> *pr = nullptr, *p = t, *q = nullptr;
	stack<AVLNode<int>*> st;
	while (p != nullptr)//Ѱ��ɾ��λ��
	{
		if (key == p->data)//�ҵ���ֹͣ����
			break;
		pr = p;
		st.push(pr);
		if (key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if (p == nullptr)//δ�ҵ�ɾ���ڵ㣬ɾ��ʧ��
		return false;
	//�����ɾ�ڵ���������Ů��ת��Ϊɾ��һ����Ů����û����Ů�Ľڵ�
	if (p->leftChild!=nullptr && p->rightChild!=nullptr)//��ɾ�ڵ���������Ů
	{
		pr = p;
		st.push(pr);
		q = p->rightChild;
		while(q->leftChild != nullptr)//��p��������p��ֱ�Ӻ��
		{
			pr = q;
			st.push(pr);
			q = q->leftChild;
		}
		p->data = q->data;//��p��ֱ�Ӻ�̵�ֵ����p
		p = q;//��ɾ��pת��Ϊɾ��q
	}
	if (p->leftChild != nullptr)//��ɾ�ڵ�pֻ��һ����Ůq
		q = p->leftChild;
	else
		q = p->rightChild;
	//pΪ��ɾ�ڵ㣬qΪɾ���ڵ����Ů�ڵ�
	if (pr == nullptr)//��ɾ�ڵ�Ϊ���ڵ㣬��ʱ����Ҫ����
		t = q;
	else//��ɾ�ڵ㲻�Ǹ��ڵ�
	{
		if (pr->leftChild == p)//����
			pr->leftChild = q;
		else
			pr->rightChild = q;
		//����ƽ�⻯����
		while (!st.empty())
		{
			pr = st.top();//��ջ���˳����ڵ�
			st.pop();
			//���qΪ�գ�prû���Һ��ӣ�����û�к��ӣ���ô���޷�����ɾ���ı�
			//if (pr->rightChild == q)//�޸ĸ��ڵ��ƽ������
			//	--(pr->bf);
			//else
			//	++(pr->bf);
			if (p->data < pr->data)
				++(pr->bf);
			else
				--(pr->bf);
			if (pr->bf==1 || pr->bf==-1)//��1)|bf|=1  ����Ҫ����ƽ�����
				break;
			//if (pr->bf == 0) (2)��������ڵ�pr�ĸ��ڵ��ƽ��״̬
			if (pr->bf != 0)//(3) |bf|=2
			{
				if (pr->bf < 0)
					q = pr->leftChild;//��qָʾ�ϸߵ�����
				else
					q = pr->rightChild;
				if (q->bf == 0)//1
				{
					if (pr->bf < 0)
					{
						RotateR(pr);//Ҫע��pr��ת���µĸ��ڵ�
						pr->bf = 1;
						pr->rightChild->bf = -1;
					}
					else
					{
						RotateL(pr);
						pr->bf = -1;
						pr->leftChild->bf = 1;
					}
					if (!st.empty())//��û�е��������ڵ��ʱ������
					{
						AVLNode<Type> *ppr = st.top();
						if (ppr->data > pr->data)
							ppr->leftChild = pr;
						else
							ppr->rightChild = pr;//��ת���¸����ϲ�����
					}
					break;
				}
				if ((q->bf)*(pr->bf) > 0)//  2  pr��q��ƽ������ͬ��
				{
					if (q->bf > 0)//ͬΪ��
						RotateL(pr);
					else//ͬΪ��
						RotateR(pr);
				}
				else//  3  pr��q��ƽ���������
				{
					if (q->bf > 0)
						RotateLR(pr);   //  <
					else
						RotateRL(pr);  //  >
				}
				if (!st.empty())//��û�е��������ڵ��ʱ������
				{
					AVLNode<Type> *ppr = st.top();
					if (ppr->data > pr->data)
						ppr->leftChild = pr;
					else
						ppr->rightChild = pr;//��ת���¸����ϲ�����
				}
			}
			q = pr;//������һ�θ��ڵ��ջ����ƽ������
		}
		if (st.empty())
			t = pr;//�����������ĸ��ڵ�
	}
	delete p;
	return true;
}

//����������������ƣ�����������������������������������ٸ��ڵ����Ҳ������Һ���
//�����ٵ�ʱ����Ҫ�������Һ��ӵĵ�ַ����˲��ú����������һ�Ŷ����������������Һ�
//�Ӹ��ڵ��˳������,��󽫸��ڵ�ָ��գ���ֹ��ΪҰָ��
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