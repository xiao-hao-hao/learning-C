//#include <iostream>
//
//namespace my_space
//{
//	template<typename T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//	public:
//		vector()
//			: start(nullptr)
//			, finish(nullptr)
//			, end_of_storage(nullptr)
//		{}
//		vector(size_t n, const T &value = T())
//			: start(nullptr)
//			, finish(nullptr)
//			, end_of_storage(nullptr)
//		{
//			reserve(n);
//			while (n-- != 0)
//			{
//				push_back(value);
//			}
//		}
//		template<class InputIterator>
//		vector(InputIterator first, InputIterator last)
//		{
//			//reserve(last - first);
//			while (first != last)
//			{
//				push_back(*first);
//				++first;
//			}
//		}
//		~vector()
//		{
//			delete[] start;
//			start = finish = end_of_storage = nullptr;
//		}
//	public:
//		size_t size()const
//		{return finish - start;}
//		size_t capacity()const
//		{return end_of_storage - start;}
//		bool empty()const
//		{return finish == start;}
//	public:
//		iterator begin()
//		{return start;}
//		iterator end()
//		{return finish;}
//	public:
//		void push_back(const T &x)
//		{insert(end(), x);}
//	public:
//		void swap(vector &v)
//		{
//			std::swap(start, v.start);
//			std::swap(finish, v.finish);
//			std::swap(end_of_storage, v.end_od_storage);
//		}
//	public:
//		void reserve(size_t n)
//		{
//			if (n > capacity())
//			{
//				size_t oldsize = size();
//				T *new_start = new T[n];
//				if (start)
//				{
//					for (int i = 0; i < oldsize; ++i)
//					{
//						new_start[i] = start[i];
//					}
//				}
//				if (start)
//					delete[] start;
//				start = new_start;
//				finish = start + oldsize;
//				end_of_storage = start + n;
//			}
//		}
//		void resize(size_t n, const T& value = T())
//		{
//			if (n <= size())
//			{
//				finish = start + n;
//				return;
//			}
//			if (n > capacity())
//				reserve(n * 2);
//			iterator p = finish;
//			finish = start + n;
//			while (p != finish)
//			{
//				*p = value;
//				++p;
//			}
//		}
//	public:
//		iterator insert(iterator pos, const T &x)
//		{
//			if (finish >= end_of_storage)
//			{
//				size_t oldpos = pos - start;
//				size_t new_cpy = capacity() ? capacity() * 2 : 1;
//				reserve(new_cpy);
//				pos = start + oldpos;
//			}
//			iterator p = finish;
//			while (p != pos)
//			{
//				*p = *(p - 1);
//				--p;
//			}
//			*p = x;
//			++finish;
//			return pos;
//		}
//		iterator erase(iterator pos)
//		{
//			iterator p = pos;
//			while (p != finish - 1)
//			{
//				*p = *(p + 1);
//				++p;
//			}
//			--finish;
//			return pos;
//		}
//	private:
//		iterator start;
//		iterator finish;
//		iterator end_of_storage;
//	};
//}
//
//int main()
//{
//	//my_space::vector<int> v1;
//	int ar[] = { 1, 2, 3, 4, 5 };
//	my_space::vector<int> v1(ar, ar + 5);
//	for (auto &e : v1)
//		std::cout << e << " ";
//	return 0;
//}