#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

/* 
* 重载运算符与类型转换 
* 当运算符被用于类类型的对象的时候，c++允许我们为其指定新的含义；
* 重载运算符是具有特殊名字的函数：它的名字由关键字operator和其后要定义的运算符号共同组成。重载运算符也包含返回类型、参数列表以及函数体
* 除了重载的函数调用运算符operator()之外，其他重载运算符不能含有默认实参
* 如果一个运算符函数是成员函数，则他的第一个（左侧）运算对象绑定到隐式的this指针上，因此成员运算符函数的参数数量比运算符的运算对象少一个
* 对于一个运算符函数来说。它或是类的成员，或者至少含有一个类类型的参数。
*/

//普通函数
int add(int i, int j)
{
	return i + j;
}

int main()
{
	/* 重载运算符的调用 */
	//一个非成员运算符的等价调用	data1 + data2;	operator + (data1, data2);
	//成员运算符		data1 += data2;	等价于	data1.operator+=(data2);
	//通常情况下，不应该重载逗号，取地址，逻辑与和逻辑或运算

	/* 输入输出运算符（非成员函数） */
	//重载输出运算符		<<		ostream &operator<<(ostream & os,const Sales_data &item);	输出运算符尽量减少格式化操作
	//重载输入运算符		>>		istream &operator>>(istream & is,const Sales_data &item);	输入运算符必须处理输入可能是失败的情况
	//if(is) ... else ..

	/* 算术和关系运算符(通常情况下都是非成员函数) */
	//如果某个类在逻辑上由相等的含义，则该类应该定义operator==，定义了==也应该定义！=
	//赋值运算符 = ;vector<string> v; v = {"a", "an", "the"}; StrVec &operator=(std::initializer_list<std::string>); 不管形参是什么，赋值运算符必须定义为成员函数
	//复合赋值运算符

	//下标运算符（必须是成员函数），如果一个类包含下标运算符，则它通常定义两个版本，一个返回普通引用，另一个是类的常量成员，并返回常量引用
	//递增和递减运算符，这两种应该同时定义，并且这些运算符通常应该被定义成类的成员
	//前置：StrBlobPtr &operator++(); StrBlobPtr &operator--();  返回递增/递减之后的引用
	//后置：为了区分前置版本和后置版本，后置版本接收一个额外的，不被使用的形参。StrBlobPtr &operator++(int); StrBlobPtr &operator--(int);后置版本应该饭hi对象的原值(递增或者递减之前的值)返回应该是一个值而不是一个引用
	 
	//成员访问运算符 *；->（必须是类的成员） 重载箭头运算符必须返回类的指针或者自定义了箭头运算符的某个类的对象
#if 0
	class StrBlobPtr {
	public:
		std::string& operator*() const
		{
			auto p = check(curr, "difference past end");
			return (*p)[curr];		//(*p)是对象所指的vector
		}
		std::string* operator->() const
		{	//将实际工作委托给解引用运算符
			return &this->operator*();			
		}
		//其他成员
	};

#endif

	/* 函数调用运算符 */
	//如果重载了函数调用运算符，则我们可以像使用函数一样使用该类的对象。因为这样的类同时也能存储状态，与普通函数比更加灵活
	//函数调用运算符必须是成员函数。一个类可以定义多个不同版本的调用运算符，各个应该在参数数量或者类型上有所区别
#if 1
	struct absInt {
		int operator() (int val) const {
			return val < 0 ? -val : val;
		}
	};
#endif
	//如果定义了调用运算符，则该类的对象称作函数对象（function object）。因为可以调用这种对象，所以我们说这些对象的行为像函数一样

	cout << sizeof(absInt) << endl;

	/* lambda是函数对象 */
	//当我们编写了一个lambda后，编译器将表达式翻译成一个未命名类的未命名对象。在lambda表达式产生的类中含有一个重载的函数调用运算符

#if 0
	//根据单词的长度对齐进行排序，队医长度相同的单词按照字母表顺序排序
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size();});
	//其行为类似与下面这个未命名对象
	class ShorterString 
	{
	public :
		bool operator()(const string& s1, const string& s2) const
		{
			return s1.size() < s2.size();
		}
	};
	stable_sort(words.begin(), words.end(), ShorterString());
#endif

	/* 标准库定义的函数对象 */
	//plus modulus equal_to
	plus<int> intAdd;		//对int加法的函数对
	negate<int> intNegate;	//对int值取反的函数对象

	int sum = intAdd(10, 20);
	sum = intNegate(intAdd(10, 20));

	//传入一个临时的函数对象用于执行两个string对象大于的比较运算
//	sort(svec.begin(), svec.end(), greater<string>());

	//注意指针的使用
#if 0
	vector<string*> nameTable;
	//错误nameTable中的指针没有彼此关系
	sort(nameTable.begin(), nameTable.end(), [](string* a, string* b) {return a < b;});
	//正确 标准库规定指针的less是良好的
	sort(nameTable.begin(), nameTable.end(), [](string* a, string* b) {return a < b;});
#endif
	//关联容器使用less<key_type>进行排序

	/* 可调用对象与function */
	//c++中有几种可调用的对象：函数、函数指针、lambda表达式、bind创建的对象以及重载了函数调用运算符的类
	//和其他对象一样，可调用对象也有类型，两个不同类型的可调用对象可能共享一种调用形式(call signature)

	//为了进行区分，我们需要定义一个函数表，用于存储指向这些可调用对象的“指针”
#if 0
	//普通函数
	int add(int i, int j) { return i + j; }
	//lambda，其产生一个未命名的函数对象类
	auto mod = [](int i, int j) {return i % j;};
	//函数对象类
	struct divide
	{
		int operator() (int denominator, int divisor) { return denominator / divisor; }
	};
	//函数表 构建从运算符到函数指针的映射关系，其中函数接受连个int、返回一个int
	map<string, int(*)(int, int)> binops;
	binops.insert({ "+", add });	//{"+", add}是一个pair
	//但是我们却不能 binops.insert({"%s", mod});		//错误：mod不是一个函数指针
	//为了解决这个问题，我们建立一个名为function的新的标准库类型解决上述问题
#endif

	//lambda，其产生一个未命名的函数对象类
	auto mod = [](int i, int j) {return i % j;};
	//函数对象类
	struct divide
	{
		int operator() (int denominator, int divisor) { return denominator / divisor; }
	};
	//function的新标准库类型解决上述问题，function定义在functiontial头文件中，存储管理可调用对象
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = divide();
	function<int(int, int)> f3 = [](int i, int j) {return i % j;};

	cout << f1(4, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 2) << endl;

	//可以使用这个function类型重新定义map
	//可调用对象与二元运算符对应关系的表格
	//所有可调用对象都必须接收两个int，返回一个int
	//其中的元素可以是函数指针，函数对象或者是lambda
	map<string, function<int(int, int)>> binops = {
		{"+", add},										//函数指针
		{"-", std::minus<int>()},						//minus<int>的调用运算符
		{"/", divide()},								//用户定义的函数对象
		{"*", [](int i, int j) { return i * j;}},		//未命名的lambda表达式
		{"%", mod}										//命名了的lambda表达式
	};
	
	cout << binops["+"](10, 5) << endl;			//调用了add(10, 5)
	cout << binops["-"](10, 5) << endl;			//使用minus<int>的调用运算符
	cout << binops["*"](10, 5) << endl;			//调用lambda函数对象
	cout << binops["/"](10, 5) << endl;			//调用divide的调用运算符
	cout << binops["%"](10, 5) << endl;			//调用lambda函数对象

	//重载的函数与function
	//我们不能直接将重载的函数名字直接存入function中
#if 0
	int add(int i, int j) { return i + j; }
	Sales_data add(const Sales_data&, const Sales_data&);
	map<string, function<int(int, int)>> binops;
	binops.insert({"+", add});		//错误，不知道加那个add

	//解决函数的二义性问题的方式就是存储函数指针而不是函数名字
	int (*fp)(int, int) = add;
	binops.insert({ "+", fp });		//正确

	//也可以用lambda来消除二义性
	binops.insert({ "+", [](int a, int b) {return add(a,b);} });		//正确
#endif

	/* 重载类型转换与运算符 */
	//转换构造函数和类型转换运算符共同定义了类类型转换（class-type conversiton）,这样的转换有事也被称作用户定义的类型转换（user-define conversions）
	//类型转化运算符（conversion operator）是类的一种特殊成员函数，转换形式为opeartor type() const;

	//一个类型转换函数必须是类的成员函数，它不能申明返回类型，新参列表也必须为空。类型转换函数通常应该是const
	//类型转换可能会产生意外的效果
	int i = 42;
//	cin << i; //cin会被转换成bool，然后再被转换成int，左移42位

#if 0
	//显示的类型转换运算符（explicit conversion operator）
	class SmallInt {
		public:
			//编译器不会自动执行这一类型的转化
			explicit operator int() const { return val; }
			//其他成员都是一致的
	};
	SmallInt si = 3;			//正确，SmallInt的构造函数不是显示的
	si + 3;						//错误：此处需要隐式的类型转换，但是类的运算符是显式的
	static_cast<int> (si) + 3;	//正确：显示的请求类型转换
#endif

	//不要为类定义相同的类型转换，也不要在类中定义两个以及两个以上转换源或转换目标是算术类型的转化。
	//最好不要在两个类之间构建相同的类型转换
#if 0
	struct B;
	struct A {
		A() = default;
		A(const B&);	//把一个B转换成A
		//其他的数据成员
	};

	struct B {
		operator A() const;		//把一个B转换成A
		//其他数据成员
	};

	A f(const A&);
	B b;
	A a = f(b);	//二义性错误：含义是f(B::operator A())
				//还是f(A::A(const B&));

	A a = f(b.operator A());
	A.a2 = f(A(b));
#endif

	//函数匹配与运算重载符号 重载的运算符也是重载的函数

#if 0
	class SmallInt() {
		friend SmallInt operator +(const SmalllInt&, const SmalllInt&);
	public:
		SmallInt(int = 0);						//转换源为int的类型转换
		operator int() const { return val; }	//二义性错误
	private:
		std::size_t val;
	};

	SmallInt s1, s2;
	SmallInt s3 = s1 + s2;	//使用重载的+
	int i = s3 + 0;			//二义性错误 0->SmallInt or？ s3->int
#endif


	return 0;
}