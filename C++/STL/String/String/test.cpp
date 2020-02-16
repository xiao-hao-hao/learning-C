#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "hello";
	s1.resize(10);
	cout << s1 << endl;
	//printf("%s\n", s1.c_str());
	return 0;
}

//int main()
//{
//	string str = "hello";
//	string::iterator it = str.end() - 1;
//	while (it != str.begin())
//	{
//		cout << *it;
//		--it;
//	}
//	cout << *it;
//
//	return 0;
//}

//void main()
//{
//	//string email = "kkkzkkbaosongshan2006@163.com";
//	//size_t pos = email.find('song'); //ÍêÈ«Æ¥Åä
//
//	//string sub("abcxyz");
//	//pos = email.find_first_of(sub);
//	//cout << pos << endl;
//
//	//pos = email.find_first_not_of(sub);
//	//cout << pos << endl;
//
//	//pos = email.find_last_of(sub);
//	//cout << pos << endl;
//
//	//pos = email.find_last_not_of(sub);
//	//cout << pos << endl;
//	string hostname;
//	string str = "123";
//	hostname = str + str + '5' + "123";
//	cout << hostname << endl;
//}

//int main()
//{
//	string str1 = "hello";
//	string str2 = "bit";
//	string str3;
//	//if (str1 == str2)
//	//{
//	//	cout << "ok" << endl;
//	//}
//	getline(cin, str3);
//	cout << str3 << endl;
//	return 0;
//}



//int main()
//{
//	string url("http://www.cpluscplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//	}
//	else
//	{
//		start += 3;
//		size_t finish = url.find('/', start);
//		string address = url.substr(start, finish - start);
//		//cout << address << endl;
//		size_t pos = url.find("://");
//		url.erase(0, pos + 3);
//		cout << url << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	string file1("string.cpp");
//	//size_t pos = file1.rfind('.');
//	//string suffix(file1.substr(pos, file1.size() - pos));
//	//cout << suffix << endl;
//	size_t pos = file1.find('.', 8);
//	cout << pos << endl;
//	return 0;
//}

//int main()
//{
//	string str;
//	str.push_back(' ');
//	str.append("a");
//	str += 'b';
//	str += "it";
//	cout << str << endl;
//	cout << str.c_str() << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello bit");
//	//cout << s1 << endl;
//	string s2(s1);
//	//s1[0] = 'H';
//	//cout << s1 << endl;
//	//cout << s2 << endl;
//	/*
//	for (int i = 0; i < s1.size(); ++i)
//		cout << s1[i];
//	return 0;
//	*/
//	/*
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	*/
//	/*
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << endl;
//		++rit;
//	}
//	*/
//	for (auto &ch : s1)
//	{
//		cout << ch << endl;
//	}
//}

//
//int main()
//{
//	string s1;
//	string s2("hello bit");
//	string s3("hello bit");
//	string s4(s3);
//	string s5(10, 'x');
//	
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	s2.resize(20);
//	cout << s2.length() << endl;
//	cout << s2.capacity() << endl;
//	cout << s2 << endl;
//	s2.resize(3);
//	cout << s2 << endl;
//	s3.reserve(100);
//	s3.reserve(20);
//	cout << s3 << endl;
//	cout << s1.capacity() << endl;
//	s5.push_back('2');
//	cout << s5 << endl;
//	return 0;
//}
