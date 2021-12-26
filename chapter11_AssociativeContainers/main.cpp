#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <utility>	//pair����
#include <map>
#include <set>


using namespace std;

void add_family(map<string, vector<string>>& families, const string& family)
{
	if (families.find(family) != families.end())
		families[family] = vector<string>{};
	/* ����һ���ǳ��򵥵���ʽ */
	//families[family];//�����У��������κβ�������û�У������һ��Ĭ�ϳ�ʼ��
}

void add_child(map<string, vector<string>>& families, const string& famliy, const string& child)
{
	families[famliy].push_back(child);
}

/* �������� */
//����������˳���������Ÿ����Ĳ�ͬ�����������е�Ԫ���ǰ��չؼ�������������ʵġ�˳�������ǰ������������е�λ��������ͷ��ʵ�


map<string, string> bulidMap(ifstream& map_file)
{
	map<string, string> trans_map;	//����ת������
	string key;		//Ҫת���ĵ���
	string value;	//�滻�������
	//��ȡ��һ�����ʣ�����key�У�����ʣ������ݴ���value
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)	//����Ƿ���ת������
			trans_map[key] = value.substr(1);	//����ǰ���ո�
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string& transform(const string& s, const map<string, string>& m)
{
	//ʵ�ʵ�ת������
	auto map_it = m.find(s);
	//�������ת��������map��
	if (map_it != m.cend())
		return map_it->second;	//ʹ���滻����
	else
		return s;		//���򷵻�ԭstring
}

void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = bulidMap(map_file);	//����ת������
	string text;							//���������е�ÿһ��
	while (getline(input, text))			//��ȡһ������
	{
		istringstream stream(text);			//��ȡÿ������
		string word;
		bool firstword = true;				//�����Ƿ��ӡ�ո�
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";				//�ڵ��ʼ��ӡһ���ո�
			//transform�������ĵ�һ����������ת��֮�����ʽ
			cout << transform(word, trans_map);
		}
		cout << endl;			//���һ�е�ת��
	}
}

int main()
{
#if 0
	//ʹ��map��һ�������ʹ�ù�����������Ӿ��ǵ��ʼ�������
	//���������Ҫ���Գ������ʣ���Ҫ�õ�set
	set<string> exclude = { "The","But","And","Or","An","A",
							"the","but","and","or","an","a" };
	map<string, size_t> word_count;	//string��size_t�Ŀ�map
	string word;
	while (cin >> word)
		if (exclude.find(word) == exclude.end())	//find���÷���һ������������������ؼ�����set�У�������ָ��ùؼ��ʣ�����find��hiβ�������
			++word_count[word];		//��ȡword�ļ������������һ�����map�л�û��word���ʹ���һ���µ�Ԫ�أ��ؼ���Ϊword��ֵΪ0

	//��map����ȡԪ��ʱ����õ�һ�����͵Ķ���
	for (const auto& w : word_count)
		//��ӡ���
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
#endif

#if 0
	//����һ��mapʱ�������ָ���ؼ������ͣ���ָ��ֵ���ͣ�������һ��setʱֻ��Ҫָ���ؼ�������
	//���ڸ����Ĺؼ���map��set��ֻ����һ��Ԫ�صĹؼ��ֵ�����������multimap��multiset��û���������
	vector<int> ivec;
	for (vector<int>::size_type i = 0;i != 10;i++)
	{
		ivec.push_back(i);
		ivec.push_back(i);
	}
	//iset��������ivec�Ĳ��ظ�Ԫ�أ�miset��������20��Ԫ��
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << miset.size() << endl;
	cout << iset.size() << endl;
#endif

	//��ϰ11.7������map���ؼ����Ǽ�ͥ���գ�ֵ��һ��vector�����ͥ�к��ӵ���
	map<string, vector<string>> families;
	add_family(families, "��");
	add_child(families, "��", "ǿ");
	add_child(families, "��", "��");
	add_child(families, "��", "��");
	add_family(families, "��");



	//auto i = families["��"][0];
	//cout << families["��"][0] << endl;

	for (auto f : families)
	{
		cout << f.first << "�ҵĺ��ӣ�";
		for (auto c : f.second)
			cout << c << " ";
		cout << endl;
	}

	//���������Ĺؼ�������Ҫ����Ҫ�ܹ��бȽϲ���
	//pair���ͣ���ͷ�ļ�utility�У�һ��pair�����������ݳ�Ա��
	//����������pair��һ�����������ض����͵�ģ�塣������һ��pairʱ�����Ǳ����ṩ������������pair�����ݳ�Ա�����ж�Ӧ�����ͣ��������Ͳ�Ҫ��һ��
	pair<string, string> anon{"123", "456"};			//��������string �ȼ���pair<string, string> anon("123", "456");
	pair<string, size_t> word_count;	//����һ��string��һ��size_t	
	pair<string, vector<int>> line;		//����һ��string��һ��vector<int> Ĭ��Ϊ��

	//make_pair(v1, v2); ����v1��v2��ʼ����pair
	//p.first,p.second
	
	vector<pair<string, int>> a;

	/* ������������ */
	//����p295�����ͱ���������������������������
	//key_type		���������͵Ĺؼ�������
	//mapped_type	ÿ���ؼ��ֹ��������ͣ�ֻ������map
	//valute_type	����set����key_type��ͬ������map��Ϊpair<const key_type, mapped_type>

	/* �������������� */
	//set�ĵ�����ʱconst�ģ���Ȼͬʱ��iterator��const_iterator�����Ƕ����ܸñ���
	//������������
#if 0

	//���һ��ָ��Ԫ�صĵ�����
	auto map_it = word_count.cbegin();
	//�Ƚϵ�ǰ��������β�������
	while (map_it != word_count.cend())	{
		//�����õ���������ӡ�ؼ���-ֵ��
		cout << map_it->first << " occurs " << map_it->secode << " times " << endl;
		++map_it;//���ӵ��������ƶ�����һԪ��
	}

#endif

	/* ���Ԫ�� */
	//set��insert��Ա�����Ԫ�ػ�����һ��Ԫ�ط�Χ
	//map��Ԫ����pair����map���Ԫ�ص����ַ�ʽ
#if 0
	map<string, size_t> word_count;
	string word;
	auto = ret = word_count.insert({word, 1});
	word_count.insert(make_pair(word, 1));
	word_count.insert(pair<string, size_t>(word, 1));
	word_count.insert(map<string, size_t>::value_type(word, 1));

	//insert����ֵע����
	if (!ret.second)	//word�Ѿ���word_count��
		++ret.first->second;	//��������������
#endif

	/* ɾ��Ԫ�� */
	//�����汾��erase

	/* map���±���� */
	//c[k]	���عؼ���k��Ԫ�أ����k����c�о����һ���ؼ���Ϊk��Ԫ��
	//c.at[k] ���ʹؼ���Ϊk��Ԫ�أ���������飬�����ڣ����׳�out_of_range�쳣

	/* ����Ԫ�� */
	//find count lower_bound upper_bound equal_range
	//Ҫ���𷵻ص��ǵ�����������pair������ֵ

	/* һ������ת����map */
	ifstream rule_file("rules"),text_file("text");
	word_transform(rule_file, text_file);

	/* �������� */
	//���ǰ��ֵ�����洢���ڴ洢����֯Ϊһ��Ͱ��ÿ��Ͱ����������߶��Ԫ��





	return 0;

}