#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <set>

using std::string;
using std::size_t;
using std::ostream;
using std::shared_ptr;
using std::multiset;
using std::endl;

//定义基类
class Quote 
{
public:
	Quote() = default;			//关于=default
	Quote(const string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; };		//返回书籍的isbn号
	//给定数量的书籍的销售总额
	//派生类负责改写并使用不同的折扣计算算法
	virtual double net_price(size_t n) const	//返回书籍的实际销售价格
	{	return n * price;	}
	//该函数返回当前对象的一份动态分配的拷贝
	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone() const&& { return new Quote(std::move(*this)); }
	virtual ~Quote() = default;					//对析构函数进行动态绑定
private:
	string bookNo;			//数据的ISBN账号
protected:
	double price = 0.0;		//代表普通状态下不打折的价格

};

#if 0
//定义派生类
class Bulk_quote : public Quote		//Bulk_quote继承了Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {}
	//覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(size_t)const override;

private:
	size_t min_qty = 0;			//使用折扣政策的最低购买数量
	double discount = 0.0;		//以小数表示的折扣额
};

#endif

//用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
//有纯虚函数，是抽象基类，不能定义对象
class Disc_quote : public Quote 
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t) const = 0;

protected:
	size_t quantity = 0;		//折扣适用的购买数量
	double discount = 0.0;		//表示折扣的小数值

};

//定义派生类
class Bulk_quote : public Disc_quote		//Bulk_quote继承了Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {}
	Bulk_quote* clone() const& { return new Bulk_quote(*this); }
	Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }
	//覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(size_t)const override;
};


//定义Basket类
class Basket 
{
public:
	//basket使用合成的默认构造函数和拷贝控制成员
	//void add_item(const shared_ptr<Quote>& sale)
	//{
	//	items.insert(sale);
	//}

	void add_item(const Quote& sale)	//拷贝给定对象
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)			//移动给定对象
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	//打印每本书的总价和购物篮中所有书的总价
	double total_receipt(ostream&) const;

private:
	//该函数慧用于比较shared_ptr，multiset成员会用到它
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	//multiset保存多个报价，按照compare成员排序
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};


double print_total(ostream& os, const Quote& item, size_t n);

