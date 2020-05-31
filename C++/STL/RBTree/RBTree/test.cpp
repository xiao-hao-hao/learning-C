//#include <iostream>
//#include <vector>
//using namespace std;
//
//typedef enum {RED=0, BLACK=1} Color_Type;
//
//template<class Type>
//class RBTree;
//
//template<class Type>
//class rb_iterator;
//
////每次以红色节点插入，因为红色插入可能不需要调整，但是黑色插入每次都得调整
//template<class Type>
//class RBTreeNode
//{
//	friend class RBTree<Type>;
//	friend class rb_iterator<Type>;
//public:
//	RBTreeNode(const Type &d=Type())
//		: data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr), color(RED)
//	{}
//	~RBTreeNode()
//	{}
//private:
//	Type data;
//	RBTreeNode<Type> *leftChild;
//	RBTreeNode<Type> *rightChild;
//	RBTreeNode<Type> *parent;
//	Color_Type color;
//};
//
//////////////////////////////////////////////////////////////////////////
//template<class Type>
//class rb_iterator
//{
//	typedef rb_iterator<Type> self;
//public:
//	rb_iterator(RBTreeNode<Type> *p, RBTreeNode<Type> *nil, RBTreeNode<Type> *enode)
//		: node(p), NIL(nil), end_node(enode)
//	{}
//	Type& operator*()
//	{
//		return node->data;
//	}
//	RBTreeNode<Type>* operator->()
//	{
//		return node;
//	}
//
//	self& operator++()
//	{
//		increment();
//		return *this;
//	}
//	self operator++(int);
//	self& operator--()
//	{
//		decrement();
//		return *this;
//	}
//	self operator--(int);
//
//	bool operator==(self & it)
//	{
//		return node == it.node;
//	}
//	bool operator!=(self & it)
//	{
//		return node != it.node;
//	}
//protected:
//	void increment()
//	{
//		if (node->rightChild != NIL)
//		{
//			node = node->rightChild;
//			if (node == end_node)
//				return;
//			while (node->leftChild != NIL)
//				node = node->leftChild;
//		}
//		else
//		{
//			RBTreeNode<Type> *pr = node->parent;
//			while (node == pr->rightChild)
//			{
//				node = pr;
//				pr = node->parent;
//			}
//			node = pr;
//		}
//	}
//	void decrement()
//	{
//		if (node->leftChild != NIL)
//		{
//			node = node->leftChild;
//			while (node->rightChild != NIL)
//				node = node->rightChild;
//		}
//		else
//		{
//			RBTreeNode<Type> *pr = node->parent;
//			while (node == pr->leftChild)
//			{
//				node = pr;
//				pr = node->parent;
//			}
//			node = pr;
//		}
//	}
//private:
//	RBTreeNode<Type> *node;
//	RBTreeNode<Type> *NIL;
//	RBTreeNode<Type> *end_node;
//};
//
//template<class Type>
//class RBTree
//{
//public:
//	typedef rb_iterator<Type> iterator;
//	RBTree() : NIL(_Buynode()), root(NIL), end_node(_Buynode())
//	{
//		NIL->parent = NIL->leftChild = NIL->rightChild = nullptr;
//		NIL->color = BLACK;
//		end_node->leftChild = end_node->rightChild = end_node->parent = NIL;
//	}
//public:
//	iterator begin()
//	{
//		RBTreeNode<Type> *p = root;
//		while (p!=NIL && p->leftChild!=NIL)
//			p = p->leftChild;
//		return iterator(p, NIL, end_node);
//	}
//	iterator end()
//	{
//		return iterator(end_node, NIL, end_node);
//	}
//	void set_endnode()
//	{
//		RBTreeNode<Type> *p = root;
//		while (p!=NIL && p->rightChild!=NIL)
//			p = p->rightChild;
//		p->rightChild = end_node;
//		end_node->parent = p;
//	}
//public:
//	bool Insert(const Type &x)
//	{
//		return Insert(root, x);
//	}
//	bool Remove(const Type &key)
//	{
//		return Remove(root, key);
//	}
//protected:
//	bool Insert(RBTreeNode<Type> *&t, const Type &x);
//	void Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
//protected:
//	bool Remove(RBTreeNode<Type> *&t, const Type &key);
//	void Remove_FixUp(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
//protected:
//	void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
//	void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
//protected:
//	RBTreeNode<Type>* _Buynode(const Type &x = Type())
//	{
//		RBTreeNode<Type> *s = new RBTreeNode<Type>(x);
//		s->leftChild = s->rightChild = NIL;
//		return s;
//	}
//private:
//	RBTreeNode<Type> *NIL;
//	RBTreeNode<Type> *root;
//	RBTreeNode<Type> *end_node;
//};
//
//template<class Type>
//bool RBTree<Type>::Insert(RBTreeNode<Type> *&t, const Type &x)
//{
//	//1 根据bst的规则插入数据
//	RBTreeNode<Type> *pr = NIL;
//	RBTreeNode<Type> *s = t;
//	while (s != NIL)
//	{
//		if (x == s->data)
//			return false;
//		pr = s;
//		if (x < s->data)
//			s = s->leftChild;
//		else
//			s = s->rightChild;
//	}
//	s = _Buynode(x);
//	if (pr == NIL)//插入的为根节点
//	{
//		t = s;
//		t->parent = NIL;
//	}
//	else if (x < pr->data)
//		pr->leftChild = s;
//	else
//		pr->rightChild = s;
//	s->parent = pr;
//
//	//2 调整平衡
//	Insert_Fixup(t, s);
//	return true;
//}
//
//template<class Type>
//void RBTree<Type>::Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
//{
//	while (x->parent->color == RED)
//	{
//		RBTreeNode<Type> *s;//叔伯节点
//		if (x->parent == x->parent->parent->leftChild)//左分支
//		{
//			s = x->parent->parent->rightChild;
//			if (s->color == RED)
//			{
//				//状况三  只需要调整颜色，不需要旋转
//				x->parent->color = BLACK;
//				s->color = BLACK;
//				x->parent->parent->color = RED;
//				x = x->parent->parent;
//				continue;
//			}
//			else if (x == x->parent->rightChild)
//			{
//				//状况二 先左单后右单，利用状况一进行右单
//				x = x->parent;
//				LeftRotate(t, x);
//			}
//			//状况一
//			x->parent->color = BLACK;       //该X的颜色
//			x->parent->parent->color = RED; //改G的颜色
//			RightRotate(t, x->parent->parent);
//		}
//		else//右分支
//		{
//			s = x->parent->parent->leftChild;
//			if (s->color == RED)
//			{
//				x->parent->color = BLACK;
//				s->color = BLACK;
//				x->parent->parent->color = RED;
//				x = x->parent->parent;
//				continue;
//			}
//			else if (x == x->parent->leftChild)
//			{
//				x = x->parent;
//				RightRotate(t, x);
//			}
//			x->parent->color = BLACK;
//			x->parent->parent->color = RED;
//			LeftRotate(t, x->parent->parent);
//		}
//	}
//	t->color = BLACK;
//}
//
//template<class Type>
//bool RBTree<Type>::Remove(RBTreeNode<Type> *&t, const Type &key)
//{
//	//1 根据bst删除节点
//	RBTreeNode<Type> *p = t, *q, *c;
//	while (p!=NIL && p->data!=key)
//	{
//		if (key < p->data)
//			p = p->leftChild;
//		else
//			p = p->rightChild;
//	}
//	if (p == NIL)
//		return false;
//
//	//把删除的节点化解为最终只有一个子女节点
//	if (p->leftChild!=NIL && p->rightChild!=NIL)//把组合5&6化解
//	{
//		q = p->rightChild;
//		while (q->leftChild != NIL)
//			q = q->leftChild;
//	}
//	else
//		q = p;
//	if (q->leftChild != NIL)
//		c = q->leftChild;
//	else
//		c = q->rightChild;
//	//if (c != NIL)//被删节点没有子节点则不用执行这一步
//		c->parent = q->parent;
//	if (q->parent == NIL)
//		t = c;
//	else if (q = q->parent->leftChild)
//		q->parent->leftChild = c;
//	else
//		q->parent->rightChild = c;
//	if (p != q)
//		p->data = q->data;
//	//2 调整平衡
//	if (q->color == BLACK)//删除节点的颜色是黑色，需要进行调整
//		Remove_FixUp(t, c);
//	//组合1直接删除
//	delete q;
//	return true;
//}
//
////删除节点为红色节点则不可能有子女节点
//template<class Type>
//void RBTree<Type>::Remove_FixUp(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
//{
//	RBTreeNode<Type> *w;//兄弟节点
//	while (x!=t && x->color==BLACK)//组合2：因为x只可能是NIL
//	{
//		if (x == x->parent->leftChild)
//		{
//			//左分支
//			w = x->parent->rightChild;
//			//情形四:转换成了情况一、二、三中的一种
//			if (w->color == RED)
//			{
//				w->color = BLACK;
//				x->parent->color = RED;
//				LeftRotate(t, x->parent);
//				w = x->parent->rightChild;
//			}
//			//情形三：brother没有子节点
//			//这里没有写father为红的情况是因为循环回去会在while那里判断
//			if (w->leftChild->color==BLACK && w->rightChild->color==BLACK)//w没有子节点
//			{
//				w->color = RED;
//				x = x->parent;
//			}
//			else//brother有子节点，brother为黑色，子节点一定为红色,
//			{   //因为子节点如果为黑色说明在删除前树就是不平衡的
//				//情形二：方向不一致，两次旋转
//				if (w->leftChild->color == RED)//包含左节点为红色且无右节点和左右节点都有且都是红色两种情况
//				{
//					w->leftChild->color = BLACK;
//					w->color = RED;
//					RightRotate(t, w);
//					w = x->parent->rightChild;
//				}
//				//情形一：方向一致，一次旋转
//				w->color = x->parent->color;
//				x->parent->color = BLACK;
//				w->rightChild->color = BLACK;
//				LeftRotate(t, x->parent);
//				x = t;
//			}
//		}
//		else
//		{
//			//右分支
//			w = x->parent->leftChild;
//			//情形四
//			if (w->color == RED)
//			{
//				w->color = BLACK;
//				x->parent->color = RED;
//				RightRotate(t, x->parent);
//				w = x->parent->leftChild;
//			}
//			//情形三
//			if (w->rightChild->color == BLACK && w->rightChild->color == BLACK)
//			{
//				w->color = RED;
//				x = x->parent;
//			}
//			else
//			{
//				//情形二
//				if (w->rightChild->color == RED)
//				{
//					w->rightChild->color = BLACK;
//					w->color = RED;
//					LeftRotate(t, w);
//					w = x->parent->leftChild;
//				}
//				//情形一
//				w->color = x->parent->color;
//				x->parent->color = BLACK;
//				w->leftChild->color = BLACK;
//				RightRotate(t, x->parent);
//				x = t;
//			}
//		}
//	}
//	x->color = BLACK;//组合4
//}
//
//template<class Type>
//void RBTree<Type>::LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
//{
//	RBTreeNode<Type> *s = p->rightChild;
//	p->rightChild = s->leftChild;
//	if (s->leftChild != NIL)
//		s->leftChild->parent = p;
//	s->parent = p->parent;
//	if (p->parent == NIL)//如果p是根节点
//		t = s;
//	else if (p == p->parent->leftChild)
//		p->parent->leftChild = s;
//	else
//		p->parent->rightChild = s;
//	s->leftChild = p;
//	p->parent = s;
//}
//
//template<class Type>
//void RBTree<Type>::RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
//{
//	RBTreeNode<Type> *s = p->leftChild;
//	p->leftChild = s->rightChild;
//	if (s->rightChild != NIL)
//		s->rightChild->parent = p;
//	s->parent = p->parent;
//	if (p->parent == NIL)
//		t = s;
//	else if (p == p->parent->leftChild)
//		p->parent->leftChild = s;
//	else
//		p->parent->rightChild = s;
//	s->rightChild = p;
//	p->parent = s;
//}
//
//int main()
//{
//	vector<int> v = {10, 7, 4, 20, 13};
//	RBTree<int> rb;
//	for (const auto &e : v)
//		rb.Insert(e);
//	//rb.set_endnode();
//	//auto it = rb.begin();
//	//while (it != rb.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	cout << endl;
//	rb.Remove(20);
//	rb.set_endnode();
//	auto it = rb.begin();
//	while (it != rb.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	return 0;
//}