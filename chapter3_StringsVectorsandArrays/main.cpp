#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#include <iterator>

using namespace std;

int main()
{
	/* 1.定义和初始化string的方式 */

	/* 2.string的操作 string::size_type()类型 */

	/* 3.字符串练习 */
	//string s, result;
	//cout << "请输入一个字符串：" << endl;
	//while (cin >> s)
	//{
	//	result  = result + ' ' + s;
	//}
	//cout << "拼接之后的字符串是：" << result << endl;

	/* 4.range for */
	//string str("some string");
	//cout << "原来的字符串是：" << str << endl;
	//for (auto &c : str)
	//{
	//	if (c == 's')
	//		c = toupper(c);
	//}
	//cout << "修改后的字符串是：" << str << endl;

	/* 5.标准库类型 vector */
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
	/* vector不可以用下标添加元素，但是可以通过下标索引元素 vector<int>::size_type */

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
	/* 确保下标有效的一种有效手段是使用范围for语句 */

	//vector <int> vInt;
	//int iVal = 0;
	//cout << "请输入一组数字" << endl;
	//while (cin >> iVal)
	//	vInt.push_back(iVal);
	//if (vInt.size() == 0)
	//{
	//	cerr << "没有任何元素！！！" << endl;
	//	return 0;
	//}
	//cout << "相邻两项的和是：" << endl;
	////利用decltype推断i的类型
	//for (decltype(vInt.size()) i = 0;i < vInt.size() - 1;i += 2)
	//{
	//	//求相邻两项的和
	//	cout << vInt[i] + vInt[i + 1] << " ";
	//	//每行输出五个数字
	//	if ((i + 2) % 10 == 0)
	//	{
	//		cout << endl;
	//	}
	//}
	////如果元素是奇数，单独处理最后一个元素
	//if (vInt.size() % 2 != 0)
	//	cout << vInt[vInt.size() - 1];
	//return 0;

	/* 6.迭代器介绍 */
	//所有的标准库容器都有迭代器 迭代器运算符
	//string s("some string!!");
	//for (auto it = s.begin();it != s.end() && !isspace(*it);*it++)
	//	*it = toupper(*it);		//解引用
	//
	//cout << s << endl;
	//cbegin()和cend(),不管vector或者string对象是不是const，返回永远是const_iterator
	//但凡使用了迭代器的循环体，都不要向迭代器所属的容器里面添加元素
	//
	//vector<string> text;
	//string s;
	////利用getline读取一段话，直接回车产生一个字符串，表示段落结束
	//while (getline(cin, s))
	//	text.push_back(s);
	////利用迭代器便利全部的字符串，遇到空字符串停止
	//for (auto it = text.begin();it != text.end() && !it->empty();it++)
	//{
	//	//利用迭代器遍历当前字符串
	//	for (auto it2 = (*it).begin();it2 != it->end();it2++)
	//	{
	//		*it2 = toupper(*it2);
	//	}
	//	cout << *it << endl;
	//}

	//auto mid = text.begin() + text.size() / 2;
	//auto mid_2 = text.begin() + (text.end() - text.begin()) / 2;
	////vector<string>::difference_type 只能在两个迭代器相减的时候使用

	/* 7.数组介绍 */
	//int arr[10];
	//int(&arrRef)[10] = arr;
	////数组下标通常是size_t类型，在cstddef头文件中
	//unsigned scores[11] = {};
	//for (auto i : scores){
	//	cout << i << endl;
	//}

	//int ia[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//auto ia2(ia);	//ia2是一个整型指针，指向ia的第一个元素
	//decltype(ia) ia3 = { 0,1,2,3,4,2,3,2,3 };
	//ia2 = ia3;

	//指针也是迭代器，可以进行数组元素的获取
	//库函数begin和end
	//int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	//int* beg = begin(ia);	//指向ia首元素的指针
	//int* last = end(ia);	//指向ia尾元素的指针
	//ptrdiff_t num = end(ia) - begin(ia);

	//标准库使用下标必须是无符号类型，而内置的并没有这个要求
	//与旧代码的接口
	string s;
	const char* str = s.c_str();

	//使用数组初始化vector对象
	int int_arr[] = {0,1,2,3,4,5,6,7};
	//ivec有六个元素，分别是int_arr的副本
	vector<int> ivec(begin(int_arr), end(int_arr));
	//拷贝三个元素：[1] [2] [3]
	vector<int>sub_ivec(int_arr[1], int_arr[4]);

	//多维数组...  使用rangefor语句处理多维数组
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

	/* 使用类型别名，简化多维数组的指针 */
	using int_array = int(*)[4];
	//typedef int (*int_array)[4];

	for (int_array p = ia;p != ia + 3;++p) {
		for (int* q = *p;q != *p + 4;++q)
			cout << *q << ' ';
		cout << endl;
	}



	return 0;
}
