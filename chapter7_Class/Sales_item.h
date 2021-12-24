#ifndef SALES_ITEM_H_
#define SALES_ITEM_H_

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

//���������ڲ��ĺ���ʱ��ʽ��inline����

struct Sales_data
{
	friend istream& read(istream&, Sales_data& );
	friend ostream& print(ostream&, const Sales_data& );
	friend Sales_data add(const Sales_data&, Sales_data& );

public:
	//�����Ĺ��캯��
	Sales_data() = default;//Ҫ����������ɹ��캯������ȫ���ںϳɵ�Ĭ�Ϲ��캯���������ڲ���Ĭ������
	explicit Sales_data(const string& s = "") :bookNo(s) {}//���캯����ʼֵ�б�
	Sales_data(const string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {}
	explicit Sales_data(istream& is)/* { is >> *this; }*/;

	//ί�й��캯��
	Sales_data(unsigned n, unsigned p) :Sales_data("", n, p) {} 


	//����Sales_data����Ĳ���
	string isbn() const { return (*this).bookNo/* this->bookNo */; }
	Sales_data& combine(const Sales_data&);
	//������Ա������const member function���൱�ڽ�thisָ����ϳ���
	//���������Լ�������������û�ָ�붼ֻ�ܵ��ó�����Ա����

private:
	double avg_price() const;
		//{	return units_sold ? revenue / units_sold : 0;	}

	//Sales_data�ķǳ�Ա�ӿڲ���
	string bookNo;				//�鼮��ţ���ʽ��ʼ��Ϊ�մ�
	unsigned units_sold = 0;	//����������ʽ��ʼ��Ϊ0
	double revenue = 0;			//�����۶��ʽ��ʼ��Ϊ0
	double sellingprice = 0.0;	//ԭʼ�۸���ʽ��ʼ��Ϊ0
	double sellprice = 0.0;		//ʵ�ʼ۸���ʽ��ʼ��Ϊ0
	double discount = 0.0;		//�ۿۣ���ʽ��ʼ��Ϊ0
};

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

//Sales_data�ķǳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);











#endif // !SALES_ITEM_H_

