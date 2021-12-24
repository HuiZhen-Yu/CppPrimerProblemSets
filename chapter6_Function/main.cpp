#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool HasUpper(const string& str)
{
	for (auto c : str)
		if (isupper(c))
			return true;
	return false;
}

void ChangeToLower(string& str)
{
	for (auto& c : str)
		c = tolower(c);
}

/* 参数类型一样的多个形参 */
void error_msg1(initializer_list<string> il)
{
	for (auto beg = il.begin();beg != il.end();beg++)
		cout << *beg;
	cout << endl;
}

/* 递归调用 */
void print_vector(vector<int> vInt, unsigned index)
{
	auto sz = vInt.size();
	if (!vInt.empty() && index < sz)
	{
		cout << vInt[index] << endl;
		print_vector(vInt, index + 1);
	}
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int doub(int a, int b)
{
	return a * a + b * b;
}

decltype(add) *func_p = add;

int main(int argc,char **argv)
{
	/* const形参和实参 */
	//顶层const作用于变量本身，函数作为形参的时候顶层的const会被忽略掉

	//函数在传值的时候尽量使用常量引用
	//string str = "ajfoajiHALSJDF";
	//string const str1 = "sagseg";
	//
	//if (HasUpper(str))
	//{
	//	cout << str << " str有大写字母" << endl;
	//	ChangeToLower(str);
	//	cout << str << " str转换之后" << endl;
	//}
	//else
	//{
	//	cout << str << "没有大写字母" << endl;
	//}

	//bool compare(const Matrix&,const Martix&);
	//vector<int>::iterator change_val(int, vector<int>::iterator);

	/* main:处理命令行选项 */
	//string str;
	//cout << argc << endl;
	//for (int i = 0;i != argc;i++)
	//{
	//	str += argv[i];
	//	cout << argv[i] << endl;
	//}
	//cout << str << endl;

	/* 含有可变形参的函数 */
	//如果所有的形参类型相同，可以传递名为initializer_list的标准库类型
	//和vector不一样的是，initializer_list中的值永远是常值（言外之意和vector的用法差不多）

	string a = "Hello World!!\r\n";
	string b = "Hello Compass!!\r\n";
	string c = "Hello SEU!!\r\n";
	initializer_list<string> lst{ a,b,c };
	error_msg1(lst);
	error_msg1({ "Hello World!!\r\n","Hello Compass!!\r\n","Hello SEU!!\r\n" });

	/* 调用一个返回引用的函数得到的是一个左值，其他情况返回右值 */

	/* 函数的递归（直接递归和简介递归）：首先要确定递归规律和递归中止的条件 */

	/* 尾置返回类型 */

	/* 函数重载 在不同的作用域中无法重载函数名 */
	/* 默认实参，某个实参被赋予了默认值，它后面的所有形参都必须赋予默认值，调用的时候只能省略尾部实参 */

	/* 内联函数和constexpr */
	//constexpr函数的返回类型及所有的形参都得是字面值类型，而且函数体中只能有一个return，且函数被隐式地指定位内联函数
	//内联函数和constexpr函数通常定义在头文件中

	/* 函数指针 */
	int (*func5)(int, int);
	vector<decltype(func5)>func_vec = { add,sub,mul,doub };
	//func_vec.push_back(add);
	//func_vec.push_back(sub);
	//func_vec.push_back(mul);
	//func_vec.push_back(doub);

	for (auto funct : func_vec)
	{
		cout << (*(*funct))(2, 3) << endl;
	}

	cout << func_p(2, 3) << endl;
	cout << (*func_p)(2, 3) << endl;
	cout << (*(*func_p))(2, 3) << endl;
	return 0;
}


/* 尾置参数类型 */
//传统定义
int(*func(int arr[][3], int n))[3]{
	return &arr[n];
}
//使用尾置类型后
auto func1(int arr[][3], int n) -> int(*)[3]
{
	return &arr[n];
}

/* decltype的使用 */
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
//返回一个指针
decltype(odd)* arrPtr(int i)
{
	return (i % 2) ? &odd : &even;//返回一个指向数组的指针
}

string (&func())[10];

//使用类型别名
typedef string (&arr)[10];
arr func3();

//使用尾置返回类型
auto func4()->string(&)[10];

//使用decltype()关键字
string str4[10];
decltype(str4)& func5();