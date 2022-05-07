#pragma once
#ifndef _class_X_h_
#define _clsss_X_h_
#include <iostream>

class X
{
public:
	X(int i) :a(i)
	{
		std::cout << "class X construted." << std::endl;
	}
	~X()
	{
		std::cout << "class X deconstruted." << std::endl;
	}
	int get_value()
	{
		return a;
	}

private:
	int a;
};

//对全局变量的引用改为函数调用，然后把全局变量改为函数内的静态变量
int get_global_x()
{
	static X x(5);
	return x.get_value();
}

//可以解决全局变量未初始化就被引用的问题，但还有另一个对称的问题它却没法解决，
//函数内的静态变量也属于 variables with static storage, 它们析构的顺序在不同的编译单元间也是不确定的，
//因此上面的方法虽然必然能保证 x 的初始化先于其被使用，但却没法妥善处理，
//如果 x 析构了 get_global_x() 还被调用这种可能发生的情况


int get_global_x2()
{
	static X* x = new X(2);
	return x->get_value();
}
//进可以解决前面提到的 x 析构后被调用的问题
//但同时却也引入了另一个问题: x 永远都不会析构了，内存泄漏还算小问题或者说不算问题
//但如果 x 的析构函数还有事情要做，如写文件清理垃圾什么的，此时如果对象不析构，显然程序的正确性都无法保证。



#endif