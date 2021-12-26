#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

/* 
* 泛型算法
* 
* 顺序容器只定义了很少的操作，添加，删除，访问元素等，而用户希望做其他很多有用的操作：查找特定元素、替换或者删除一个特定值，重排元素顺序等
* 标准库并未给每个容器都定义成员函数来实现这些操作，而是定义了一组泛型算法（generic algorithm），实现了经典算法的公共接口
* 一般情况下，这些算法并不是直接操作容器，而是遍历由两个迭代器指定的一个元素范围来进行操作
* 迭代器令算法不依赖于容器，但是算法依赖于元素类型的操作
* 泛型算法本身不会执行容器的操作，指挥运行于迭代器之上，执行迭代器的操作。
* 算法永远不会改变底层容器的大小，算法可能改变容器中保存的元素，也可能在容器中移动元素，但是永远不会直接添加或者删除元素
*/

void elimDups(vector<string>& words)
{
	//按字典顺序排序words，以便查找重复单词
	sort(words.begin(), words.end());
	//unique重排输入范围，使得每个单词都出现一次
	//排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	//使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());
}

bool check_size(string& s, size_t sz)
{
	return s.size() < sz;
}

inline ostream& print(ostream& os, const string& s, char c)
{
	//io对象不能被拷贝，只能使用引用
	return os << s << c << endl;
}



void biggest(vector<string>& words, vector<string>::size_type sz, ostream& os = cout)
{
	elimDups(words);	//将words按照字典顺序排序并删除重复单词
	//按长度排序，长度相同的按照字典顺序排序
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size();});
	//获取一个迭代器，指向第一个满足size()>=sz的元素
	auto wc = find_if(words.begin(), words.end(), [sz](const string& a) {return a.size() >= sz;});
	//使用bind函数
	auto check_sz = bind(check_size, std::placeholders::_1, sz);
	auto wc_2 = find_if(words.begin(), words.end(), bind(check_size, std::placeholders::_1, sz));
	//计算满足size>=sz的元素的数目
	auto count = words.end() - wc;
	cout << count << " " << ((count > 1) ? "words":"word") << " of length " << sz << " or longer " << endl;

	//ref表示引用方式传值
	auto print_b = bind(print, ref(os), _1, ' ');
	//打印长度大于等于给定值的单词，每个单词后面借一个空格
	for_each(wc, words.end(), [&os](const string& s) {os << s << " ";});
	for_each(wc, words.end(), print_b);
	cout << endl;
	
}

void fcn2(size_t v2)
{
	size_t v1 = 42;

	auto f2 = [v2]() { return v2; };
	v1 = 0;
	auto j = f2();
	cout << j << endl;
}



auto fcn3(size_t v2)
{
	size_t v1 = 42;

	auto f2 = [v2]()mutable->size_t { return ++v2; };

	return f2;
}

int main()
{
	/* 只读算法 find count accumulate（求和）equal（确定两个序列是否保存相同的值） */
	//equal：利用迭代器完成，因此我们可以通过调用equal来比较两个不同类型的容器中的元素，而且元素类型也可以不一样 p399
	//fill：将给定值赋予元素 fill_n()
	//back_inserter():插入迭代器，向容器中添加元素的迭代器 auto it = back_inserter(vec)
	//copy(复制), replace(替换), replace_copy
	//sort(排序), unique(挑选出不重复元素)，erase（删除元素）

	/* 我们可以重载算法，以定制我们需要的行为 */
	//向算法传递函数，第三个参数，也被称为（谓词）
	//谓词（predicate）：是一个可用的表达式，iq返回结果是一个能用做条件的值。标准库算法所用的谓词分为两类一元谓词（unary predicate）和二元谓词（binary predicate）
	//sort(words.begin(), words.end(), isShorter)(排序); stable_sort()：保持相同长度的单词按字典序排列，可以使用stable_sort()算法。这种算法稳定排序算法维持相等元素的原有内容。
	//bool isShorter(const string &s1,const string &s2){ return s1.size() < s2.size() }
	//partition() :对容器内所有的元素进行划分
	//find(); find_if()
	//for_each算法
	//遍历所有内容，执行给定操作

	/* lambda表达式 */
	//我们可以向算法传递任何类别的可调用对象（callable object）。对于一个对象或者表达式，如果可以对其实用调用运算符，则称它为可调用的。
	//即，如果e是一个可调用的表达式，则我们可以编写代码e(args),其中args是一个逗号分隔的一个或者多个参数的列表。目前为止，我们接触过的可调用对象为函数或者函数指针
	//还有两种可调用对象：重载了函数调用运算符的类，和lambda表达式

	//lambda表达式表示一个可以调用的代码单元。我们可以将其理解为一个未命名的内联函数。lambda具有一个返回类型，一个参数列表和一个函数体
	//[capture list](parameter list)->return type{function body}
	auto f = [](const string& a, const string& b)->bool {return a.size() < b.size();};
	cout << f("sf", "asdgadbg") << endl;

	vector <string> testvs{ "a","abc","sdgfaegqaeg","asdgsdfq","s","a","seu","compass","fire","helloword","hello","erdfg" };
	biggest(testvs, 5);

	fcn2(2);

	cout << fcn3(2)() << endl;

	//当引用方式捕捉一个变量时，必须保证在lambda执行时变量时存在的，建议尽量保持lambda的变量捕获简单化
	//lambda的隐式捕获，当我们混合使用隐式捕获和显示捕获的时候，捕获列表中的第一个元素必须是一个&或者=。此符号制定了默认捕获方式为引用或者值。
	//对于那种只在一个地方使用的简单操作，lambda表达式是最有用的。如果我们需要在很多地方使用相同的操作，通常应该定义一个函数，而不是多次编写相同的lambda表达式

	/* 参数绑定 bind 头文件functional中 */
	//_n都定义在一个名为placeholders的命名空间中，而这个命名空间本身定义在std中
	//ref()函数
	//print_b("sfae");

	/* 再探迭代器 */
	//插入迭代器
	//iostream迭代器
#if 0
	istream_iterator<int> in_iter(cin);	//从cin中读取int
	istream_iterator<int> eof;			//istream尾后迭代器
	vector<int> vec(in_iter, eof);
	vector<int> vec_1;
	while (in_iter != eof)
		//后置递增运算符读取流，返回迭代器的旧值
		//解引用迭代器，获得从流读取的前一个值
		vec.push_back(*in_iter++);

	for (auto i : vec)
		cout << i << " ";
	//istream_iterator允许使用懒惰求值，即推迟到使用迭代器时才真正从流中读取数据

	//ostream_iteraor
	ostream_iterator<int> out_iter(cout, " ");
	for (auto e : vec)
		*out_iter++ = e;//可以写成out_iter = e,因为*和++不做任何事
	cout << endl;
	//这么些比循环更加简单
	copy(vec.begin(), vec.end(), out_iter);
	cout << endl;
#endif
	//使用流迭代器处理类型 我们可以为任何定义了输入运算符(<<)的类型创建istream_iterator对象，类似的只要有输出运算符(>>)，就可以为其定义ostream_iterator

	/* 反向迭代器 */
	//反向迭代器就是在容器中从尾元素向首元素反向移动的迭代器。对于反向迭代器递增操作的含义会反过来
	//sort(vec.begin(), vec.end());	按照正常顺序排序vec
	//sort(vec.rbegin(), vec.rend()); 按照逆序排序，最小元素放在vec的末尾

	string line("FIRST, MIDDLE, LAST");
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	cout << string(line.crbegin(), rcomma) << endl;		//TSAL

	cout << string(rcomma.base(), line.cend()) << endl;		//TSAL

	/* 泛型算法结构 */
	//算法要求的迭代器操作可以分为五个迭代器类别（iterator category）
	/* 
	* 输入迭代器			只读，不写；单遍扫描，只能递增
	* 输出迭代器			只写，不读；单遍扫描，只能递增
	* 前向迭代器			可读写；多遍扫描，只能递增
	* 双向迭代器			可读写；多遍扫描，可递增递减
	* 随机访问迭代器		可读写，多遍扫描，支持全部迭代器运算
	*/

	/* 算法形参模式 */
	//在任何其他的算法之上还有一组参数规范。

	/* 算法命名规范 */

	/* 特定容器的算法 */
	//list 与 forword_list

	return 0;
}