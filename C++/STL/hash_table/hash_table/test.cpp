#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
	53, 97, 193, 389, 769,
	1543, 3079, 6151, 12289, 24593,
	49157, 98317, 196613, 393241, 786433,
	1572869, 3145739, 6291469, 12582917, 25165843,
	50331653, 100663319, 201326611, 402653189, 805306457,
	1610612741, 3221225473ul, 4294967291ul
};
inline unsigned long __stl_next_prime(unsigned long n)
{
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	//返回值是一个迭代器, 返回指向大于等于key的第一个值的位置
	//如果所有val都小于key,返回last的位置
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}


template <class Value>
struct __hashtable_node
{
	__hashtable_node* next;
	Value val;
};

template <class Key, class Value, class HashFcn, class ExtractKey>
class hashtable;

/////////////////////////////////////////////////////////////////////////////////////
template <class Key, class Value, class HashFcn, class ExtractKey>
struct __hashtable_iterator
{
	typedef hashtable<Key, Value, HashFcn, ExtractKey> hashtable;
	typedef __hashtable_iterator<Key, Value, HashFcn, ExtractKey> iterator;
	typedef __hashtable_node<Value> node;
	typedef Value&  reference;
	typedef Value* pointer;
	typedef size_t size_type;


	node* cur;
	hashtable* ht;

	__hashtable_iterator(node* n, hashtable* tab) : cur(n), ht(tab)
	{}
	__hashtable_iterator()
	{}
	reference operator*() const
	{
		return cur->val;
	}
	pointer operator->() const
	{
		return &(operator*());
	}

	iterator& operator++()
	{
		const node* old = cur;
		cur = cur->next;
		if (!cur)
		{
			size_type bucket = ht->bkt_num(old->val);//求得原数据的桶号
			//当cur为空且到最后一个桶时才会返回指向空的迭代器
			while (!cur && ++bucket < ht->buckets.size())
				cur = ht->buckets[bucket];
		}
		return *this;//返回迭代器对象的引用
	}
	iterator operator++(int);
	bool operator==(const iterator& it) const
	{
		return cur == it.cur;
	}
	bool operator!=(const iterator& it) const
	{
		return cur != it.cur;
	}
};
//////////////////////////////////////////////////////////////////////////////////////////

//key-value
template <class Key, class Value, class HashFcn, class ExtractKey>
class hashtable
{
	friend struct __hashtable_iterator<Key, Value, HashFcn, ExtractKey>;
public:
	typedef __hashtable_node<Value> node;
	typedef size_t size_type;
	typedef Value  value_type;
	typedef Key    key_type;

	typedef HashFcn hasher;

	typedef __hashtable_iterator<Key, Value, HashFcn, ExtractKey> iterator;

public:
	hashtable(size_type n) //哈希表桶个数初始化
	{
		initialize_buckets(n);
	}
	void print_hashtable()
	{
		for (int i = 0; i < buckets.size(); ++i)
		{
			cout << i << ":";
			node *p = buckets[i];
			while (p != NULL)
			{
				cout << p->val << "->";
				p = p->next;
			}
			cout << "Nil" << endl;

		}
	}
public:
	iterator begin()
	{
		node *p;
		for (int i = 0; i < buckets.size(); ++i)
		{
			p = buckets[i];
			if (p != NULL)
				break;
		}
		return iterator(p, this);
	}
	iterator end()
	{
		return iterator(0, this);//最后一个元素的下一个是空
	}
public:
	bool insert_unique(const value_type& obj)//插入唯一值
	{
		resize(num_elements + 1);
		return insert_unique_noresize(obj);
	}
	bool insert_unique_noresize(const value_type& obj)
	{
		const size_type n = bkt_num(obj);//求桶号
		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
			if (cur->val == obj)//不能插入相同值
				return false;

		node* tmp = new_node(obj);//头插
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return true;
	}

	iterator insert_equal(const value_type& obj)//插入不唯一值
	{
		resize(num_elements + 1);//在插入之前调整桶个数
		return insert_equal_noresize(obj);
	}
	iterator insert_equal_noresize(const value_type& obj)
	{
		const size_type n = bkt_num(obj);
		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
		{
			if (get_key(cur->val) == get_key(obj))//如果有相同值，则相同值相连(这里只能处理整数)
			{
				node* tmp = new_node(obj);
				tmp->next = cur->next;
				cur->next = tmp;
				++num_elements;
				return iterator(tmp, this);
			}
		}

		node* tmp = new_node(obj);//没有相同值则头插
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return iterator(tmp, this);
	}
private:
	void resize(size_type num_elements_hint);

	size_type bkt_num_key(const key_type& key) const
	{
		return bkt_num_key(key, buckets.size());
	}
	size_type bkt_num(const value_type& obj) const
	{
		return bkt_num_key(get_key(obj));//先取得关键值，再求桶号
	}
	size_type bkt_num_key(const key_type& key, size_t n) const
	{
		return hash(key) % n;//由关键值求桶号
	}
	size_type bkt_num(const value_type& obj, size_t n) const
	{
		return bkt_num_key(get_key(obj), n);
	}
	node* new_node(const value_type& obj)
	{
		node* n = (node*)malloc(sizeof(node));
		n->next = 0;
		n->val = obj;
		return n;
	}
	size_type next_size(size_type n) const
	{
		return __stl_next_prime(n);
	}
	void initialize_buckets(size_type n)
	{
		const size_type n_buckets = next_size(n);
		buckets.reserve(n_buckets);
		buckets.insert(buckets.end(), n_buckets, (node*)0);
		num_elements = 0;
	}

private:
	hasher      hash;
	ExtractKey  get_key;//用来提取关键值
private:
	vector<node*> buckets;
	size_type num_elements;
};

template <class Key, class Value, class HashFcn, class ExtractKey>
void hashtable<Key, Value, HashFcn, ExtractKey>::resize(size_type num_elements_hint)
{
	size_type old_n = buckets.size();//原来桶的个数
	if (num_elements_hint > old_n)//如果插入新元素后元素个数大于桶个数，则调整
	{
		const size_type n = next_size(num_elements_hint);//得到新的桶个数
		if (n > old_n)//在桶个数没有超范围时调整
		{
			vector<node*> tmp(n, (node*)0);
			for (size_type bucket = 0; bucket < old_n; ++bucket)//把原数据移到tmp中
			{
				node* first = buckets[bucket];
				while (first)
				{
					size_type new_bucket = bkt_num(first->val, n);
					buckets[bucket] = first->next;

					first->next = tmp[new_bucket];
					tmp[new_bucket] = first;
					first = buckets[bucket];
				}
			}
			buckets.swap(tmp);
		} 
	}
}

struct hashfun//如果关键值是整数直接返回，如果关键值不是整数则需要进行转换
{
	const int operator()(int x)const
	{
		return x;
	}
	const size_t operator()(const char *str)const//将字符串关键值转为整形关键值
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

struct KeyOfValue//提取键值
{
	const int operator()(const int &s)const
	{
		return s;
	}
	const int operator()(const pair<int, int> &s)const
	{
		return s.first;
	}
	char* operator()(char* &s)const
	{
		return s;
	}
};

void main()
{
	char* str[] = { "fjalfja", "hellofafl", "abcxyz" };
	hashtable<char*, char*, hashfun, KeyOfValue> ht(5);
	ht.insert_unique(str[0]);
	ht.insert_unique(str[1]);
	ht.insert_unique(str[2]);
	//auto it = ht.begin();
	//while (it != ht.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
}