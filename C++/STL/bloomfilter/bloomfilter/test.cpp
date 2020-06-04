#include <iostream>
#include <vector>
//#include <bitset>
using namespace std;

class Bitset
{
public:
	friend ostream& operator<<(ostream &out, const Bitset &bt);
	Bitset(size_t bitCount)//申请32的整数倍的空间
		: _bit((bitCount >> 5) + 1), _bitCount(bitCount)
	{}
	// 将which比特位置1
	void set(size_t which)
	{
		if (which > _bitCount)
			return;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		_bit[index] |= (1 << pos);
	}
	// 将which比特位置0
	void reset(size_t which)
	{
		if (which > _bitCount)
			return;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		_bit[index] &= ~(1 << pos);
	}
	// 检测位图中which是否为1
	bool test(size_t which)
	{
		if (which > _bitCount)
			return false;
		size_t index = (which >> 5);
		size_t pos = which % 32;
		return _bit[index] & (1 << pos);
	}
	// 获取位图中比特位的总个数
	size_t size()const{ return _bitCount; }
	// 位图中比特为1的个数
	size_t Count()const
	{
		int bitCntTable[256] = {
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 };

		size_t size = _bit.size();
		size_t count = 0;
		for (size_t i = 0; i < size; ++i)
		{
			int value = _bit[i];
			int j = 0;
			while (j < sizeof(_bit[0]))//对一个整形变量截成四段，分别求1的个数
			{
				unsigned char c = value;
				count += bitCntTable[c];
				++j;
				value >>= 8;
			}
		}
		return count;
	}
private:
	vector<int> _bit;
	size_t _bitCount;
};

ostream& operator<<(ostream &out, const Bitset &bt)
{
	for (int i = bt._bitCount-1; i >= 0; --i)
	{
		if (bt._bit[i / 32] & (0x01 << (i%32)))
			out << 1;
		else
			out << 0;
	}
	return out;
}

int main()
{
	Bitset bmp(1000);
	bmp.set(500);
	cout << bmp << endl;
	return 0;
}

/*
struct StrToInt1
{
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return BKDRHash(str.c_str());
	}
};
struct StrToInt2
{
	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return SDBMHash(str.c_str());
	}
};
struct StrToInt3
{
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return RSHash(str.c_str());
	}
};
#define _N 1000
template<class K, class HashFunc1 = StrToInt1,
class HashFunc2 = StrToInt2,
class HashFunc3 = StrToInt3>
class BloomFilter
{
public:
	BloomFilter() : m_size(0)
	{}
public:
	void Insert(const string &str)
	{
		size_t bit_capacity = m_bmp.size();
		size_t index1 = HashFunc1()(str) % bit_capacity;
		m_bmp.set(index1);
		size_t index2 = HashFunc2()(str) % bit_capacity;
		m_bmp.set(index2);
		size_t index3 = HashFunc3()(str) % bit_capacity;
		m_bmp.set(index3);
		m_size++;
	}
	bool Test(const string &str)
	{
		size_t bit_capacity = m_bmp.size();
		size_t index1 = HashFunc1()(str) % bit_capacity;
		if (!m_bmp.test(index1))
			return false;
		size_t index2 = HashFunc2()(str) % bit_capacity;
		if (!m_bmp.test(index2))
			return false;
		size_t index3 = HashFunc3()(str) % bit_capacity;
		if (!m_bmp.test(index3))
			return false;
		return true; //可能存在
	}
private:
	bitset<_N * 5> m_bmp;
	size_t m_size;
};
void main()
{
	BloomFilter<string> bf;
	string str0 = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	string str1 = "ttps://www.cnb";
	string str2 = "https://www.cnblogs";
	string str3 = "https://www.cnblogs.com/clq/archive/2012/05/31/2528153.html";
	bf.Insert(str0);
	bf.Insert(str1);
	bf.Insert(str2);
	bf.Insert(str3);
	cout << bf.Test(str2) << endl;
	string str = "https://www.cnblogs.com/.clq/archive/2012/05/31/2528153.html";
	cout << bf.Test(str) << endl;
	string str4 = "baidu.com";
	cout << bf.Test(str4) << endl;
}
*/