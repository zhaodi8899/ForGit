#pragma once
/*O(n) versus O(1)
std::string 和 std::string_view 都有 substr 方法
std::string 的 substr 方法返回的是字符串的子串
std::string_view 的 substr 返回的则是字符串子串的"视图".
听上去似乎两个方法功能上比较相似,但他们之间有一个非常大的差别: 
std::string::substr 是线性复杂度, 
std::string_view::substr 则是常数复杂度.
这意味着 
std::string::substr 方法的性能取决于字符串的长度
std::string_view::substr 的性能并不受字符串长度的影响.

简单的性能对比:
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
	//如何使用默认的new?

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
		std::random_device seed;		//随机数发生器
		std::mt19937 engine(seed());	//随机数引擎
		std::uniform_int_distribution<> uniformDist(0, size - count - 2); //离散均匀分布
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
