#pragma once
#include "common.h"
#include <string>

#define new new(__FILE__, __LINE__)
namespace EXEC_1
{

	void getString(const std::string& str) {}

	int exec_001_string()
	{
		std::cout << std::endl;

		std::cout << "std::string" << std::endl;
		//�����17֮ǰ��������new�Ķ�����������ϣ�17��ʱ����ЩС���ȵ���ջ��
		std::string small = "0123456789";		//new
		std::string substr = small.substr(3);	//new
		std::cout << "   " << substr << std::endl;

		std::cout << std::endl;

		std::cout << "getString" << std::endl;

		getString(small);
		getString("0123456789"); //new
		const char message[] = "0123456789";
		getString(message);		//new


		std::string bigstringWillNew = "012345678901234567890123456789012345678901234567890123456789";		//new

		std::cout << std::endl;

		return 0;
	}

};