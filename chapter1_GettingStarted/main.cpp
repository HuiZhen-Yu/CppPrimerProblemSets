#include "Macro.h"
#include "Sales_item.h"


int main()
{
	/* 1~16 */
	//int problem_num = PROB_16;
	//(*prob_arry[problem_num])();

	/* 20 */
	//Sales_item book;
	//std::cout << "请输入销售记录：" << std::endl;
	//while (std::cin >> book) 
	//{
	//	std::cout << "ISBN、售出本数、销售额和平均售价为 " << book << std::endl;
	//}

	/* 21 */
	//Sales_item trans1, trans2;
	//std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
	//std::cin >> trans1 >> trans2;

	//if (compareIsbn(trans1, trans2))
	//	std::cout << "汇总信息：ISBN、售出本书、销售额和平均售价为 "
	//	<< trans1 + trans2 << std::endl;
	//else
	//	std::cout << "两条销售记录的ISBN不同" << std::endl;
	//return 0;

	/* 23 */
	Sales_item trans1, trans2;
	int num = 1;
	std::cout << "请输入若干销售记录："
		<< std::endl;
	if (std::cin >> trans1)	{
		while (std::cin >> trans2)
			if (compareIsbn(trans1, trans2))//ISBN相同
				num++;
			else { //isbn 不同
				std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;
				trans1 = trans2;
				num = 1;
			}
		std::cout << trans1.isbn() << "共有" << num << "条销售数据" << std::endl;
	}
	else
	{
		std::cout << "没有数据" << std::endl;
		return -1;
	}
	return 0;
}