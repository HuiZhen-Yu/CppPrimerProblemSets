#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool HasUpper(const string& str)
{
	for (auto c : str)
		if (isupper(c))
			return true;
	return false;
}

void ChangeToLower(string& str)
{
	for (auto& c : str)
		c = tolower(c);
}

/* ��������һ���Ķ���β� */
void error_msg1(initializer_list<string> il)
{
	for (auto beg = il.begin();beg != il.end();beg++)
		cout << *beg;
	cout << endl;
}

/* �ݹ���� */
void print_vector(vector<int> vInt, unsigned index)
{
	auto sz = vInt.size();
	if (!vInt.empty() && index < sz)
	{
		cout << vInt[index] << endl;
		print_vector(vInt, index + 1);
	}
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int doub(int a, int b)
{
	return a * a + b * b;
}

decltype(add) *func_p = add;

int main(int argc,char **argv)
{
	/* const�βκ�ʵ�� */
	//����const�����ڱ�������������Ϊ�βε�ʱ�򶥲��const�ᱻ���Ե�

	//�����ڴ�ֵ��ʱ����ʹ�ó�������
	//string str = "ajfoajiHALSJDF";
	//string const str1 = "sagseg";
	//
	//if (HasUpper(str))
	//{
	//	cout << str << " str�д�д��ĸ" << endl;
	//	ChangeToLower(str);
	//	cout << str << " strת��֮��" << endl;
	//}
	//else
	//{
	//	cout << str << "û�д�д��ĸ" << endl;
	//}

	//bool compare(const Matrix&,const Martix&);
	//vector<int>::iterator change_val(int, vector<int>::iterator);

	/* main:����������ѡ�� */
	//string str;
	//cout << argc << endl;
	//for (int i = 0;i != argc;i++)
	//{
	//	str += argv[i];
	//	cout << argv[i] << endl;
	//}
	//cout << str << endl;

	/* ���пɱ��βεĺ��� */
	//������е��β�������ͬ�����Դ�����Ϊinitializer_list�ı�׼������
	//��vector��һ�����ǣ�initializer_list�е�ֵ��Զ�ǳ�ֵ������֮���vector���÷���ࣩ

	string a = "Hello World!!\r\n";
	string b = "Hello Compass!!\r\n";
	string c = "Hello SEU!!\r\n";
	initializer_list<string> lst{ a,b,c };
	error_msg1(lst);
	error_msg1({ "Hello World!!\r\n","Hello Compass!!\r\n","Hello SEU!!\r\n" });

	/* ����һ���������õĺ����õ�����һ����ֵ���������������ֵ */

	/* �����ĵݹ飨ֱ�ӵݹ�ͼ��ݹ飩������Ҫȷ���ݹ���ɺ͵ݹ���ֹ������ */

	/* β�÷������� */

	/* �������� �ڲ�ͬ�����������޷����غ����� */
	/* Ĭ��ʵ�Σ�ĳ��ʵ�α�������Ĭ��ֵ��������������βζ����븳��Ĭ��ֵ�����õ�ʱ��ֻ��ʡ��β��ʵ�� */

	/* ����������constexpr */
	//constexpr�����ķ������ͼ����е��βζ���������ֵ���ͣ����Һ�������ֻ����һ��return���Һ�������ʽ��ָ��λ��������
	//����������constexpr����ͨ��������ͷ�ļ���

	/* ����ָ�� */
	int (*func5)(int, int);
	vector<decltype(func5)>func_vec = { add,sub,mul,doub };
	//func_vec.push_back(add);
	//func_vec.push_back(sub);
	//func_vec.push_back(mul);
	//func_vec.push_back(doub);

	for (auto funct : func_vec)
	{
		cout << (*(*funct))(2, 3) << endl;
	}

	cout << func_p(2, 3) << endl;
	cout << (*func_p)(2, 3) << endl;
	cout << (*(*func_p))(2, 3) << endl;
	return 0;
}


/* β�ò������� */
//��ͳ����
int(*func(int arr[][3], int n))[3]{
	return &arr[n];
}
//ʹ��β�����ͺ�
auto func1(int arr[][3], int n) -> int(*)[3]
{
	return &arr[n];
}

/* decltype��ʹ�� */
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
//����һ��ָ��
decltype(odd)* arrPtr(int i)
{
	return (i % 2) ? &odd : &even;//����һ��ָ�������ָ��
}

string (&func())[10];

//ʹ�����ͱ���
typedef string (&arr)[10];
arr func3();

//ʹ��β�÷�������
auto func4()->string(&)[10];

//ʹ��decltype()�ؼ���
string str4[10];
decltype(str4)& func5();