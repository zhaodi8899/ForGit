#pragma once
/*
c++ 全局变量初始化的一点总结 https://www.cnblogs.com/catch/p/4314256.html
C++ 标准，全局变量的初始化要在 main 函数执行前完成
main 函数执行前到底具体是什么时候呢？是编译时还是运行时？
答案是既有编译时，也可能会有运行时(seriously), 
从语言的层面来说，全局变量的初始化可以划分为以下两个阶段（c++11 N3690 3.6.2)：

static initialization: 静态初始化指的是用常量来对变量进行初始化,主要包括 
	zero initialization      //变量会被保存在 bss 段
	const initialization	 //变量则放在 data 段内
静态初始化在程序加载的过程中完成，对简单类型(内建类型，POD等)来说 从具体实现上看，程序加载即可完成初始化

dynamic initialization：动态初始化主要是指需要经过函数调用才能完成的初始化
比如说：int a = foo()，或者是复杂类型（类）的初始化（需要调用构造函数）等。
这些变量的初始化会在 main 函数执行前由运行时调用相应的代码从而得以进行(函数内的 static 变量除外)。

需要明确的是：静态初始化执行先于动态初始化！ 只有当所有静态初始化执行完毕，动态初始化才会执行。
显然，这样的设计是很直观
静态初始化的变量，它的初始值都是在编译时就能确定，因此可以直接 hard code 到生成的代码里
动态初始化需要在运行时执行相应的动作才能进行，因此，静态初始化先于动态初始化是必然的。
*/
//nifty 俏皮/漂亮
//idiom 习语
#include <iostream>
#include "global.h"

namespace EXEC_4
{
	int exec_004_nifty_counter_idiom()
	{
		std::cout << "x = " << x.get_value() << std::endl;
		return 0;
	}
};
