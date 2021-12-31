#include "Sale_item.h"

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

double print_total(ostream& os, const Quote& item, size_t n)
{
	//���ݴ����item�βεĶ������͵���Quote::net_price
	//����Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()	//����Quote::isbn
		<< " # sold: " << n << "total due: " << ret << endl;
	return ret;
}

double Basket::total_receipt(ostream& os) const
{
	double sum = 0.0;			//����ʵʱ������ļ۸�
	//iterָ��ISBN��ͬ��һ��Ԫ���еĵ�һ��
	//upper_bound����һ�����������õ�����ָ������Ԫ�ص�β��λ��
	for (auto iter = items.cbegin(); iter != items.cend();iter = items.upper_bound(*iter))
	{
		//����ֱ���ڵ�ǰ��Baske��������һ���ùؼ��ֵ�Ԫ��
		//��ӡ���鼮��Ӧ����Ŀ
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;		//��ӡ���յ��ܼ۸�
	return sum;
}















