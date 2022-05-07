// UserfulTestExe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "001_string.h"
#include "002_string_view.h"
#include "003_string_view.h"
#include "004_nifty_counter_idiom.h"

using namespace std;

//清除屏幕
void clearScreen()
{
	system("cls");
}

void printLog()
{
	cout << "输入如下的编号，执行对应的功能，并显示对应代码" << endl;
	cout << "No:1  " << "string optimisation-字符串优化" << endl;
	cout << "No:2  " << "string_view" << endl;
	cout << "No:3  " << "string_view and string sub 性能比较" << endl;
	cout << "No:4  " << "nifty_counter_idiom" << endl;
	cout << "输入q直接退出" << endl;
}
#define EXECFUNCTION(index,func)  case index:	EXEC_##index##::##func##();	break;
void exeFunction(int nIndex)
{
	switch (nIndex)
	{
		EXECFUNCTION(1, exec_001_string)
		EXECFUNCTION(2, exec_002_string_view)
		EXECFUNCTION(3, exec_003_string_view)
		EXECFUNCTION(4, exec_004_nifty_counter_idiom)
	default:
		break;
	}
}


int main()
{
	int nSelectIndex = 0;
	string strTemp;
	while (true)
	{
		clearScreen();
		printLog();
		cin >> strTemp;
		if (strTemp == "q")
		{
			exit(0);
			return 0;
		}
		nSelectIndex = atoi(strTemp.c_str());
		clearScreen();
		exeFunction(nSelectIndex);

		cout << "输入数组或者字符键回车将重新执行" << endl;
		cin >> strTemp;
	}

	
	return 0;
}
