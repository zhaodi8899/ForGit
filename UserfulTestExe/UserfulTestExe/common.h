#pragma once
#include <iostream>

//void* operator new(std::size_t count)
void* operator new(size_t count, const char* file, int line)
{
	std::cout << "   " << count << " bytes" << file << ":" << line << std::endl;
	return malloc(count);
}

void* operator new(size_t count)
{
	std::cout << "   " << count << " bytes" << std::endl;
	return malloc(count);
}