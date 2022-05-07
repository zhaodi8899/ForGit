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

//��ȫ�ֱ��������ø�Ϊ�������ã�Ȼ���ȫ�ֱ�����Ϊ�����ڵľ�̬����
int get_global_x()
{
	static X x(5);
	return x.get_value();
}

//���Խ��ȫ�ֱ���δ��ʼ���ͱ����õ����⣬��������һ���ԳƵ�������ȴû�������
//�����ڵľ�̬����Ҳ���� variables with static storage, ����������˳���ڲ�ͬ�ı��뵥Ԫ��Ҳ�ǲ�ȷ���ģ�
//�������ķ�����Ȼ��Ȼ�ܱ�֤ x �ĳ�ʼ�������䱻ʹ�ã���ȴû�����ƴ���
//��� x ������ get_global_x() �����������ֿ��ܷ��������


int get_global_x2()
{
	static X* x = new X(2);
	return x->get_value();
}
//�����Խ��ǰ���ᵽ�� x �����󱻵��õ�����
//��ͬʱȴҲ��������һ������: x ��Զ�����������ˣ��ڴ�й©����С�������˵��������
//����� x ������������������Ҫ������д�ļ���������ʲô�ģ���ʱ���������������Ȼ�������ȷ�Զ��޷���֤��



#endif