#include "Macro.h"
#include "Sales_item.h"


int main()
{
	/* 1~16 */
	//int problem_num = PROB_16;
	//(*prob_arry[problem_num])();

	/* 20 */
	//Sales_item book;
	//std::cout << "���������ۼ�¼��" << std::endl;
	//while (std::cin >> book) 
	//{
	//	std::cout << "ISBN���۳����������۶��ƽ���ۼ�Ϊ " << book << std::endl;
	//}

	/* 21 */
	//Sales_item trans1, trans2;
	//std::cout << "����������ISBN��ͬ�����ۼ�¼��" << std::endl;
	//std::cin >> trans1 >> trans2;

	//if (compareIsbn(trans1, trans2))
	//	std::cout << "������Ϣ��ISBN���۳����顢���۶��ƽ���ۼ�Ϊ "
	//	<< trans1 + trans2 << std::endl;
	//else
	//	std::cout << "�������ۼ�¼��ISBN��ͬ" << std::endl;
	//return 0;

	/* 23 */
	Sales_item trans1, trans2;
	int num = 1;
	std::cout << "�������������ۼ�¼��"
		<< std::endl;
	if (std::cin >> trans1)	{
		while (std::cin >> trans2)
			if (compareIsbn(trans1, trans2))//ISBN��ͬ
				num++;
			else { //isbn ��ͬ
				std::cout << trans1.isbn() << "����" << num << "�����ۼ�¼" << std::endl;
				trans1 = trans2;
				num = 1;
			}
		std::cout << trans1.isbn() << "����" << num << "����������" << std::endl;
	}
	else
	{
		std::cout << "û������" << std::endl;
		return -1;
	}
	return 0;
}