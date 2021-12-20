#include "Macro.h"


int problem_3(void)
{
	std::cout << "Hello" << std::endl;
	return 0;
}

int problem_4(void)
{
	std::cout << "请输入两个数" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	std::cout << v1 << "和" << v2 << "的积为" << v1 * v2 << std::endl;
	return 0;
}

int problem_9(void)
{
	int sum = 0;
	int i = 50;
	while (i <= 100)
	{
		sum += i;
		i++;
	}
	std::cout << "50到100之间的整数和为：" << sum << std::endl;
	return 0;
}

int problem_16(void)
{
	/* 不定次数循环，以及输入流结束判断 */
	int sum = 0, value = 0;
	std::cout << "请输入一些数，按control z表示结束" << std::endl;
	for (;std::cin >> value;)
	{
		sum += value;
	}
	std::cout << "读入的数之和为" << sum << std::endl;
	
	return 0;
}

prob_func prob_arry[] =
{
	problem_3,
	problem_4,
	problem_9,
	problem_16,
};
