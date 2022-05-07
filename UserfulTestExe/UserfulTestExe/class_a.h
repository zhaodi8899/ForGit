#ifndef _class_h_
#define _clsss_h_
#include <iostream>

class A
{
public:
	A(int i) :a(i)
	{
		std::cout << "class A construted." << std::endl;
	}
	~A()
	{
		std::cout << "class A deconstruted." << std::endl;
	}
	int get_value()
	{
		return a;
	}

private:
	int a;
};

#endif