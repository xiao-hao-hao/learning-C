#include <iostream>
#include "Everything.h"
//通过引入lib和头文件也可以使用
//#pragma comment(lib, "xxx.lib")

using namespace std;

int main()
{
	//A字符   W宽字符
	Everything_SetSearchA("设计模式");
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