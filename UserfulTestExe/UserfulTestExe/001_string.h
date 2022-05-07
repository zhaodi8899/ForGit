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
		//如果在17之前的下面标记new的都会产生到堆上，17的时候这些小长度的在栈上
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