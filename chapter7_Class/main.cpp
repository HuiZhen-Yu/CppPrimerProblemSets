#include <iostream>
#include "Screen_item.h"
#include "Exercise.h"

using namespace std;

/*
* 类的基本思想时数据封装（data abstraction）和抽象（encapsulation）
* 数据抽象时一种依赖于接口（interface）和实现（implementation）分离的编程及设计技术。
* 类的接口包括用户所能执行的操作；类的实现包括类的数据成员、负责接口实现的函数体现及定义所需的各种私有函数。
* 
* 类的用户是指其他使用类的程序员，而不是使用程序的人。
* 
* 
*/




int main()
{
	/* 构造函数 */
	//构造函数没有返回类型，并且不能被声明为const
	//默认构造函数：1.如果存在类内初始值就用它来初始化函数，否则默认初始化该成员（编译器只有在没有默认初始化函数的情况下才会给我们进行默认初始化函数）
	//如果有其他构造函数，但是没有默认初始化，会出现问题

	/* 访问控制与封装 */
	//封装是指保护类的成员不被随意访问的能力；优点1确保用户代码不会无意间破坏封装对象的状态，优点2分装的类的具体细节可以随意改变

	/* 友元 */
	//友元声明只能出现在类定义的内部，但是在类内出现的具体位置不限。
	//友元不是类的成员函数，不受它所在区域访问控制级别的控制。
	//友元只是指定了访问的权限，而非通常意义上的函数声明。

	//类还可以将其他的类定义成友元，也可以把其他类（之前定义过的）成员函数定义成友元，
	//如果一个类指定了友元类，则友元类的成员函数可以访问此类包括非共有成员在内的所有成员

	Screen myScreen(5, 5, 'X');
	//const Screen blank(5, 3, ' ');

	//myScreen.set('#').display(cout);	//调用非常量版本
	//cout << '|' << endl;
	//blank.display(cout);		//调用常量版本

	myScreen.move(4, 0).set('#').display(cout);
	cout << '\n';
	myScreen.display(cout);
	cout << '\n';

	/* 类的作用域规则 */
	//局部变量，全局变量，以及类的成员
	

	//默认实参与构造函数 
	//委托构造函数 使用它所属类的其他构造函数执行它自己的初始化过程，一个委托构造函数也有一个成员初始值列表和一个函数体

	//默认构造函数：不明显的情况是类的某些数据成员缺少默认构造函数；
	vector<NoDefault> vec(1);
	vector<C> vecc(1);

	//构造函数的隐式转换，可以通过加explicit加以阻止隐式转换成当前类，explicit关键字旨在类内声明构造函数使用，并且只能有一个实参
	//explicit构造函数只能用于直接初始化


	/* 类的静态成员 */
	//类的静态成员与静态成员函数不与任何对象绑定在一起，他们不包含this指针，静态成员函数不能是const，也不能在静态成员函数内使用this指针
	//一个静态数据成员只能被定义一次，定义在任何函数之外，一旦被定义，就存在于整个函数周期

	return 0;
}