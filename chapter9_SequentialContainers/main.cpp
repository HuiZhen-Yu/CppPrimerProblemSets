#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <array>

using namespace std;

//bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
//{
//	for (;beg != end;beg++)
//		if (*beg == val)
//			return true;
//	return false;
//}

//vector<int>::value_type a;
//vector<int>::reference b;
//vector<int>::const_reference b;

vector<int>::iterator search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
	for (;beg != end;beg++)
		if (*beg == val)
			return beg;
	return end;
}

int main()
{
	/* 顺序容器概述 vector deque list forward_list string */
	//vector	可变大小数组。支持快速随机访问，在尾部之外的位置插入或者删除元素可能很慢
	//deque		双端队列，支持快速随机访问。在头尾位置插入/删除速度很快
	//list		双向链表。支持双向顺序访问。在list中任何位置进行插入/删除都很快
	//forward_list 单向链表。支持单向顺序访问。在链表任何位置进行插入/删除操作速度都很快
	//array		固定大小数组。支持快速随机访问。不能添加或者删除元素
	//string	与vector相似的容器。但是专门用于保存字符。随机访问快。在尾部插入删除速度很快

	//list<deque<int>> a;

	//当不需要写访问时，使用cbegin和cend

	//只有顺序容器的构造函数才接受大小参数，关联容器并不支持

	//标准库array具有固定大小
	array<int, 42> arr_1;
	//从list<int>初始化vector<double>
	list<int> ilist = { 1,2,3,4,5,6,7 };
	vector<int> ivec = { 7,6,5,4,3,2,1 };
	//容器类型不同不能使用拷贝初始化
	//vec<double> ivec(ilist);
	//元素类型相同，可以使用范围初始化
	vector<double> dvec(ilist.begin(), ilist.end());

	//容器类型不同，不能使用拷贝初始化
	//vector<double> dvec1(ivec);
	//元素类型相同，可以使用范围初始化
	vector<double> dvec1(ivec.begin(), ivec.end());

	cout << dvec.capacity() << " " << dvec.size() << " " << dvec[0] << " " << dvec[dvec.size() - 1] << endl;
	cout << dvec1.capacity() << " " << dvec1.size() << " " << dvec1[0] << " " << dvec1[dvec1.size() - 1] << endl;

	vector<const char*>oldstyle;
	list<string> names(oldstyle.begin(),oldstyle.end());

	names.assign(oldstyle.begin(), oldstyle.end());
	
	//swap操作速度比拷贝快很多，其元素本身并未交换，只是数据结构的交换

	/* (除了无序关联容器外，所有容器都支持，容器类型与元素类型都要相同)关系运算符 == != > >= < <= */
	//向vector或者string添加元素可能引起整个对象存储空间的重新分配。重新分配一个对象的存储空间需要分配新的内存，并将元素从旧的空间移动到新的空间中

	/* insert操作在中间插入，有时会很耗时 emplace操作，直接调用构造函数生成一个新的*/
	//假设c保存的是Sales_data,需要在c的末尾构造一个sales_data
	//使用三个参数的Sales_data构造函数 可以根据构造函数的不同分别调用
	//c.emplace_back("978-05935334252", 25, 25.99);
	//错误没有接收三个参数的push_back()版本
	//c.push_back("978-05935334252", 25, 25.99);
	//正确：创建一个临时Sales_data变量给push_back
	//c.push_back(Sales_data("978-05935334252", 25, 25.99));

	/* 访问元素：迭代器，c.front(), c.back(), c[n], c.at(n)返回的是引用 c.data()返回的是第一个元素类型指针 */

	/* 删除元素c.pop_back(), c.pop_front, c.erase(), c.erase(b, e), c.clear() */

	/* 改变容器大小 */
	//c.resize()允许我们告诉容器需要准备多少的空间  c.capacity()会告诉我们在不扩张内存的情况下还能存储多少元素 c.shrink_to_fit()将capacity()减少到size()相同的空间

	/* 容器操作可能会使迭代器失效 */

	vector<char> vc = { 'h','e','l','l','o' };
	string s(vc.data(), vc.size());	//vc.data()返回char *
	cout << s << endl;

	/* string类型其他的赋值方式；append与replace */
	//append是在末尾进行添加
	//replace是erase与insert的集合

	/* string的搜索操作，如果成功返回string::size_type值，表示匹配发生位置的下标，如果搜索失败则返回string::npos的static成员 */
	//find(arg); rfind(arg)（arg内容）; find_first_of(arg)(arg中任一字符), find_last_of, find_first_not_of, fing_last_not_of
	//compare与strcmp差不多
	
	/* 数值转换 */
	//to_string; stoi; stol; stoul; stoll; stoull; stof; stod; stold;


	/* 除了标准容器之外，标准库还定义了三种容器适配器：stack、queue 和 priority_queue */
	/*
	* 适配器（adaptor）是标准库中的一个通用概念。容器，迭代器和函数都有适配器。
	* 本质上一个适配器接受一种已有的容器类型，使其行为看起来像一种不同的类型
	* 例如：stack适配器接收一个顺序容器（除array或forward_list），并使其操作看起来像stack一样 
	*/


	return 0;
}
