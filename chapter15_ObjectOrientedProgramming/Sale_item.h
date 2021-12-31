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

//�������
class Quote 
{
public:
	Quote() = default;			//����=default
	Quote(const string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; };		//�����鼮��isbn��
	//�����������鼮�������ܶ�
	//�����ฺ���д��ʹ�ò�ͬ���ۿۼ����㷨
	virtual double net_price(size_t n) const	//�����鼮��ʵ�����ۼ۸�
	{	return n * price;	}
	//�ú������ص�ǰ�����һ�ݶ�̬����Ŀ���
	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone() const&& { return new Quote(std::move(*this)); }
	virtual ~Quote() = default;					//�������������ж�̬��
private:
	string bookNo;			//���ݵ�ISBN�˺�
protected:
	double price = 0.0;		//������ͨ״̬�²����۵ļ۸�

};

#if 0
//����������
class Bulk_quote : public Quote		//Bulk_quote�̳���Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {}
	//���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
	double net_price(size_t)const override;

private:
	size_t min_qty = 0;			//ʹ���ۿ����ߵ���͹�������
	double discount = 0.0;		//��С����ʾ���ۿ۶�
};

#endif

//���ڱ����ۿ�ֵ�͹��������࣬������ʹ����Щ���ݿ���ʵ�ֲ�ͬ�ļ۸����
//�д��麯�����ǳ�����࣬���ܶ������
class Disc_quote : public Quote 
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t) const = 0;

protected:
	size_t quantity = 0;		//�ۿ����õĹ�������
	double discount = 0.0;		//��ʾ�ۿ۵�С��ֵ

};

//����������
class Bulk_quote : public Disc_quote		//Bulk_quote�̳���Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {}
	Bulk_quote* clone() const& { return new Bulk_quote(*this); }
	Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }
	//���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
	double net_price(size_t)const override;
};


//����Basket��
class Basket 
{
public:
	//basketʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
	//void add_item(const shared_ptr<Quote>& sale)
	//{
	//	items.insert(sale);
	//}

	void add_item(const Quote& sale)	//������������
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)			//�ƶ���������
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	//��ӡÿ������ܼۺ͹���������������ܼ�
	double total_receipt(ostream&) const;

private:
	//�ú��������ڱȽ�shared_ptr��multiset��Ա���õ���
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	//multiset���������ۣ�����compare��Ա����
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};


double print_total(ostream& os, const Quote& item, size_t n);

