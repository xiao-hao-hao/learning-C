// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		if (n == 0)
			break;
		while (n > 1)
		{
			++count;
			n = n / 3 + (n % 3 > 0);
		}
		cout << count << endl;
	}
	return 0;
}







//����λ�϶�����������ż��λ�϶���ż��
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void oddInOddEvenInEven(vector<int>& arr, int len)
//{
//	int i = 0, j = 1;
//	while (i < len && j < len)
//	{
//		if (arr[i] % 2 != 0 && arr[j] % 2 == 0)
//		{
//			swap(arr[i], arr[j]);
//			j += 2;
//			i += 2;
//			continue;
//		}
//		if (arr[i] % 2 == 0)
//			i += 2;
//		if (arr[j] % 2 != 0)
//			j += 2;
//	}
//}
//int main()
//{
//	vector<int> arr = { 0, 1, 2, 2, 2 ,5,5,5};
//	oddInOddEvenInEven(arr, 8);
//	return 0;
//}

////���üӼ��˳����ӷ�
//class Solution {
//public:
//	int Add(int num1, int num2)
//	{
//		while (num2 != 0)
//		{
//			int temp = num1 ^ num2;
//			num2 = (num1 & num2) << 1;
//			num1 = temp;
//		}
//		return num1;
//	}
//};
//
//







//#include <stdio.h>
//int main()
//{
//	char c;
//	unsigned char uc;
//	unsigned short us;
//	c = 128;
//	uc = 128;
//	us = c + uc;
//	printf("0x%x ", us);
//	us = (unsigned char)c + uc;
//	printf("0x%x ", us);
//	us = c + (char)uc;
//	printf("0x%x ", us);
//	return 0;
//}

//#include <stdio.h> 
//unsigned char i = 0;
//int main()
//{
//	//for (i = 0; i <= 255; i++)
//	//{
//	//	printf("hello world\n");
//	//}
//	printf("%f\n", 3.5E-1);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = -375, b = 2;
//	printf("%d\n", a, b);
//	printf("%c %hd\n", a, b);
//	return 0;
//}
//short int a = 1, b = 2, c = 3;
////���ʲô��
//#include <stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%u,b=%d,c=%d\n", a, b, c);
//	return 0;
//}

//#include <stdio.h> 
//int main()
//{
//	int d = 0x01000000;
//	char a = -128;
//	int b = -1;
//	char c = 128;
//	printf("%u\n", a);
//	printf("%u\n", d);
//	printf("%u\n", c);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int N, M;
//	while (cin >> N >> M)
//	{
//		vector<int> steps(M + 1, INT_MAX);
//		steps[N] = 0;
//		for (int i = N; i <= M; ++i)
//		{
//			if (steps[i] == INT_MAX)
//				continue;
//			for (int j = 2; j * j <= i; ++j)
//			{
//				if (i % j == 0)
//				{
//					if (i + j <= M)
//						steps[i + j] = min(steps[i] + 1, steps[i + j]);
//					if (i + i / j <= M)
//						steps[i + i / j] = min(steps[i] + 1, steps[i + i / j]);
//				}
//			}
//		}
//		if (steps[M] == INT_MAX)
//			steps[M] = -1;
//		cout << steps[M] << endl;
//	}
//	return 0;
//}



//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int tag = 1;
//		int str_len = str.length();
//		int count = 0;
//		string str_out;
//		string str_temp;
//		for (int i = 0; i <= str_len; ++i)
//		{
//			if (i == str_len && str_temp.length())
//			{
//				str_out += str_temp + '\n';
//				++count;
//			}
//			if (str[i] != ' ' && str[i] != '"' || str[i] == ' ' && !tag)
//				str_temp += str[i];
//			if (str[i] == ' ' && tag && str_temp.length())
//			{
//				str_out += str_temp + '\n';
//				++count;
//				str_temp.clear();
//			}
//			if (str[i] == '"' && tag)
//			{
//				if (str_temp.length())
//				{
//					str_out += str_temp + '\n';
//					++count;
//					str_temp.clear();
//				}
//				tag = 0;
//			}
//			if (str[i] == '"' && !tag && str_temp.length())
//			{
//				str_out += str_temp + '\n';
//				str_temp.clear();
//				++count;
//				tag = 1;
//			}
//		}
//		cout << count << endl;
//		cout << str_out;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;

//int main()
//{
//	int n = 10;
//	char s1[32] = {0};
//	_itoa(n, s1, 16);//16��ʾ��n��16���Ʒ���s1
//	//char s2[32];
//	//sprintf(s2, "%d", n);
//	//char s3[32];
//	//sprintf(s3, "%f", n);
//	return 0;
//}

//#include<sstream>
//int main()
//{
//	int a = 12345678;
//	string sa;
//	// ��һ�����α���ת��Ϊ�ַ������洢��string�������
//	stringstream s;
//	s << a;
//	s >> sa;
//	// ��stringstream�ײ����string�������ó�"", 
//	// ������ת��ʱ���Ὣ���ȫ���ۻ��ڵײ�string������
//	//s.str("");
//	s.clear(); // ���s, ����ջ�ת��ʧ��
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string sValue;
//	sValue = sa.c_str(); // str()����������stringsteam�й����string����
//	//sValue = "123";
//	cout << sa << endl;
//	return 0;
//}

//int main()
//{
//	stringstream sstream;
//	int a = 123;
//	int b = 456;
//	// ������ַ������� sstream ��
//	sstream << "first" << " " << "string,";
//	sstream << " second string";
//	cout << "strResult is: " << sstream.str() << endl;
//	// ��� sstream
//	sstream.str("");
//	sstream << "third string";
//	sstream << a;
//	sstream.clear();
//	sstream << b;
//	cout << "After clear, strResult is: " << sstream.str() << endl;
//	return 0;
//}

//#include <fstream>
//
//// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
//struct ServerInfo
//{
//	char _ip[32]; // ip
//	int _port; // �˿�
//};
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* configfile = "bitserver.config")
//		:_configfile(configfile)
//	{}
//	void WriteBin(const ServerInfo& info)
//	{
//		// ����ע��ʹ�ö����Ʒ�ʽ��д
//		ofstream ofs(_configfile, ios::out | ios::binary);
//		ofs.write((const char*)&info, sizeof(ServerInfo));
//		ofs.close();
//	}
//	void ReadBin(ServerInfo& info)
//	{
//		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
//		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
//		ifs.read((char*)&info, sizeof(ServerInfo));
//		ifs.close();
//	}
//	void WriteText(const ServerInfo& info)
//	{
//		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
//		// C ���Ե��Ȱ�����itoa��д
//		ofstream ofs(_configfile, ios::out);
//		ofs << info._ip << endl;
//		ofs << info._port << endl;
//		ofs.close();
//	}
//	void ReadText(ServerInfo& info)
//	{
//		// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
//		// C ���Ե��ȶ��ַ�������atoi
//		ifstream ifs(_configfile, ios::in);
//		ifs >> info._ip;
//		ifs >> info._port;
//		ifs.close();
//	}
//private:
//	string _configfile; // �����ļ�
//};
//int main()
//{
//	ConfigManager cfgMgr;
//	ServerInfo wtinfo;
//	ServerInfo rdinfo;
//	wtinfo = { "127.0.0.1", 8080 };
//	// //�����ƶ�д
//	cfgMgr.WriteBin(wtinfo);
//	cfgMgr.ReadBin(rdinfo);
//	cout << rdinfo._ip << endl;
//	cout << rdinfo._port << endl;
//	// �ı���д
//	//cfgMgr.WriteText(wtinfo);
//	//cfgMgr.ReadText(rdinfo);
//	//cout << rdinfo._ip << endl;
//	//cout << rdinfo._port << endl;
//	return 0;
//}

// extract to string
//#include <iostream>
//#include <string>
//
//int main()
//{
//	std::string name;
//	std::cout << "Please, enter your full name: ";
//	cout << (bool)std::getline(std::cin, name);
//	std::cout << "Hello, " << name << "!\n";
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	char m[20];
//	cout << "please: ";
//	fflush(stdin);
//	cin.getline(m, 21);
//	cout << m << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//int main()
//{
//	string line;
//	while (getline(cin, line))
//		cout << line << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <stdio.h>
//using namespace std;
//
//int main()
//{
//	string line;
//	char a[20];
//	cout << (bool)cin.getline(a, 5);
//	//printf("%d", (bool)cin.getline(a, 5));
//	return 0;
//}