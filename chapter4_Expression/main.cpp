#include <iostream>
#include <string>

using namespace std;

int main()
{
	/* ��ֵ����ֵ */
	//������ʽ����ֵ�������ֵ��decltyoe�����ڸñ��ʽ�õ�һ���������͡�
	//����p��������int*����Ϊ������������ֵ������decltype(p)�Ľ����int&��
	//��һ���棬��Ϊȡ��ַ�����������ֵ������decltype(&p)�Ľ����int**��ָ������ָ���ָ��

	/* ���ȼ��涨������������Ϸ�ʽ������û��˵�����������ʲô˳����ֵ */
	//������������涨����ְ˳�� && || ?: ,
	//���������������������ֵ���������ֵ

	/* ��Ա��������� */
	string s1 = "a string", * p = &s1;
	auto n = s1.size();
	n = (*p).size();
	n = p->size();

	/* λ�������ǿ�ҽ������λ��������ڴ����޷������� */

	/* ��������� */

	/* ��ʾת�� static_cast��dynamic_cast��const_cast��reintepret_cast */
	//static_cast:���ڷǶ�̬����ת��(��̬ת��)���κα�׼ת�����������������ǲ���������������ص�����ת����
	int i = 0, j = 0;
	double slope = static_cast<double>(j) / i;
	double d = 0.23;
	i *= static_cast<int>(d);
	//const_cast:ֻ�ܸı��������ĵײ�const��ɾ������const�����ԣ����㸳ֵ
	//�����������һ�����������дȨ���ǺϷ�����Ϊ����������Ǹ������������δ������
	//һ��ֻ�����к������ص���������
	const char* cp = "adgfag";
	//char* q = static_cast<char*>(cp);//����static_cast����ת��const����
	string str = static_cast<string>(cp);
	//const_cast<string>(cp);//����const_castֻ�ܸı䳣������

	//reintepret_cast:��һ������ת��Ϊ��һ�ֲ�ͬ�����͡�ͨ��Ϊ��������λģʽ�ṩ�ϵͲ���ϵ����½���
	int* ip = &i;
	char* pc = reinterpret_cast<char*>(ip);

	return 0;
}

