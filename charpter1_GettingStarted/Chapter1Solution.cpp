#include "Macro.h"


int problem_3(void)
{
	std::cout << "Hello" << std::endl;
	return 0;
}

int problem_4(void)
{
	std::cout << "������������" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	std::cout << v1 << "��" << v2 << "�Ļ�Ϊ" << v1 * v2 << std::endl;
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
	std::cout << "50��100֮���������Ϊ��" << sum << std::endl;
	return 0;
}

int problem_16(void)
{
	/* ��������ѭ�����Լ������������ж� */
	int sum = 0, value = 0;
	std::cout << "������һЩ������control z��ʾ����" << std::endl;
	for (;std::cin >> value;)
	{
		sum += value;
	}
	std::cout << "�������֮��Ϊ" << sum << std::endl;
	
	return 0;
}

prob_func prob_arry[] =
{
	problem_3,
	problem_4,
	problem_9,
	problem_16,
};
