#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <stdexcept> 
#include "Blob_item.h"

using namespace std;

/* 动态内存 
* 
* 到目前为止我们只用到静态内存与栈内存
* 静态内存用来保存局部static对象、类static数据成员，以及定义在任何函数之外的变量
* 栈内存用来保存定义函数内的非static对象。
* 分配在静态或栈内存中的对象由编译器自动创建与销毁。对于栈对象，仅在其定义的程序块运行时才存在，static对象在使用前分配，在程序结束时销毁
* 
* 除了静态内存和栈内存，每个程序还拥有一个内存池。这部分内存被称为自由空间（free store）或堆（heap）
* 程序用堆来存储动态分配（dynamically allocate）的对象--即，那些在程序运行时分配的对象。
* 动态对象的生存期由程序来控制，也就是说，当动态对象不再使用的时候，我们的代码必须显示的销毁他们。
* 
*/

vector<int>* new_vector()
{
	return new(nothrow) vector<int>;
}

shared_ptr<vector<int>> new_vector_s()
{
	return make_shared<vector<int>>();
}

void read_inV(vector<int> *pv)
{
	int v;
	while (cin >> v)
		pv->push_back(v);
}

void read_inV_s(shared_ptr<vector<int>> spv)
{
	int v;
	while (cin >> v)
		spv->push_back(v);
}

void print_ints(vector<int>* pv)
{
	for (const auto v : *pv)
		cout << v << " ";
	cout << endl;
}

void print_ints_s(shared_ptr<vector<int>> spv)
{
	for (const auto v : *spv)
		cout << v << " ";
	cout << endl;
}
int main()
{
	/* 动态内存与只能指针 */
	//为了更好的使用动态内存，新的标准库提供了两种智能指针（smart pointer）类型来管理动态内存对象
	//shared_ptr: 允许多个指针指向同一对象	; unique_ptr：独占所指向的对象; 标准库还定义了一种weak_ptr的伴随类，他是一种弱引用，指向shared_ptr所管理的对象

#if 0
	//类似vector，智能指针也是模板，当我们创建智能指针的时候也需要给出额外的信息，指针可以指向的的类型
	shared_ptr<string> p1;	//shared_ptr 指向 string
	shared_ptr<list<int>> p2;	//shared_ptr指向 int的list

	if (p1 && p1->empty())
		*p1 = "hi";	//如果p1指向一个空string，解引用p1，将一个新值赋给string

	//最安全的分配和使用动态内存的方式时调用一个叫做make_shared的标准库函数，此函数在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr。
	shared_ptr<int> p3 = make_shared<int>(42); 
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>();
#endif
	/* shared_ptr的拷贝和赋值 */
	//当进行拷贝或者赋值操作时，每个shared_ptr都会记录有多少个其他shared_ptr指向相同的对象。（不初始化就是一个空指针）
	//我们可以认为每个shared_ptr都有一个关联的计数器，通常称其为引用计数（reference count）。
	//无论何时我们拷贝一个shared_ptr，计数器都会递增，当我们给shared_ptr赋予一个新值或是shared_ptr被销毁（离开作用域）计数器就会递减；

	//shared_ptr自动销毁所管理的对象，通过析构函数实现的，并且其还会自动释放相关的额内存
	//当多个对象共享相同状态的时候就会用到动态内存管理
#if 0
	vector <int> a;
	a.push_back(1);
	try {
		a.at(1);
	}
	catch (std::out_of_range exc) {
		std::cerr << exc.what() << " Line:" << __LINE__ << " File:" << __FILE__ << endl;
	}
	return EXIT_SUCCESS;
#endif

#if 0
	StrBlob b1;
	{
		StrBlob b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;
	
	const StrBlob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;
#endif

	/* 直接管理内存 */
	//new 分配内存，delete释放new分配的内存
	//自己直接管理内存的类与使用智能指针的类不同，他们不能依赖类对对象拷贝、赋值和销毁操作的任何默认定义
#if 0
	int* pi = new int{1024};
	int* pi1 = new int;	//未定义值
	int* pi2 = new int();//初始化为0
	const int* pci = new const int(1024);
	string* ps = new string(10, '9');
	vector<int>* pv = new vector<int>{ 0,1,2,3,4,5,6,7,8,9 };

	auto p1 = new auto(12);
	//auto p2 = new auto{12, 13};//错误只能有单一初始化器
	int* p11 = new int;	//如果分配失败，new抛出std::bad_alloc
	int* p2 = new (nothrow) int;	//如果分配失败，则返回空指针，称这种形式的new为定位new（placement new）

	//释放动态内存 通过delete表达式（delete expression）来将动态内存归还给系统。delete表达式接收一个指针，指向我们想要释放的地方
	delete pi;		//pi必须是指向一个动态内存分配的内存，或者是一个空指针
	//delete指向两个动作，销毁给定的指针指向的对象；释放对应的内存
	//const对象的值不能改变，但是空间可以被销毁
	//有内置指针（而不是智能指针）管理的动态内存在被显式的释放前一直都会在，重复delete可能会破坏自由空间，delete之后指针就变成了人们说的空悬指针（dangling pointer）
	//尽量在delete之后用nullptr指向指针
#endif

#if 0
	vector<int>* pv = new_vector();
	if (!pv)
	{
		cerr << "内存不足！" << endl;
		return -1;
	}

	read_inV(pv);
	print_ints(pv);

	delete pv;
	pv = nullptr;

	auto spv = new_vector_s();
	read_inV_s(spv);
	print_ints_s(spv);

#endif

	//shared_ptr与new结合使用
	//shared_ptr<int> p1 = new int(1024);	//错误，必须使用直接初始化形式
	shared_ptr<int> p1(new int(1024));
	//使用内置指针来访问一个智能指针的行为很危险，因为我们不知道对象什么时候会被销毁
	//不要使用get初始化另一个智能指针或者为智能指针赋值，使用get返回的指针的代码不能delete此指针（get用来将指针的访问权限传递给代码，你只有在确定代码不会delete指针的情况下才能使用get）
	//reset来将一个新的指针赋予shared_ptr和unique一起配合使用 p414

	//如果使用内置指针管理，new之后，delete之前，发生了异常，则内存不会被释放
	//通过shared_ptr进行我们自己的释放操作，当我们创建一个shared_ptr的时候，可以传递一个可选的指向删除器函数的参数
	//void end_connection(connection *p) { disconnect(*p); }
	//void f(destination &d /* 其他参数 */) 
	//{ connection c = connect(&d);shared_ptr<connection> p(&c, end_connection);
	//	使用连接；当f退出的时候，connection会被正确关闭
	// }

	//unique_ptr 某个时刻只能由一个umique_ptr指向一个给定对象。当unique_ptr被销毁时，它所指向的对象也被销毁
	//当我们i当以一个unique_ptr的时候，需要将其绑定到一个new指针上，初始化必须采用直接初始化的形式
	

	//weak_ptr是一种不控制所指向对象生存期的智能指针，它指向由一个shared_ptr管理的对象，将weak_ptr绑定到shared_ptr不会改变引用计数，
	//我们不能直接调用weak_ptr，需要用lock

	/* 动态数组 */
	//初始化
	//类allocator，允许我们将分配和初始化分离
	int* pia = new int[10];
	int* pia2 = new int[10]();	//全为零
	int* pia3 = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };//如果超过了数目，就产生bad_array_new_length（头文件new中）
	string* psa = new string[10];

	delete [] pia;
	delete [] pia2;
	delete [] pia3;
	delete [] psa;

	//释放，为了释放动态数组，delete在指针前加上一个空方括号对
	typedef int arrT[42];
	int* p = new arrT;
	delete[]p;		//方括号是必须的，因为我们当初分配的是一个数组

	//管理new分配数组的unique_ptr版本
	//up指向一个包含10个未初始化int的数组
	unique_ptr<int[]> up(new int[10]);
	for (size_t i = 0;i != 10;++i)
		up[i] = i;		//	为每个元素赋予一个新值
	for (size_t i = 0;i != 10;++i)
		cout << up[i] << " ";
	cout << endl;
	up.release();	//自动用delete[]销毁其指针

	/* allocator类（模板） */
	//定义在memory的头文件中，它帮助我们将内存分配和对象构造分离开来。它提供一种类型感知的内存分配方式，它分配的内存是原始的、未构造的

	allocator<string> alloc;	//可以分配string的allocator对象
	auto const p_1 = alloc.allocate(10);	
	auto q = p_1;
	alloc.construct(q++);	//空字符串
	alloc.construct(q++, 10, 'c');	//*q为"cccccccccc"
	alloc.construct(q++, "hi");		//*q为hi

	while (q != p_1)
		alloc.destroy(--q);	//释放真正构造的string

	//元素销毁后，释放内存通过deallocate来完成；
	alloc.deallocate(p_1, 10);

	//cout << *(--q) << endl;

	return 0;
}