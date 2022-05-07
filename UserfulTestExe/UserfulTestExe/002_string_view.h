#pragma once
/*No memory allocation required
std::string_view 无需复制字符串数据的优点就更加明显了(std::string不进行短字符串优化的情况下)
(堆)内存分配是一个非常耗时的操作,尽量的避免(堆)内存分配会给程序带来很大的性能提升,
使用 string_view 能提升程序效率的原因也正是在此,当你需要创建很多 string 的子字符串时, string_view 带来的效率提升将更加明显.
*/
#include <cassert>
#include <string>
#include <string_view>
#include "common.h"

#define new new(__FILE__, __LINE__)

namespace EXEC_2
{
	//错误	C2323	“EXEC_002::operator new”: 非成员运算符 new 或 delete 函数不可声明为静态的
	// 也不可在全局命名空间之外的命名空间中进行声明
	// void* operator new(std::size_t count)
	// {
	// 	std::cout << "   " << count << " bytes" << std::endl;
	// 	return malloc(count);
	// }

void getString(const std::string& str) {}

void getStringView(std::string_view strView) {}

int exec_002_string_view()
{
	std::cout << std::endl;

	std::cout << "std::string" << std::endl;

	std::string large = "0123456789-123456789-123456789-123456789";
	std::string substr = large.substr(10);

	std::cout << std::endl;

	std::cout << "std::string_view" << std::endl;

	std::string_view largeStringView{ large.c_str(), large.size() };
	largeStringView.remove_prefix(10);

	assert(substr == largeStringView);

	std::cout << std::endl;

	std::cout << "getString" << std::endl;

	getString(large);
	getString("0123456789-123456789-123456789-123456789");
	const char message[] = "0123456789-123456789-123456789-123456789";
	getString(message);

	std::cout << std::endl;

	std::cout << "getStringView" << std::endl;

	getStringView(large);
	getStringView("0123456789-123456789-123456789-123456789");
	getStringView(message);

	std::cout << std::endl;

	return 0;
}
};
