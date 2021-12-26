#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

/* 
* �����㷨
* 
* ˳������ֻ�����˺��ٵĲ�������ӣ�ɾ��������Ԫ�صȣ����û�ϣ���������ܶ����õĲ����������ض�Ԫ�ء��滻����ɾ��һ���ض�ֵ������Ԫ��˳���
* ��׼�Ⲣδ��ÿ�������������Ա������ʵ����Щ���������Ƕ�����һ�鷺���㷨��generic algorithm����ʵ���˾����㷨�Ĺ����ӿ�
* һ������£���Щ�㷨������ֱ�Ӳ������������Ǳ���������������ָ����һ��Ԫ�ط�Χ�����в���
* ���������㷨�������������������㷨������Ԫ�����͵Ĳ���
* �����㷨������ִ�������Ĳ�����ָ�������ڵ�����֮�ϣ�ִ�е������Ĳ�����
* �㷨��Զ����ı�ײ������Ĵ�С���㷨���ܸı������б����Ԫ�أ�Ҳ�������������ƶ�Ԫ�أ�������Զ����ֱ����ӻ���ɾ��Ԫ��
*/

void elimDups(vector<string>& words)
{
	//���ֵ�˳������words���Ա�����ظ�����
	sort(words.begin(), words.end());
	//unique�������뷶Χ��ʹ��ÿ�����ʶ�����һ��
	//�����ڷ�Χ��ǰ��������ָ���ظ�����֮��һ��λ�õĵ�����
	auto end_unique = unique(words.begin(), words.end());
	//ʹ����������eraseɾ���ظ�����
	words.erase(end_unique, words.end());
}

bool check_size(string& s, size_t sz)
{
	return s.size() < sz;
}

inline ostream& print(ostream& os, const string& s, char c)
{
	//io�����ܱ�������ֻ��ʹ������
	return os << s << c << endl;
}



void biggest(vector<string>& words, vector<string>::size_type sz, ostream& os = cout)
{
	elimDups(words);	//��words�����ֵ�˳������ɾ���ظ�����
	//���������򣬳�����ͬ�İ����ֵ�˳������
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size();});
	//��ȡһ����������ָ���һ������size()>=sz��Ԫ��
	auto wc = find_if(words.begin(), words.end(), [sz](const string& a) {return a.size() >= sz;});
	//ʹ��bind����
	auto check_sz = bind(check_size, std::placeholders::_1, sz);
	auto wc_2 = find_if(words.begin(), words.end(), bind(check_size, std::placeholders::_1, sz));
	//��������size>=sz��Ԫ�ص���Ŀ
	auto count = words.end() - wc;
	cout << count << " " << ((count > 1) ? "words":"word") << " of length " << sz << " or longer " << endl;

	//ref��ʾ���÷�ʽ��ֵ
	auto print_b = bind(print, ref(os), _1, ' ');
	//��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
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
	/* ֻ���㷨 find count accumulate����ͣ�equal��ȷ�����������Ƿ񱣴���ͬ��ֵ�� */
	//equal�����õ�������ɣ�������ǿ���ͨ������equal���Ƚ�������ͬ���͵������е�Ԫ�أ�����Ԫ������Ҳ���Բ�һ�� p399
	//fill��������ֵ����Ԫ�� fill_n()
	//back_inserter():����������������������Ԫ�صĵ����� auto it = back_inserter(vec)
	//copy(����), replace(�滻), replace_copy
	//sort(����), unique(��ѡ�����ظ�Ԫ��)��erase��ɾ��Ԫ�أ�

	/* ���ǿ��������㷨���Զ���������Ҫ����Ϊ */
	//���㷨���ݺ�����������������Ҳ����Ϊ��ν�ʣ�
	//ν�ʣ�predicate������һ�����õı��ʽ��iq���ؽ����һ��������������ֵ����׼���㷨���õ�ν�ʷ�Ϊ����һԪν�ʣ�unary predicate���Ͷ�Ԫν�ʣ�binary predicate��
	//sort(words.begin(), words.end(), isShorter)(����); stable_sort()��������ͬ���ȵĵ��ʰ��ֵ������У�����ʹ��stable_sort()�㷨�������㷨�ȶ������㷨ά�����Ԫ�ص�ԭ�����ݡ�
	//bool isShorter(const string &s1,const string &s2){ return s1.size() < s2.size() }
	//partition() :�����������е�Ԫ�ؽ��л���
	//find(); find_if()
	//for_each�㷨
	//�����������ݣ�ִ�и�������

	/* lambda���ʽ */
	//���ǿ������㷨�����κ����Ŀɵ��ö���callable object��������һ��������߱��ʽ��������Զ���ʵ�õ���������������Ϊ�ɵ��õġ�
	//�������e��һ���ɵ��õı��ʽ�������ǿ��Ա�д����e(args),����args��һ�����ŷָ���һ�����߶���������б�ĿǰΪֹ�����ǽӴ����Ŀɵ��ö���Ϊ�������ߺ���ָ��
	//�������ֿɵ��ö��������˺���������������࣬��lambda���ʽ

	//lambda���ʽ��ʾһ�����Ե��õĴ��뵥Ԫ�����ǿ��Խ������Ϊһ��δ����������������lambda����һ���������ͣ�һ�������б��һ��������
	//[capture list](parameter list)->return type{function body}
	auto f = [](const string& a, const string& b)->bool {return a.size() < b.size();};
	cout << f("sf", "asdgadbg") << endl;

	vector <string> testvs{ "a","abc","sdgfaegqaeg","asdgsdfq","s","a","seu","compass","fire","helloword","hello","erdfg" };
	biggest(testvs, 5);

	fcn2(2);

	cout << fcn3(2)() << endl;

	//�����÷�ʽ��׽һ������ʱ�����뱣֤��lambdaִ��ʱ����ʱ���ڵģ����龡������lambda�ı�������򵥻�
	//lambda����ʽ���񣬵����ǻ��ʹ����ʽ�������ʾ�����ʱ�򣬲����б��еĵ�һ��Ԫ�ر�����һ��&����=���˷����ƶ���Ĭ�ϲ���ʽΪ���û���ֵ��
	//��������ֻ��һ���ط�ʹ�õļ򵥲�����lambda���ʽ�������õġ����������Ҫ�ںܶ�ط�ʹ����ͬ�Ĳ�����ͨ��Ӧ�ö���һ�������������Ƕ�α�д��ͬ��lambda���ʽ

	/* ������ bind ͷ�ļ�functional�� */
	//_n��������һ����Ϊplaceholders�������ռ��У�����������ռ䱾������std��
	//ref()����
	//print_b("sfae");

	/* ��̽������ */
	//���������
	//iostream������
#if 0
	istream_iterator<int> in_iter(cin);	//��cin�ж�ȡint
	istream_iterator<int> eof;			//istreamβ�������
	vector<int> vec(in_iter, eof);
	vector<int> vec_1;
	while (in_iter != eof)
		//���õ����������ȡ�������ص������ľ�ֵ
		//�����õ���������ô�����ȡ��ǰһ��ֵ
		vec.push_back(*in_iter++);

	for (auto i : vec)
		cout << i << " ";
	//istream_iterator����ʹ��������ֵ�����Ƴٵ�ʹ�õ�����ʱ�����������ж�ȡ����

	//ostream_iteraor
	ostream_iterator<int> out_iter(cout, " ");
	for (auto e : vec)
		*out_iter++ = e;//����д��out_iter = e,��Ϊ*��++�����κ���
	cout << endl;
	//��ôЩ��ѭ�����Ӽ�
	copy(vec.begin(), vec.end(), out_iter);
	cout << endl;
#endif
	//ʹ������������������ ���ǿ���Ϊ�κζ��������������(<<)�����ʹ���istream_iterator�������Ƶ�ֻҪ����������(>>)���Ϳ���Ϊ�䶨��ostream_iterator

	/* ��������� */
	//��������������������д�βԪ������Ԫ�ط����ƶ��ĵ����������ڷ�����������������ĺ���ᷴ����
	//sort(vec.begin(), vec.end());	��������˳������vec
	//sort(vec.rbegin(), vec.rend()); ��������������СԪ�ط���vec��ĩβ

	string line("FIRST, MIDDLE, LAST");
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	cout << string(line.crbegin(), rcomma) << endl;		//TSAL

	cout << string(rcomma.base(), line.cend()) << endl;		//TSAL

	/* �����㷨�ṹ */
	//�㷨Ҫ��ĵ������������Է�Ϊ������������iterator category��
	/* 
	* ���������			ֻ������д������ɨ�裬ֻ�ܵ���
	* ���������			ֻд������������ɨ�裬ֻ�ܵ���
	* ǰ�������			�ɶ�д�����ɨ�裬ֻ�ܵ���
	* ˫�������			�ɶ�д�����ɨ�裬�ɵ����ݼ�
	* ������ʵ�����		�ɶ�д�����ɨ�裬֧��ȫ������������
	*/

	/* �㷨�β�ģʽ */
	//���κ��������㷨֮�ϻ���һ������淶��

	/* �㷨�����淶 */

	/* �ض��������㷨 */
	//list �� forword_list

	return 0;
}