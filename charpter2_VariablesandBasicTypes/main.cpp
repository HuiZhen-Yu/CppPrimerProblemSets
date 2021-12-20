#include <iostream>

using std::cout;
using std::endl;

//global_variable 会被初始化为0；
//local_variable 不会被初始化，如果调用会产生奇异值错误

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;//初始值
	double revenue = 0.0;
};


int main(void)
{
	long double ld = 3.1415926;
	//int a{ ld }, b = { ld };	//错误：转换没有执行，会丢失一定的精度
	int c(ld), d = ld;			//正确：转换执行，丢失了精度

	//不要在一个表达式中混用带符号类型和不带符号类型

	//引用必须初始化 引用本身不是一个对象
	int ival;
	int& refVal = ival;
#if 0
	int& rvall = 1024;//错误：引用必须指向一个实际存在的对象而不是字面值常量
#endif
	int* p = nullptr;
	/*
	*	解引用操作对象必须是指针
	*	const变量必须要初始化
	*
	*/
	const int ci = 1024;
	const int& ri = ci;	//正确:引用以及其对应的对象都是常量
#if 0
	ri = 42;	//错误：r1是对常量的引用
	int& r2 = ci;	//错误：试图让一个非常量引用指向一个常量对象
	const int& r3 = 42;//正确：常量引用指向常量
#endif

	int cb = 1024;
	const int &cbr = cb;//正确:常量引用，不可以通过常量改变cb的值
	const int* cbp = &cb;//正确：常量指针，不可以通过指针改变cb的值

	const double pi = 3.1415926;
	
	const double* p1;
	const double* const pip = &pi;

	/* 顶层const与底层const */
	int  i = 0;
	int* const pl = &i;

	/* constexpr申明的变量一定是一个常量，而且必须用常量表达式初始化 */
	//constexpr int sz = size();	//只有当size是一个constexpr函数时，才是一条正确的申明语句
	//const int* p; //P是一个指向整形常量的指针
	//constexpr int* q;//q是一个指向整数的常量指针（需要初始化）
					//constexpr只对指针有效，对指针处理的类型无关

	/* 类型别名 */
	typedef double wages;	//wages是double的同义词
	typedef wages base, * ptr;//base是double的同义词，p是double*的同义词
	using si = double*;		//si是double*的同义词

	/* auto类型说明符 decltype类型指示符 */
	//auto会忽略掉顶层的const，底层的则会被保存下来
	const int cs = i, & cr = cs;
	auto b = cs;	//b是一个整数（cs的顶层const被忽略掉）
	auto cw = cr;	//c是一个整数（cr是cs的别名，cs本身是一个顶层const）
	auto dw = &i;	//d是一个整形指针（整数的地址就是指向整数的指针了）
	auto e = &cs;	//e是一个指向整数常量的指针（对常量对象取地址是一种底层const）

	decltype(cs) cx = 0;	//x的类型是const int
	decltype(cr) y1 = cx;		//y1的类型是const int&，y绑定到变量x
	decltype(cr + 0) y2 = cx;		//y2的类型是int，y绑定到变量x

	/* 切记：decltype((variable))（注意是双层括号）的结果永远是引用，
		而decltype(variable)结果只有当variable本身就是一个引用时才是引用 */

	std::cerr << "DATA must!!!" << endl;
	return 0;
}