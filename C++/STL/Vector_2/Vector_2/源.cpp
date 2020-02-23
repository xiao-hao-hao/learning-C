#include <iostream>

namespace bit
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()
		{}
		~vector()
		{
			delete[] start;
			start = finish = end_of_storage = nullptr;
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}

int main()
{
	bit::vector<int> v1;
	//int ar[] = { 1, 2, 3, 4, 5 };
	//bit::vector<int> v1(ar, ar + 5);
	//for (auto &e : v1)
		//std::cout << e << " ";
	return 0;
}