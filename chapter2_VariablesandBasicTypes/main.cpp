#include <iostream>

using std::cout;
using std::endl;

//global_variable �ᱻ��ʼ��Ϊ0��
//local_variable ���ᱻ��ʼ����������û��������ֵ����

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;//��ʼֵ
	double revenue = 0.0;
};


int main(void)
{
	long double ld = 3.1415926;
	//int a{ ld }, b = { ld };	//����ת��û��ִ�У��ᶪʧһ���ľ���
	int c(ld), d = ld;			//��ȷ��ת��ִ�У���ʧ�˾���

	//��Ҫ��һ�����ʽ�л��ô��������ͺͲ�����������

	//���ñ����ʼ�� ���ñ�����һ������
	int ival;
	int& refVal = ival;
#if 0
	int& rvall = 1024;//�������ñ���ָ��һ��ʵ�ʴ��ڵĶ������������ֵ����
#endif
	int* p = nullptr;
	/*
	*	�����ò������������ָ��
	*	const��������Ҫ��ʼ��
	*
	*/
	const int ci = 1024;
	const int& ri = ci;	//��ȷ:�����Լ����Ӧ�Ķ����ǳ���
#if 0
	ri = 42;	//����r1�ǶԳ���������
	int& r2 = ci;	//������ͼ��һ���ǳ�������ָ��һ����������
	const int& r3 = 42;//��ȷ����������ָ����
#endif

	int cb = 1024;
	const int &cbr = cb;//��ȷ:�������ã�������ͨ�������ı�cb��ֵ
	const int* cbp = &cb;//��ȷ������ָ�룬������ͨ��ָ��ı�cb��ֵ

	const double pi = 3.1415926;
	
	const double* p1;
	const double* const pip = &pi;

	/* ����const��ײ�const */
	int  i = 0;
	int* const pl = &i;

	/* constexpr�����ı���һ����һ�����������ұ����ó������ʽ��ʼ�� */
	//constexpr int sz = size();	//ֻ�е�size��һ��constexpr����ʱ������һ����ȷ���������
	//const int* p; //P��һ��ָ�����γ�����ָ��
	//constexpr int* q;//q��һ��ָ�������ĳ���ָ�루��Ҫ��ʼ����
					//constexprֻ��ָ����Ч����ָ�봦��������޹�

	/* ���ͱ��� */
	typedef double wages;	//wages��double��ͬ���
	typedef wages base, * ptr;//base��double��ͬ��ʣ�p��double*��ͬ���
	using si = double*;		//si��double*��ͬ���

	/* auto����˵���� decltype����ָʾ�� */
	//auto����Ե������const���ײ����ᱻ��������
	const int cs = i, & cr = cs;
	auto b = cs;	//b��һ��������cs�Ķ���const�����Ե���
	auto cw = cr;	//c��һ��������cr��cs�ı�����cs������һ������const��
	auto dw = &i;	//d��һ������ָ�루�����ĵ�ַ����ָ��������ָ���ˣ�
	auto e = &cs;	//e��һ��ָ������������ָ�루�Գ�������ȡ��ַ��һ�ֵײ�const��

	decltype(cs) cx = 0;	//x��������const int
	decltype(cr) y1 = cx;		//y1��������const int&��y�󶨵�����x
	decltype(cr + 0) y2 = cx;		//y2��������int��y�󶨵�����x

	/* �мǣ�decltype((variable))��ע����˫�����ţ��Ľ����Զ�����ã�
		��decltype(variable)���ֻ�е�variable�������һ������ʱ�������� */

	std::cerr << "DATA must!!!" << endl;
	return 0;
}