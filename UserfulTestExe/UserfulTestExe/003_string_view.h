#pragma once
/*O(n) versus O(1)
std::string �� std::string_view ���� substr ����
std::string �� substr �������ص����ַ������Ӵ�
std::string_view �� substr ���ص������ַ����Ӵ���"��ͼ".
����ȥ�ƺ��������������ϱȽ�����,������֮����һ���ǳ���Ĳ��: 
std::string::substr �����Ը��Ӷ�, 
std::string_view::substr ���ǳ������Ӷ�.
����ζ�� 
std::string::substr ����������ȡ�����ַ����ĳ���
std::string_view::substr �����ܲ������ַ������ȵ�Ӱ��.

�򵥵����ܶԱ�:
*/
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include <string_view>
#include "common.h"

#define new new(__FILE__, __LINE__)

namespace EXEC_3
{
	//���ʹ��Ĭ�ϵ�new?

	static const int count = 30;
	static const int access = 10000000;

	int exec_003_string_view()
	{
		std::cout << std::endl;

		std::ifstream inFile("grimm.txt");

		std::stringstream strStream;
		strStream << inFile.rdbuf();
		std::string grimmsTales = strStream.str();

		size_t size = grimmsTales.size();

		std::cout << "Grimms' Fairy Tales size: " << size << std::endl;
		std::cout << std::endl;

		// random values
		std::random_device seed;		//�����������
		std::mt19937 engine(seed());	//���������
		std::uniform_int_distribution<> uniformDist(0, size - count - 2); //��ɢ���ȷֲ�
		std::vector<int> randValues;
		for (auto i = 0; i < access; ++i) randValues.push_back(uniformDist(engine));

		auto start = std::chrono::steady_clock::now();
		for (auto i = 0; i < access; ++i)
		{
			grimmsTales.substr(randValues[i], count);
		}
		std::chrono::duration<double> durString = std::chrono::steady_clock::now() - start;
		std::cout << "std::string::substr:      " << durString.count() << " seconds" << std::endl;

		std::string_view grimmsTalesView{ grimmsTales.c_str(), size };
		start = std::chrono::steady_clock::now();
		for (auto i = 0; i < access; ++i)
		{
			grimmsTalesView.substr(randValues[i], count);
		}
		std::chrono::duration<double> durStringView = std::chrono::steady_clock::now() - start;
		std::cout << "std::string_view::substr: " << durStringView.count() << " seconds" << std::endl;

		std::cout << std::endl;

		std::cout << "durString.count()/durStringView.count(): " << durString.count() / durStringView.count() << std::endl;

		std::cout << std::endl;

		return 0;
	}

};
