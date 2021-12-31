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
	//根据传入的item形参的对象类型调用Quote::net_price
	//或者Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()	//调用Quote::isbn
		<< " # sold: " << n << "total due: " << ret << endl;
	return ret;
}

double Basket::total_receipt(ostream& os) const
{
	double sum = 0.0;			//保存实时计算出的价格
	//iter指向ISBN相同的一批元素中的第一个
	//upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	for (auto iter = items.cbegin(); iter != items.cend();iter = items.upper_bound(*iter))
	{
		//我们直到在当前的Baske中至少有一个该关键字的元素
		//打印该书籍对应的项目
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;		//打印最终的总价格
	return sum;
}















