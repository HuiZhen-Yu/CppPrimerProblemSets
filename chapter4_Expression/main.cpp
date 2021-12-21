#include <iostream>
#include <string>

using namespace std;

int main()
{
	/* 左值和右值 */
	//如果表达式的求值结果是左值，decltyoe作用于该表达式得到一个引用类型。
	//假设p的类型是int*，因为解引用生成左值，所以decltype(p)的结果是int&。
	//另一方面，因为取地址运算符生成右值，所以decltype(&p)的结果是int**，指向整形指针的指针

	/* 优先级规定了运算对象的组合方式，但是没有说明运算对象按照什么顺序求值 */
	//有四种运算符规定了求职顺序 && || ?: ,
	//算数运算符的运算对象和求值结果都是右值

	/* 成员访问运算符 */
	string s1 = "a string", * p = &s1;
	auto n = s1.size();
	n = (*p).size();
	n = p->size();

	/* 位运算符，强烈建议仅将位运算符用于处理无符号类型 */

	/* 逗号运算符 */

	/* 显示转换 static_cast、dynamic_cast、const_cast、reintepret_cast */
	//static_cast:用于非多态类型转换(静态转换)，任何标准转换都可以用它，但是不能用于两个不相关的类型转换。
	int i = 0, j = 0;
	double slope = static_cast<double>(j) / i;
	double d = 0.23;
	i *= static_cast<int>(d);
	//const_cast:只能改变运算对象的底层const，删除变量const的属性，方便赋值
	//如果对象本身不是一个常量，获得写权限是合法的行为，如果对象是个常量，则产生未定义后果
	//一般只用于有函数重载的上下文中
	const char* cp = "adgfag";
	//char* q = static_cast<char*>(cp);//错误，static_cast不能转换const性质
	string str = static_cast<string>(cp);
	//const_cast<string>(cp);//错误，const_cast只能改变常量属性

	//reintepret_cast:将一种类型转换为另一种不同的类型。通常为运算对象的位模式提供较低层次上的重新解释
	int* ip = &i;
	char* pc = reinterpret_cast<char*>(ip);

	return 0;
}

