#include "HasPtr_item.h"


HasPtr_val& HasPtr_val::operator=(const HasPtr_val& rhs)
{
	auto newp = new string(*rhs.ps);	//底层string
	delete ps;	//释放旧内存
	ps = newp;	//从右侧运算对象拷贝数据到本对象
	i = rhs.i;
	return *this;	//返回本对象
}

HasPtr_val& HasPtr_val::operator=(HasPtr_val rhs)
{
	//交换左侧运算对象和局部变量rhs的内容
	swap(*this, rhs);
	return *this;
}


HasPtr_Ptr& HasPtr_Ptr::operator=(const HasPtr_Ptr& rhs)
{
	++* rhs.use;	//递增右侧运算符对象的引用计数
	if (-- * use == 0) {	//递减本对象的引用计数
		delete ps;			//如果没有其他用户
		delete use;			//释放本对象分配的成员
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}


HasPtr_Ptr::~HasPtr_Ptr()
{
	if (-- * use == 0)	//如果引用计数变为0
	{
		delete ps;		//释放string内存
		delete use;		//释放计数器内存
	}
}

StrVec::StrVec(const StrVec& s)
{
	//调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec&& s) noexcept		//移动操作不应抛出异常
//成员初始化器接管s中的资源
	:elements(s.elements),first_free(first_free),cap(s.cap)
{
	//令s进入这样的状态--对齐运行析构函数是安全的
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	//调用alloc_n_copy内存分配，大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec& StrVec::operator = (StrVec&& rhs) noexcept
{
	//检测到直接赋值
	if (this != &rhs)
	{
		free();			//释放已有元素
		elements = rhs.elements;	//从rhs接管资源
		first_free = rhs.first_free;
		cap = rhs.cap;
		//将rhs置于可析构状态
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}


void StrVec::push_back(const string& s)
{
	chk_n_alloc();		//确保由空间容纳新元素
	//在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string&& s)
{
	chk_n_alloc();		//确保由空间容纳新元素
		//在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, std::move(s));
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string* b, const string* e)
{
	//分配空间保存给定范围中的而元素
	auto data = alloc.allocate(e - b);
	//初始化并返回一个pair，该pair由data和unitialized_copy的返回值构成
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	//不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
	if (elements) {
		//逆序销毁元素
		for (auto p = first_free; p != elements;/* 空 */)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	//我们将分配当前大小两倍的空间
	auto newcapacity = size() ? 2 * size() : 1;
	//分配新内存
	auto newdata = alloc.allocate(newcapacity);
	//将数据从旧内存移动到新内存
	auto dest = newdata;	//指向新数组中下一个空闲位置
	auto elem = elements;	//指向旧数组中下一个元素
	for (size_t i = 0;i != size();++i)
		alloc.construct(dest++, std::move(*elem++));
	//换种方式更简单
#if 0
	auto first = alloc.allocate(newcapacity);
	//移动元素
	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
#endif

	free();			//一旦我们完成移动元素就释放旧内存空间
	//跟新我们的数据结构，执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

StrVec::~StrVec()
{
	free();
}
