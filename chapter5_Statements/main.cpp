#include <iostream>
#include <string>
#include <vector>
#include "Sales_item.h"

using namespace std;

int main()
{
	/* 1.switch内部的变量定义 */
	//bool a = false;
	//switch (a)
	//{
	//case true:
	//	//因为程序的执行流程可能绕开下面的初始化语句，所以该switch语句不合法
	//	//string file_name = "name";	//错误：控制流绕过一个隐式初始化的变量
	//	//string ival = 0;	//错误：控制流绕过一个显示初始化的变量
	//	int jval;			//正确：因为jval没有初始化
	//	break;
	//case false:
	//	//正确：jval虽然在作用域内，但是它没有被初始化
	//	jval = 9;
	//	break;
	//
	//}
	//
	//switch (a)
	//{
	//case true:
	//{
	//	string file_name = "name";	//正确
	//	string ival = 0;	//正确
	//	int jval;			//正确
	//	break;
	//}
	//case false:
	//	//错误：jval在作用域外
	//	//jval = 9;
	//	break;
	//
	//}

	/* 2.while循环 */
	//当不确定循环的次数，或者在循环结束后访问循环控制变量
	//vector<int> v;
	//int i;
	////重复读入数据直到文件末尾或者其他
	//while (cin >> i)
	//	v.push_back(i);
	////寻找第一个负值元素
	//auto beg = v.begin();
	////decltype(v.begin()) beg = v.begin();
	//while (beg != v.end() && *beg >= 0)
	//	++beg;
	//if (beg == v.end())
	//	cout << "所有数据都大于0" << endl;

	///* 3.for语句 */
	////for中的init_statement只能有一个声明语句，所有变量的基础类型必须相同，可以定义多个对象
	//for (int i = 0, double j = 0;i < 30;i++)
	//{

	//}

	//范围for语句

	/* 4.do while语句 不允许在循环条件内定义变量 */

	/* 5.try语句块和异常处理 */
	//throw表达式（throw expression），异常检测部分使用了throw表达式来表示它遇到了无法处理的问题。我们说throw引发（rise）了异常；
	//try语句块（try blok），try语句快以关键字try开始，并以一个或者多个catch子句（catch clause）结束。
	//try语句块中代码抛出的异常通常会被某个catch子句处理。因为catch子句处理异常，所以它们也被称为异常处理模块；
	//一套异常类（expression class），用于在throw表达式和相关的catch字句之间传递异常的具体信息。
	
	//Sales_item item1, item2;
	//cin >> item1 >> item2;
	//首先检查item1和item2是否表示同一种书籍
	//if (item1.isbn() == item2.isbn())
	//{
	//	cout << item1 + item2 << endl;
	//}
	//else {
	//	cerr << "Data must refer to same ISBN" << endl;
	//	return -1;// 表示失败
	//}

	Sales_item item1, item2;
	cin >> item1 >> item2;
	try
	{
		if (item1.isbn() != item2.isbn())
			throw runtime_error("Data must refer to same ISBN");
		cout << item1 + item2 << endl;
	}
	catch (runtime_error err)
	{
		cerr << err.what() << endl;
	}

	/* 标准异常 */
	//exception头文件定义了最通用的异常类exception。它只报告异常的发生，不提供任何额外信息。
	//stdexcept头文件定义了几种常用的异常类








	return 0;
}