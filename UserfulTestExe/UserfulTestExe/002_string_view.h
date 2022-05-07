#pragma once
/*No memory allocation required
std::string_view ���踴���ַ������ݵ��ŵ�͸���������(std::string�����ж��ַ����Ż��������)
(��)�ڴ������һ���ǳ���ʱ�Ĳ���,�����ı���(��)�ڴ��������������ܴ����������,
ʹ�� string_view ����������Ч�ʵ�ԭ��Ҳ�����ڴ�,������Ҫ�����ܶ� string �����ַ���ʱ, string_view ������Ч����������������.
*/
#include <cassert>
#include <string>
#include <string_view>
#include "common.h"

#define new new(__FILE__, __LINE__)

namespace EXEC_2
{
	//����	C2323	��EXEC_002::operator new��: �ǳ�Ա����� new �� delete ������������Ϊ��̬��
	// Ҳ������ȫ�������ռ�֮��������ռ��н�������
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
