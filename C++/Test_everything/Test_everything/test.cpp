#include <iostream>
#include "Everything.h"
//ͨ������lib��ͷ�ļ�Ҳ����ʹ��
//#pragma comment(lib, "xxx.lib")

using namespace std;

int main()
{
	//A�ַ�   W���ַ�
	Everything_SetSearchA("���ģʽ");
	Everything_QueryA(TRUE);

	cout << Everything_GetNumResults() <<endl;

	for (int i = 0; i<Everything_GetNumResults(); i++)
	{
		wcout << Everything_GetResultFileNameA(i) << endl;
	}
	return 0;
}

/*
#include "..\include\Everything.h"

int main(int argc, char **argv)
{
	Everything_SetSearchW(L"hello");
	Everything_QueryW(TRUE);

	{
		DWORD i;

		for (i = 0; i<Everything_GetNumResults(); i++)
		{
			wcout << Everything_GetResultFileNameW(i) << L"\n";
		}
	}

	return 0;
}
*/