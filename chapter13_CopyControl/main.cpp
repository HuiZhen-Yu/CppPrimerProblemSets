#include <iostream>
#include <string>
#include <vector>
#include "HasPtr_item.h"
#include <utility>

using namespace std;

/* 拷贝控制 */
//当定义一个类时，我们显示或者隐式地指定在此类型的对象拷贝、移动、赋值和销毁时做什么。一个类通过五种特殊的成员函数来控制这些操作。拷贝控制操作（copy control）
//包括：拷贝构造函数(copy construction)拷贝赋值运算符(copy_assignment operator),移动构造函数(move construction),移动赋值运算符(move-assignment operator),和析构函数(destructor)
//拷贝和移动构造函数定义了用同类型的另一个对象初始化本对象时需要做什么。拷贝和移动赋值运算符定义了将一个对象赋予同类型的另一个对象的时候做什么。析构函数当此类型对象销毁时做什么；

//在定义任何C++类的时候，拷贝控制操作都是必要的部分

class A
{
	int& a;		//sizeof(A) = 4
};

class B
{
	//sizeof(B) = 1
};

int main()
{
	//拷贝构造函数 ->合成拷贝构造函数
	//拷贝构造函数发生的情况：1.用=定义变量的时候。2.将一个对象作为实参传递给一个非引用类型的形参。3.从一个返回类型为非引用类型的函数返回一个对象。4.用花括号列表初始化一个数组中的元素或者一个聚合类中的成员。
	string dots(10, '.');	//直接初始化
	string s(dots);			//直接初始化
	string s2 = dots;		//拷贝初始化
	string null_book = "99-99-999-9999";	//copy initialization
	string nines = string(100, '9');		//copy initialization

	//explicit -- contraints on copy initialization
	
	//The copy-assignment operator 与拷贝构造函数一样，如果类未定义自己的拷贝赋值运算符，编译器会为他合成一个，重载运算符本质是函数
	//Sales_data trans, accum;
	//trans = accum;
	//赋值运算符通常应该返回一个指向其左侧运算对象的引用

	//析构函数，与构造函数相反，构造函数初始化对象的非static数据成员，析构函数释放对象的资源，并销毁对象的非static数据成员
	//析构函数是类的一个成员函数，名字由波行号接类名构成，没有返回值；析构函数不接受参数，所以不能被重载，一个给定类只有唯一一个析构函数
	//当指向一个类的引用或者指针离开作用域，析构函数不会执行
	//析构函数体是作为成员销毁步骤之外的另一部分而进行的

	//需要析构函数的类也需要拷贝和赋值操作；需要拷贝操作的类也需要赋值操作
	//=default		显示要求编译器生成合成的版本
	//=delete		不能以任何形式使用他们（组织拷贝与赋值），必须出现在函数第一次声明的时候，析构函数不能是删除成员

	//需要区分像值的类和像指针的类
	//引用计数


	//交换操作swap，交换两个元素的时候会使用
	//using std::swap
	//swap(a, b);	如果存在特定版本的swap，swap调用会与之对应，如果不存在特定版本，则会使用std版本(假定作用域中由std申明)

	//拷贝控制（示例Folder 与 Message page461）代码练习

	//动态内存管理类
	//某些类需要在运行时分配可变大小的内存空间。这种类通常可以用标准库容器来保存他们的数据

	/* 对象移动，string的移动与交换 区分移动与拷贝 */
	/* 右值引用（rvalue reference）必须绑定到右值的引用 */
	//我们通过&&而不是&来获得右值的引用，智能绑定到一个将要销毁的对象，左值和右值是表达式属性，一个左值表达式表示的是一个对象的身份，而一个右值表达式表示的是对象的值

	//类似任何引用，一个右值引用也不过是某个对象的另一个名字而已，如我们所知，对于馋鬼引用（为了与右值引用区分，称之为左值引用），我们不能将其绑定到要求转换的表达式，字面常量或是返回右值的表达式。右值引用有着完全相反的绑定性质：我们可以将一个右值绑定到这类表达式上，但是不能将右值引用绑定到左值引用上
	int i = 42;
	int& r = i;				//r引用i
	//int&& rr = i;			//错误		
	//int& r2 = i * 42;		//错误
	const int& r3 = i * 42;	//可以将一个const的引用绑定到一个右值上 先在数据区开辟一个值为i*42的无名整型量，再将引用a与这个整型量进行绑定。
	int&& rr2 = i * 42;		//右值引用 和const int& r3 = i * 42;是完全一样的操作，先在数据区开辟一个值为i*42的无名整型量，再将引用a与这个整型量进行绑定。但是右值引用直接支持rebind.

	//返回左值引用的函数，连同赋值、下标、解引用和前置递增/递减运算符，都是返回左值的表达式的例子
	//返回右值引用类型的函数，联通算术，关系、位以及后置递增递减运算符

	/*
	* int b = 0;
	* int &a = b;	等价于 int *const lambda = &b;
	*/

	//变量表达式也有左值/右值的属性，变量表达式都是左值，带来的结果是我们不能将一个右值引用绑定到一个右值引用类型的变量上，变量是左值，不能将右值引用直接绑定到一个变量上，即使这个变量是右值引用类型也不行
	int&& rr1 = 42;		//正确，字面值是右值
	//int&& rr2 = rr1;	//错误，表达式rr1是左值

	//标准库move函数 头文件utility中，使用move应该使用std::move,而不是move避免潜在的名字冲突
	int&& rr3 = std::move(rr1);		//OK move告诉编译器，我们有一个左值，但是我们希望像一个右值一样处理它（调用move意味着除了对rr1赋值或者销毁以外，我们不再使用它，如果这个时候使用结果是未定义的。）

	//关于noexcept 不抛出异常的移动构造函数和移动赋值运算符必须标记位noexcept

	//移动赋值运算符 移动赋值运算符执行与析构函数和移动构造函数相同的工作

	//合成的移动操作

	//移动右值，拷贝左值
	//如果一个类既有移动构造函数，也有拷贝构造函数，编译器使用普通的函数匹配规则来确定使用哪个构造函数
#if 0
	StrVec v1, v2;
	v1 = v2;		//v2是左值使用拷贝赋值
	StrVec getVec(istream&);
	v2 = getVec(cin);		//调用结果是个右值，使用移动赋值
#endif

	//如果没有移动构造函数，右值也会被拷贝，通过拷贝构造函数来实现移动，用拷贝构造函数代替移动构造函数几乎肯定是安全的
#if 0
	class Foo {
	public:
		Foo() = default;
		Foo(const Foo&);	//拷贝构造函数
		//其他成员函数，但是Foo未定义移动构造函数
	};
	Foo x;
	Foo y(x);				//拷贝构造函数，x是一个左值
	Foo z(std::move(x));	//拷贝构造函数，因为Foo未定义移动构造函数
#endif

	//拷贝并交换赋值运算符和移动操作 swap

	//移动迭代器(move iteator)  make_move_iteator()实现转换

	//我们希望在类中阻止向右值赋值的方式，即强制所测运算对象（即this指向的对象）是一个左值，
	//我们指定this左值右值属性的方式与定义const成员相同，即在参数列表后面放一个引用限定符（reference qualifier）
	//引用限定符可以是&或者&&，分别指出this可以指向一个左值或者是右值。类似const限定符，引用限定符只能用于（非static）成员函数，且必须同时出现在声明和定义中，一个函数可以同时用const和引用限定符，引用限定符必须在const限定符之后

	string s21 = "a value";
	string s22 = "another";

	auto n = (s21 + s22).find('a');

	s21 + s22 = "Wow !!";
	//int a31 = 323;
	//int b34 = 35;
	//a31 + b34 = 45;

#if 0
	class Foo 
	{
	public:
		Foo& operator=(const Foo&)&;	//只能向可修改的左值赋值
		//Foo其他参数
	};

	Foo& Foo::operator=(const Foo& rhs)&
	{
		//将rhs。。
		return *this;
	}

	Foo& retFoo();		//返回一个引用；retFoo调用是一个左值
	Foo	retVal();		//返回一个值，retVal调用是一个右值
	Foo i, j;			//i和j是左值
	i = j;				//正确 i是左值
	retFoo() = j;		//正确： retFoo()返回一个左值
	retVal() = j;		//错误：retVal()返回一个右值
	i = retVal();		//正确
#endif

	//引用限定符可以区分重载版本，（与const一样），如果我们定义两个或者两个以上具有同名和相同参数列表的成员函数，就必须对所有函数都加上引用限定符，或者所有都不加

#if 0
	class Foo{
	public:
		Foo sorted() &&;
		Foo sorted() const ;	//错误必须加上引用限定符

		using Comp = bool(const int&, const int&);
	}

#endif



	return 0;
}
