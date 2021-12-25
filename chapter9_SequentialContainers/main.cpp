#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <array>

using namespace std;

//bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
//{
//	for (;beg != end;beg++)
//		if (*beg == val)
//			return true;
//	return false;
//}

//vector<int>::value_type a;
//vector<int>::reference b;
//vector<int>::const_reference b;

vector<int>::iterator search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
	for (;beg != end;beg++)
		if (*beg == val)
			return beg;
	return end;
}

int main()
{
	/* ˳���������� vector deque list forward_list string */
	//vector	�ɱ��С���顣֧�ֿ���������ʣ���β��֮���λ�ò������ɾ��Ԫ�ؿ��ܺ���
	//deque		˫�˶��У�֧�ֿ���������ʡ���ͷβλ�ò���/ɾ���ٶȺܿ�
	//list		˫������֧��˫��˳����ʡ���list���κ�λ�ý��в���/ɾ�����ܿ�
	//forward_list ��������֧�ֵ���˳����ʡ��������κ�λ�ý��в���/ɾ�������ٶȶ��ܿ�
	//array		�̶���С���顣֧�ֿ���������ʡ�������ӻ���ɾ��Ԫ��
	//string	��vector���Ƶ�����������ר�����ڱ����ַ���������ʿ졣��β������ɾ���ٶȺܿ�

	//list<deque<int>> a;

	//������Ҫд����ʱ��ʹ��cbegin��cend

	//ֻ��˳�������Ĺ��캯���Ž��ܴ�С������������������֧��

	//��׼��array���й̶���С
	array<int, 42> arr_1;
	//��list<int>��ʼ��vector<double>
	list<int> ilist = { 1,2,3,4,5,6,7 };
	vector<int> ivec = { 7,6,5,4,3,2,1 };
	//�������Ͳ�ͬ����ʹ�ÿ�����ʼ��
	//vec<double> ivec(ilist);
	//Ԫ��������ͬ������ʹ�÷�Χ��ʼ��
	vector<double> dvec(ilist.begin(), ilist.end());

	//�������Ͳ�ͬ������ʹ�ÿ�����ʼ��
	//vector<double> dvec1(ivec);
	//Ԫ��������ͬ������ʹ�÷�Χ��ʼ��
	vector<double> dvec1(ivec.begin(), ivec.end());

	cout << dvec.capacity() << " " << dvec.size() << " " << dvec[0] << " " << dvec[dvec.size() - 1] << endl;
	cout << dvec1.capacity() << " " << dvec1.size() << " " << dvec1[0] << " " << dvec1[dvec1.size() - 1] << endl;

	vector<const char*>oldstyle;
	list<string> names(oldstyle.begin(),oldstyle.end());

	names.assign(oldstyle.begin(), oldstyle.end());
	
	//swap�����ٶȱȿ�����ܶ࣬��Ԫ�ر���δ������ֻ�����ݽṹ�Ľ���

	/* (����������������⣬����������֧�֣�����������Ԫ�����Ͷ�Ҫ��ͬ)��ϵ����� == != > >= < <= */
	//��vector����string���Ԫ�ؿ���������������洢�ռ�����·��䡣���·���һ������Ĵ洢�ռ���Ҫ�����µ��ڴ棬����Ԫ�شӾɵĿռ��ƶ����µĿռ���

	/* insert�������м���룬��ʱ��ܺ�ʱ emplace������ֱ�ӵ��ù��캯������һ���µ�*/
	//����c�������Sales_data,��Ҫ��c��ĩβ����һ��sales_data
	//ʹ������������Sales_data���캯�� ���Ը��ݹ��캯���Ĳ�ͬ�ֱ����
	//c.emplace_back("978-05935334252", 25, 25.99);
	//����û�н�������������push_back()�汾
	//c.push_back("978-05935334252", 25, 25.99);
	//��ȷ������һ����ʱSales_data������push_back
	//c.push_back(Sales_data("978-05935334252", 25, 25.99));

	/* ����Ԫ�أ���������c.front(), c.back(), c[n], c.at(n)���ص������� c.data()���ص��ǵ�һ��Ԫ������ָ�� */

	/* ɾ��Ԫ��c.pop_back(), c.pop_front, c.erase(), c.erase(b, e), c.clear() */

	/* �ı�������С */
	//c.resize()�������Ǹ���������Ҫ׼�����ٵĿռ�  c.capacity()����������ڲ������ڴ������»��ܴ洢����Ԫ�� c.shrink_to_fit()��capacity()���ٵ�size()��ͬ�Ŀռ�

	/* �����������ܻ�ʹ������ʧЧ */

	vector<char> vc = { 'h','e','l','l','o' };
	string s(vc.data(), vc.size());	//vc.data()����char *
	cout << s << endl;

	/* string���������ĸ�ֵ��ʽ��append��replace */
	//append����ĩβ�������
	//replace��erase��insert�ļ���

	/* string����������������ɹ�����string::size_typeֵ����ʾƥ�䷢��λ�õ��±꣬�������ʧ���򷵻�string::npos��static��Ա */
	//find(arg); rfind(arg)��arg���ݣ�; find_first_of(arg)(arg����һ�ַ�), find_last_of, find_first_not_of, fing_last_not_of
	//compare��strcmp���
	
	/* ��ֵת�� */
	//to_string; stoi; stol; stoul; stoll; stoull; stof; stod; stold;


	/* ���˱�׼����֮�⣬��׼�⻹����������������������stack��queue �� priority_queue */
	/*
	* ��������adaptor���Ǳ�׼���е�һ��ͨ�ø���������������ͺ���������������
	* ������һ������������һ�����е��������ͣ�ʹ����Ϊ��������һ�ֲ�ͬ������
	* ���磺stack����������һ��˳����������array��forward_list������ʹ�������������stackһ�� 
	*/


	return 0;
}
