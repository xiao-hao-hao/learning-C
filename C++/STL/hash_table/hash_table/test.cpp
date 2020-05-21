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
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}


template <class Value>
struct __hashtable_node
{
	__hashtable_node* next;
	Value val;
};

template <class Key, class Value>
class hashtable
{
public:
	typedef __hashtable_node<Value> node;
	typedef size_t size_type;
	typedef Value  value_type;
public:
	hashtable(size_type n) :num_elements(0)
	{
		initialize_buckets(n);
	}
public:
	bool insert_unique(const value_type& obj)
	{

		return insert_unique_noresize(obj);
	}
	bool insert_unique_noresize(const value_type& obj)
	{
		const size_type n = bkt_num(obj);
		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
		if (cur->val == obj)
			return false;

		node* tmp = new_node(obj);
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return true;
	}
private:
	size_type bkt_num(const value_type& obj) const
	{
		return obj % buckets.size();
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
	vector<node*> buckets;
	size_type num_elements;
};

void main()
{
	hashtable<int, int> ht(53); //int-string
	ht.insert_unique(1);
	ht.insert_unique(54);
}