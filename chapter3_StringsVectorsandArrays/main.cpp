#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#include <iterator>

using namespace std;

int main()
{
	/* 1.����ͳ�ʼ��string�ķ�ʽ */

	/* 2.string�Ĳ��� string::size_type()���� */

	/* 3.�ַ�����ϰ */
	//string s, result;
	//cout << "������һ���ַ�����" << endl;
	//while (cin >> s)
	//{
	//	result  = result + ' ' + s;
	//}
	//cout << "ƴ��֮����ַ����ǣ�" << result << endl;

	/* 4.range for */
	//string str("some string");
	//cout << "ԭ�����ַ����ǣ�" << str << endl;
	//for (auto &c : str)
	//{
	//	if (c == 's')
	//		c = toupper(c);
	//}
	//cout << "�޸ĺ���ַ����ǣ�" << str << endl;

	/* 5.��׼������ vector */
	//int word = 0;
	//vector <int> num;
	//while (cin >> word)
	//{
	//	num.push_back(word);
	//}

	//for (auto &a : num)
	//{
	//	a *= a;
	//	cout << a << ' ';
	//}
	//cout << endl;
	/* vector���������±����Ԫ�أ����ǿ���ͨ���±�����Ԫ�� vector<int>::size_type */

	//string word;
	//vector<string> phy;
	//while (cin >> word)
	//{
	//	phy.push_back(word);
	//}

	//for (auto& a : phy)
	//{
	//	a[0] = towupper(a[0]);
	//	cout << a << ' ';
	//}
	//cout << endl;
	//cout << phy.size() << endl;
	/* ȷ���±���Ч��һ����Ч�ֶ���ʹ�÷�Χfor��� */

	//vector <int> vInt;
	//int iVal = 0;
	//cout << "������һ������" << endl;
	//while (cin >> iVal)
	//	vInt.push_back(iVal);
	//if (vInt.size() == 0)
	//{
	//	cerr << "û���κ�Ԫ�أ�����" << endl;
	//	return 0;
	//}
	//cout << "��������ĺ��ǣ�" << endl;
	////����decltype�ƶ�i������
	//for (decltype(vInt.size()) i = 0;i < vInt.size() - 1;i += 2)
	//{
	//	//����������ĺ�
	//	cout << vInt[i] + vInt[i + 1] << " ";
	//	//ÿ������������
	//	if ((i + 2) % 10 == 0)
	//	{
	//		cout << endl;
	//	}
	//}
	////���Ԫ���������������������һ��Ԫ��
	//if (vInt.size() % 2 != 0)
	//	cout << vInt[vInt.size() - 1];
	//return 0;

	/* 6.���������� */
	//���еı�׼���������е����� �����������
	//string s("some string!!");
	//for (auto it = s.begin();it != s.end() && !isspace(*it);*it++)
	//	*it = toupper(*it);		//������
	//
	//cout << s << endl;
	//cbegin()��cend(),����vector����string�����ǲ���const��������Զ��const_iterator
	//����ʹ���˵�������ѭ���壬����Ҫ������������������������Ԫ��
	//
	//vector<string> text;
	//string s;
	////����getline��ȡһ�λ���ֱ�ӻس�����һ���ַ�������ʾ�������
	//while (getline(cin, s))
	//	text.push_back(s);
	////���õ���������ȫ�����ַ������������ַ���ֹͣ
	//for (auto it = text.begin();it != text.end() && !it->empty();it++)
	//{
	//	//���õ�����������ǰ�ַ���
	//	for (auto it2 = (*it).begin();it2 != it->end();it2++)
	//	{
	//		*it2 = toupper(*it2);
	//	}
	//	cout << *it << endl;
	//}

	//auto mid = text.begin() + text.size() / 2;
	//auto mid_2 = text.begin() + (text.end() - text.begin()) / 2;
	////vector<string>::difference_type ֻ�������������������ʱ��ʹ��

	/* 7.������� */
	//int arr[10];
	//int(&arrRef)[10] = arr;
	////�����±�ͨ����size_t���ͣ���cstddefͷ�ļ���
	//unsigned scores[11] = {};
	//for (auto i : scores){
	//	cout << i << endl;
	//}

	//int ia[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//auto ia2(ia);	//ia2��һ������ָ�룬ָ��ia�ĵ�һ��Ԫ��
	//decltype(ia) ia3 = { 0,1,2,3,4,2,3,2,3 };
	//ia2 = ia3;

	//ָ��Ҳ�ǵ����������Խ�������Ԫ�صĻ�ȡ
	//�⺯��begin��end
	//int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	//int* beg = begin(ia);	//ָ��ia��Ԫ�ص�ָ��
	//int* last = end(ia);	//ָ��iaβԪ�ص�ָ��
	//ptrdiff_t num = end(ia) - begin(ia);

	//��׼��ʹ���±�������޷������ͣ������õĲ�û�����Ҫ��
	//��ɴ���Ľӿ�
	string s;
	const char* str = s.c_str();

	//ʹ�������ʼ��vector����
	int int_arr[] = {0,1,2,3,4,5,6,7};
	//ivec������Ԫ�أ��ֱ���int_arr�ĸ���
	vector<int> ivec(begin(int_arr), end(int_arr));
	//��������Ԫ�أ�[1] [2] [3]
	vector<int>sub_ivec(int_arr[1], int_arr[4]);

	//��ά����...  ʹ��rangefor��䴦���ά����
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];
	size_t cnt = 0;
	for (decltype(ia[0]) row : ia)
		for (auto& col : row) {
			col = cnt;
			++cnt;
			cout << col << " ";
		}
	cout << endl;

	/* ʹ�����ͱ������򻯶�ά�����ָ�� */
	using int_array = int(*)[4];
	//typedef int (*int_array)[4];

	for (int_array p = ia;p != ia + 3;++p) {
		for (int* q = *p;q != *p + 4;++q)
			cout << *q << ' ';
		cout << endl;
	}



	return 0;
}
