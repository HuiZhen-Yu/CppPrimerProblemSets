#include <iostream>
#include <string>
#include <vector>
#include "Sales_item.h"

using namespace std;

int main()
{
	/* 1.switch�ڲ��ı������� */
	//bool a = false;
	//switch (a)
	//{
	//case true:
	//	//��Ϊ�����ִ�����̿����ƿ�����ĳ�ʼ����䣬���Ը�switch��䲻�Ϸ�
	//	//string file_name = "name";	//���󣺿������ƹ�һ����ʽ��ʼ���ı���
	//	//string ival = 0;	//���󣺿������ƹ�һ����ʾ��ʼ���ı���
	//	int jval;			//��ȷ����Ϊjvalû�г�ʼ��
	//	break;
	//case false:
	//	//��ȷ��jval��Ȼ���������ڣ�������û�б���ʼ��
	//	jval = 9;
	//	break;
	//
	//}
	//
	//switch (a)
	//{
	//case true:
	//{
	//	string file_name = "name";	//��ȷ
	//	string ival = 0;	//��ȷ
	//	int jval;			//��ȷ
	//	break;
	//}
	//case false:
	//	//����jval����������
	//	//jval = 9;
	//	break;
	//
	//}

	/* 2.whileѭ�� */
	//����ȷ��ѭ���Ĵ�����������ѭ�����������ѭ�����Ʊ���
	//vector<int> v;
	//int i;
	////�ظ���������ֱ���ļ�ĩβ��������
	//while (cin >> i)
	//	v.push_back(i);
	////Ѱ�ҵ�һ����ֵԪ��
	//auto beg = v.begin();
	////decltype(v.begin()) beg = v.begin();
	//while (beg != v.end() && *beg >= 0)
	//	++beg;
	//if (beg == v.end())
	//	cout << "�������ݶ�����0" << endl;

	///* 3.for��� */
	////for�е�init_statementֻ����һ��������䣬���б����Ļ������ͱ�����ͬ�����Զ���������
	//for (int i = 0, double j = 0;i < 30;i++)
	//{

	//}

	//��Χfor���

	/* 4.do while��� ��������ѭ�������ڶ������ */

	/* 5.try������쳣���� */
	//throw���ʽ��throw expression�����쳣��ⲿ��ʹ����throw���ʽ����ʾ���������޷���������⡣����˵throw������rise�����쳣��
	//try���飨try blok����try�����Թؼ���try��ʼ������һ�����߶��catch�Ӿ䣨catch clause��������
	//try�����д����׳����쳣ͨ���ᱻĳ��catch�Ӿ䴦����Ϊcatch�Ӿ䴦���쳣����������Ҳ����Ϊ�쳣����ģ�飻
	//һ���쳣�ࣨexpression class����������throw���ʽ����ص�catch�־�֮�䴫���쳣�ľ�����Ϣ��
	
	//Sales_item item1, item2;
	//cin >> item1 >> item2;
	//���ȼ��item1��item2�Ƿ��ʾͬһ���鼮
	//if (item1.isbn() == item2.isbn())
	//{
	//	cout << item1 + item2 << endl;
	//}
	//else {
	//	cerr << "Data must refer to same ISBN" << endl;
	//	return -1;// ��ʾʧ��
	//}

	Sales_item item1, item2;
	cin >> item1 >> item2;
	try
	{
		if (item1.isbn() != item2.isbn())
			throw runtime_error("Data must refer to same ISBN");
		cout << item1 + item2 << endl;
	}
	catch (runtime_error err)
	{
		cerr << err.what() << endl;
	}

	/* ��׼�쳣 */
	//exceptionͷ�ļ���������ͨ�õ��쳣��exception����ֻ�����쳣�ķ��������ṩ�κζ�����Ϣ��
	//stdexceptͷ�ļ������˼��ֳ��õ��쳣��








	return 0;
}