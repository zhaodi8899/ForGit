/* global.h */
#ifndef _global_h_
#define _global_h_

#include "class_a.h"
extern A& x;

class initializer
{
public:
	initializer()
	{
		if (s_counter_++ == 0) init();
	}
	~initializer()
	{
		if (--s_counter_ == 0) clean();
	}
private:
	void init();
	void clean();
	static int s_counter_;
};

static initializer s_init_val;

#endif