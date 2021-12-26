#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <utility>	//pair类型
#include <map>
#include <set>


using namespace std;

void add_family(map<string, vector<string>>& families, const string& family)
{
	if (families.find(family) != families.end())
		families[family] = vector<string>{};
	/* 还有一个非常简单的形式 */
	//families[family];//若已有，不会有任何操作，若没有，会进行一次默认初始化
}

void add_child(map<string, vector<string>>& families, const string& famliy, const string& child)
{
	families[famliy].push_back(child);
}

/* 关联容器 */
//关联容器和顺序容器有着根本的不同：关联容器中的元素是按照关键字来保存与访问的。顺序容器是按他们在容器中的位置来保存和访问的


map<string, string> bulidMap(ifstream& map_file)
{
	map<string, string> trans_map;	//保存转换规则
	string key;		//要转换的单词
	string value;	//替换后的内容
	//读取第一个单词，存入key中，行中剩余的内容存入value
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)	//检查是否有转换规则
			trans_map[key] = value.substr(1);	//跳过前导空格
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string& transform(const string& s, const map<string, string>& m)
{
	//实际的转换工作
	auto map_it = m.find(s);
	//如果单词转换规则在map中
	if (map_it != m.cend())
		return map_it->second;	//使用替换短语
	else
		return s;		//否则返回原string
}

void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = bulidMap(map_file);	//保存转换规则
	string text;							//保存输入中的每一行
	while (getline(input, text))			//读取一行输入
	{
		istringstream stream(text);			//读取每个单词
		string word;
		bool firstword = true;				//控制是否打印空格
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";				//在单词间打印一个空格
			//transform返回它的第一个参数或者转换之后的形式
			cout << transform(word, trans_map);
		}
		cout << endl;			//完成一行的转换
	}
}

int main()
{
#if 0
	//使用map，一个经典的使用关联数组的例子就是单词计数程序
	//如果我们需要忽略常见单词，需要用到set
	set<string> exclude = { "The","But","And","Or","An","A",
							"the","but","and","or","an","a" };
	map<string, size_t> word_count;	//string到size_t的空map
	string word;
	while (cin >> word)
		if (exclude.find(word) == exclude.end())	//find调用返回一个迭代器，如果给定关键字在set中，迭代器指向该关键词，否则find饭hi尾后迭代器
			++word_count[word];		//提取word的计数器并将其加一，如果map中还没有word，就创建一个新的元素，关键词为word，值为0

	//从map中提取元素时，会得到一个类型的对象，
	for (const auto& w : word_count)
		//打印结果
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
#endif

#if 0
	//定义一个map时，必须既指明关键字类型，又指明值类型；而定义一个set时只需要指明关键字类型
	//对于给定的关键字map和set，只能有一个元素的关键字等于它。容器multimap和multiset就没有这个限制
	vector<int> ivec;
	for (vector<int>::size_type i = 0;i != 10;i++)
	{
		ivec.push_back(i);
		ivec.push_back(i);
	}
	//iset包含来自ivec的不重复元素，miset包含所有20个元素
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << miset.size() << endl;
	cout << iset.size() << endl;
#endif

	//练习11.7，定义map，关键字是家庭的姓，值是一个vector保存家庭中孩子的名
	map<string, vector<string>> families;
	add_family(families, "张");
	add_child(families, "张", "强");
	add_child(families, "张", "刚");
	add_child(families, "王", "五");
	add_family(families, "王");



	//auto i = families["王"][0];
	//cout << families["王"][0] << endl;

	for (auto f : families)
	{
		cout << f.first << "家的孩子：";
		for (auto c : f.second)
			cout << c << " ";
		cout << endl;
	}

	//有序容器的关键字类型要求：需要能够有比较操作
	//pair类型：在头文件utility中，一个pair保存两个数据成员。
	//类似容器，pair是一个用来生成特定类型的模板。当创建一个pair时，我们必须提供两个类型名，pair的数据成员将具有对应的类型，两个类型不要求一样
	pair<string, string> anon{"123", "456"};			//保存两个string 等价于pair<string, string> anon("123", "456");
	pair<string, size_t> word_count;	//保存一个string和一个size_t	
	pair<string, vector<int>> line;		//保存一个string和一个vector<int> 默认为空

	//make_pair(v1, v2); 返回v1，v2初始化的pair
	//p.first,p.second
	
	vector<pair<string, int>> a;

	/* 关联容器操作 */
	//除了p295的类型别名，关联容器还定义了其他的
	//key_type		此容器类型的关键字类型
	//mapped_type	每个关键字关联的类型；只适用于map
	//valute_type	对于set，与key_type相同，对于map，为pair<const key_type, mapped_type>

	/* 关联容器迭代器 */
	//set的迭代器时const的，虽然同时有iterator，const_iterator，但是都不能该笔那
	//遍历关联容器
#if 0

	//获得一个指向元素的迭代器
	auto map_it = word_count.cbegin();
	//比较当前迭代器和尾后迭代器
	while (map_it != word_count.cend())	{
		//解引用迭代器，打印关键字-值对
		cout << map_it->first << " occurs " << map_it->secode << " times " << endl;
		++map_it;//增加迭代器，移动到下一元素
	}

#endif

	/* 添加元素 */
	//set的insert成员，添加元素或者是一个元素范围
	//map的元素是pair，向map添加元素的四种方式
#if 0
	map<string, size_t> word_count;
	string word;
	auto = ret = word_count.insert({word, 1});
	word_count.insert(make_pair(word, 1));
	word_count.insert(pair<string, size_t>(word, 1));
	word_count.insert(map<string, size_t>::value_type(word, 1));

	//insert返回值注意下
	if (!ret.second)	//word已经在word_count中
		++ret.first->second;	//递增计数迭代器
#endif

	/* 删除元素 */
	//三个版本的erase

	/* map的下标操作 */
	//c[k]	返回关键字k的元素，如果k不在c中就添加一个关键字为k的元素
	//c.at[k] 访问关键字为k的元素，带参数检查，若不在，则抛出out_of_range异常

	/* 访问元素 */
	//find count lower_bound upper_bound equal_range
	//要区别返回的是迭代器，还是pair，还是值

	/* 一个单词转换的map */
	ifstream rule_file("rules"),text_file("text");
	word_transform(rule_file, text_file);

	/* 无序容器 */
	//不是按字典排序存储，在存储上组织为一组桶，每个桶保存零个或者多个元素





	return 0;

}