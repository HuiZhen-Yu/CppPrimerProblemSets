#ifndef SALES_ITEM_H_
#define SALES_ITEM_H_

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

//定义在类内部的函数时隐式的inline函数

struct Sales_data
{
	friend istream& read(istream&, Sales_data& );
	friend ostream& print(ostream&, const Sales_data& );
	friend Sales_data add(const Sales_data&, Sales_data& );

public:
	//新增的构造函数
	Sales_data() = default;//要求编译器生成构造函数，完全等于合成的默认构造函数，在类内部，默认内联
	explicit Sales_data(const string& s = "") :bookNo(s) {}//构造函数初始值列表
	Sales_data(const string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {}
	explicit Sales_data(istream& is)/* { is >> *this; }*/;

	//委托构造函数
	Sales_data(unsigned n, unsigned p) :Sales_data("", n, p) {} 


	//关于Sales_data对象的操作
	string isbn() const { return (*this).bookNo/* this->bookNo */; }
	Sales_data& combine(const Sales_data&);
	//常量成员函数（const member function）相当于将this指针加上常量
	//对象常量，以及常量对象的引用或指针都只能调用常量成员函数

private:
	double avg_price() const;
		//{	return units_sold ? revenue / units_sold : 0;	}

	//Sales_data的非成员接口操作
	string bookNo;				//书籍编号，隐式初始化为空串
	unsigned units_sold = 0;	//销售量，显式初始化为0
	double revenue = 0;			//总销售额，显式初始化为0
	double sellingprice = 0.0;	//原始价格，显式初始化为0
	double sellprice = 0.0;		//实际价格，显式初始化为0
	double discount = 0.0;		//折扣，显式初始化为0
};

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

//Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);











#endif // !SALES_ITEM_H_

