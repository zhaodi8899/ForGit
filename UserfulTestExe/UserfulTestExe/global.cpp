/* global.cpp */
#include "global.h"

// need to ensure memory alignment??
static char g_dummy[sizeof(A)];
#if 0

static A x;
int initializer::s_counter_ = 0;

void initializer::init()
{
	new(&x) A;
}

void initializer::clean()
{
	(&x)->~A();
}

/*所有需要引用 x 的地方都需要引用 global.h 这个头文件，
而一旦引入了该头文件，就一定会引入 initializer 类型的一个静态变量 s_init_val
因此虽然不同编译单元间的初始化顺序不确定，但他们都肯定包含有 s_init_val，
因此我们可以在 s_init_val 的构造函数里加入对 x 的初始化操作，只有在第一个 s_init_val 被构造时才初始化 x 变量，
这可以通过 initializer 的静态成员变量来实现，因为 s_counter_ 的初始化是静态初始化，能保证在程序加载后就完成了。

初始化 x 用到了 placement new 的技巧，至于析构，那就是简单粗暴地直接调用析构函数了，
这一段代码里的技巧也许有些难看，但都是合法的，当然，同时还有些问题待解决：

首先，因为 x 是复杂类型的变量，它有自己的构造函数，init() 函数初始化 x 之后，
程序初始化 x 所在的编译单元时，x 的构造函数还会被再调用一次，
同理 x 析构函数也会被调用两次，这显然很容易引起问题，解决的方法是把 x 改为引用，下面的方案：
*/
#endif




/*A& x = reinterpret_cast<A&>(g_dummy);是静态初始化
因为 g_dummy 是编译时就确定了的（引用是简单类型且以常量为初始值）
而 x 只是一个强制转化而来的引用，编译器不会生成调用 x 构造函数和析构函数的代码。
通过上面的修改，这个方案已经比较完美了，但遗憾的是它也不是 100% 正确的
这个方案能正确工作的前提是：所有引用 x 的地方都会 include 头文件 global.h，
但如果某一个全局变量 y 的初始化函数里没有直接引用 x, 而是间接调用了另一个函数 foo，
再通过 foo 引用了 x，此时就可能出错了，因为 y 所在的编译单元里可能并没有直接引用 x，
因此很有可能就没有 include 头文件 global.h，那么 y 的初始化就很有可能发生在 x 之前
*/
A& x = reinterpret_cast<A&>(g_dummy);

int initializer::s_counter_ = 0;

void initializer::init()
{
	new(&x) A(8);
}

void initializer::clean()
{
	(&x)->~A();
}