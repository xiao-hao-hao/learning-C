#include <iostream>
using namespace std;

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

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	string line;
	char a[20];
	cout << (bool)cin.getline(a, 5);
	//printf("%d", (bool)cin.getline(a, 5));
	return 0;
}