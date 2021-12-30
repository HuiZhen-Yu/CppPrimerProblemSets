#pragma once
#include <string>
#include <memory>
#include <utility>

using std::string;
using std::size_t;
using std::allocator;
using std::pair;

class HasPtr_val
{
	friend void swap(HasPtr_val&, HasPtr_val&);
public:
	HasPtr_val(const string& s = string()) :
		ps(new string(s)), i(0) {}
	//对ps指向的string，每个HasPtr对象由自己的拷贝
	HasPtr_val(const HasPtr_val& p) :
		ps(new string(*p.ps)), i(p.i) {}
	HasPtr_val& operator = (const HasPtr_val&);
	HasPtr_val& operator = (HasPtr_val);
	~HasPtr_val() { delete ps; }

private:
	string* ps;
	int i;
};

class HasPtr_Ptr
{
public:
	//构造函数分配新的string和新的计数器，将计数器置为1
	HasPtr_Ptr(const string& s = string()) :
		ps(new string(s)), i(0), use(new size_t(1)) {}
	//拷贝构造函数由三个数据成员，并递增计数器
	HasPtr_Ptr(const HasPtr_Ptr& p) :
		ps(p.ps), i(p.i), use(p.use) {	++* use;	}
	HasPtr_Ptr& operator=(const HasPtr_Ptr&);

	~HasPtr_Ptr();

private:
	string* ps;
	int i;
	size_t* use;	//	记录由多少共享的*ps成员

};

inline void swap(HasPtr_val& lhs, HasPtr_val& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}


class StrVec
{
public:
	StrVec() :		//allocator成员进行默认初始化
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);					//拷贝构造函数
	StrVec(StrVec&&) noexcept;						//移动构造函数
	StrVec& operator = (const StrVec&);		//拷贝赋值运算符
	StrVec& operator = (StrVec&&) noexcept;	//移动赋值运算符
	~StrVec();								//析构函数
	void push_back(const string&);			//拷贝元素
	void push_back(string &&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }

private:
	allocator<string> alloc;	//分配元素
	//添加元素的函数所使用
	void chk_n_alloc()
	{	if (size() == capacity()) reallocate();	}
	//工具函数，被拷贝的构造函数、赋值运算符和析构运算符
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();						//销毁元素并释放内存
	void reallocate();					//获得更多内存并拷贝已有的元素
	string* elements;					//指向数组首元素的指针
	string* first_free;					//指向数组第一个空闲元素的指针
	string* cap;						//指向数组尾后位置的指针
};

