#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

/* 
* ���������������ת�� 
* ������������������͵Ķ����ʱ��c++��������Ϊ��ָ���µĺ��壻
* ����������Ǿ����������ֵĺ��������������ɹؼ���operator�����Ҫ�����������Ź�ͬ��ɡ����������Ҳ�����������͡������б��Լ�������
* �������صĺ������������operator()֮�⣬����������������ܺ���Ĭ��ʵ��
* ���һ������������ǳ�Ա�����������ĵ�һ������ࣩ�������󶨵���ʽ��thisָ���ϣ���˳�Ա����������Ĳ�������������������������һ��
* ����һ�������������˵����������ĳ�Ա���������ٺ���һ�������͵Ĳ�����
*/

//��ͨ����
int add(int i, int j)
{
	return i + j;
}

int main()
{
	/* ����������ĵ��� */
	//һ���ǳ�Ա������ĵȼ۵���	data1 + data2;	operator + (data1, data2);
	//��Ա�����		data1 += data2;	�ȼ���	data1.operator+=(data2);
	//ͨ������£���Ӧ�����ض��ţ�ȡ��ַ���߼�����߼�������

	/* ���������������ǳ�Ա������ */
	//������������		<<		ostream &operator<<(ostream & os,const Sales_data &item);	���������������ٸ�ʽ������
	//�������������		>>		istream &operator>>(istream & is,const Sales_data &item);	������������봦�����������ʧ�ܵ����
	//if(is) ... else ..

	/* �����͹�ϵ�����(ͨ������¶��Ƿǳ�Ա����) */
	//���ĳ�������߼�������ȵĺ��壬�����Ӧ�ö���operator==��������==ҲӦ�ö��壡=
	//��ֵ����� = ;vector<string> v; v = {"a", "an", "the"}; StrVec &operator=(std::initializer_list<std::string>); �����β���ʲô����ֵ��������붨��Ϊ��Ա����
	//���ϸ�ֵ�����

	//�±�������������ǳ�Ա�����������һ��������±������������ͨ�����������汾��һ��������ͨ���ã���һ������ĳ�����Ա�������س�������
	//�����͵ݼ��������������Ӧ��ͬʱ���壬������Щ�����ͨ��Ӧ�ñ��������ĳ�Ա
	//ǰ�ã�StrBlobPtr &operator++(); StrBlobPtr &operator--();  ���ص���/�ݼ�֮�������
	//���ã�Ϊ������ǰ�ð汾�ͺ��ð汾�����ð汾����һ������ģ�����ʹ�õ��βΡ�StrBlobPtr &operator++(int); StrBlobPtr &operator--(int);���ð汾Ӧ�÷�hi�����ԭֵ(�������ߵݼ�֮ǰ��ֵ)����Ӧ����һ��ֵ������һ������
	 
	//��Ա��������� *��->����������ĳ�Ա�� ���ؼ�ͷ��������뷵�����ָ������Զ����˼�ͷ�������ĳ����Ķ���
#if 0
	class StrBlobPtr {
	public:
		std::string& operator*() const
		{
			auto p = check(curr, "difference past end");
			return (*p)[curr];		//(*p)�Ƕ�����ָ��vector
		}
		std::string* operator->() const
		{	//��ʵ�ʹ���ί�и������������
			return &this->operator*();			
		}
		//������Ա
	};

#endif

	/* ������������� */
	//��������˺�������������������ǿ�����ʹ�ú���һ��ʹ�ø���Ķ�����Ϊ��������ͬʱҲ�ܴ洢״̬������ͨ�����ȸ������
	//������������������ǳ�Ա������һ������Զ�������ͬ�汾�ĵ��������������Ӧ���ڲ�������������������������
#if 1
	struct absInt {
		int operator() (int val) const {
			return val < 0 ? -val : val;
		}
	};
#endif
	//��������˵���������������Ķ��������������function object������Ϊ���Ե������ֶ�����������˵��Щ�������Ϊ����һ��

	cout << sizeof(absInt) << endl;

	/* lambda�Ǻ������� */
	//�����Ǳ�д��һ��lambda�󣬱����������ʽ�����һ��δ�������δ����������lambda���ʽ���������к���һ�����صĺ������������

#if 0
	//���ݵ��ʵĳ��ȶ���������򣬶�ҽ������ͬ�ĵ��ʰ�����ĸ��˳������
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size();});
	//����Ϊ�������������δ��������
	class ShorterString 
	{
	public :
		bool operator()(const string& s1, const string& s2) const
		{
			return s1.size() < s2.size();
		}
	};
	stable_sort(words.begin(), words.end(), ShorterString());
#endif

	/* ��׼�ⶨ��ĺ������� */
	//plus modulus equal_to
	plus<int> intAdd;		//��int�ӷ��ĺ�����
	negate<int> intNegate;	//��intֵȡ���ĺ�������

	int sum = intAdd(10, 20);
	sum = intNegate(intAdd(10, 20));

	//����һ����ʱ�ĺ�����������ִ������string������ڵıȽ�����
//	sort(svec.begin(), svec.end(), greater<string>());

	//ע��ָ���ʹ��
#if 0
	vector<string*> nameTable;
	//����nameTable�е�ָ��û�б˴˹�ϵ
	sort(nameTable.begin(), nameTable.end(), [](string* a, string* b) {return a < b;});
	//��ȷ ��׼��涨ָ���less�����õ�
	sort(nameTable.begin(), nameTable.end(), [](string* a, string* b) {return a < b;});
#endif
	//��������ʹ��less<key_type>��������

	/* �ɵ��ö�����function */
	//c++���м��ֿɵ��õĶ��󣺺���������ָ�롢lambda���ʽ��bind�����Ķ����Լ������˺����������������
	//����������һ�����ɵ��ö���Ҳ�����ͣ�������ͬ���͵Ŀɵ��ö�����ܹ���һ�ֵ�����ʽ(call signature)

	//Ϊ�˽������֣�������Ҫ����һ�����������ڴ洢ָ����Щ�ɵ��ö���ġ�ָ�롱
#if 0
	//��ͨ����
	int add(int i, int j) { return i + j; }
	//lambda�������һ��δ�����ĺ���������
	auto mod = [](int i, int j) {return i % j;};
	//����������
	struct divide
	{
		int operator() (int denominator, int divisor) { return denominator / divisor; }
	};
	//������ �����������������ָ���ӳ���ϵ�����к�����������int������һ��int
	map<string, int(*)(int, int)> binops;
	binops.insert({ "+", add });	//{"+", add}��һ��pair
	//��������ȴ���� binops.insert({"%s", mod});		//����mod����һ������ָ��
	//Ϊ�˽��������⣬���ǽ���һ����Ϊfunction���µı�׼�����ͽ����������
#endif

	//lambda�������һ��δ�����ĺ���������
	auto mod = [](int i, int j) {return i % j;};
	//����������
	struct divide
	{
		int operator() (int denominator, int divisor) { return denominator / divisor; }
	};
	//function���±�׼�����ͽ���������⣬function������functiontialͷ�ļ��У��洢����ɵ��ö���
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = divide();
	function<int(int, int)> f3 = [](int i, int j) {return i % j;};

	cout << f1(4, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 2) << endl;

	//����ʹ�����function�������¶���map
	//�ɵ��ö������Ԫ�������Ӧ��ϵ�ı��
	//���пɵ��ö��󶼱����������int������һ��int
	//���е�Ԫ�ؿ����Ǻ���ָ�룬�������������lambda
	map<string, function<int(int, int)>> binops = {
		{"+", add},										//����ָ��
		{"-", std::minus<int>()},						//minus<int>�ĵ��������
		{"/", divide()},								//�û�����ĺ�������
		{"*", [](int i, int j) { return i * j;}},		//δ������lambda���ʽ
		{"%", mod}										//�����˵�lambda���ʽ
	};
	
	cout << binops["+"](10, 5) << endl;			//������add(10, 5)
	cout << binops["-"](10, 5) << endl;			//ʹ��minus<int>�ĵ��������
	cout << binops["*"](10, 5) << endl;			//����lambda��������
	cout << binops["/"](10, 5) << endl;			//����divide�ĵ��������
	cout << binops["%"](10, 5) << endl;			//����lambda��������

	//���صĺ�����function
	//���ǲ���ֱ�ӽ����صĺ�������ֱ�Ӵ���function��
#if 0
	int add(int i, int j) { return i + j; }
	Sales_data add(const Sales_data&, const Sales_data&);
	map<string, function<int(int, int)>> binops;
	binops.insert({"+", add});		//���󣬲�֪�����Ǹ�add

	//��������Ķ���������ķ�ʽ���Ǵ洢����ָ������Ǻ�������
	int (*fp)(int, int) = add;
	binops.insert({ "+", fp });		//��ȷ

	//Ҳ������lambda������������
	binops.insert({ "+", [](int a, int b) {return add(a,b);} });		//��ȷ
#endif

	/* ��������ת��������� */
	//ת�����캯��������ת���������ͬ������������ת����class-type conversiton��,������ת������Ҳ�������û����������ת����user-define conversions��
	//����ת���������conversion operator�������һ�������Ա������ת����ʽΪopeartor type() const;

	//һ������ת��������������ĳ�Ա�����������������������ͣ��²��б�Ҳ����Ϊ�ա�����ת������ͨ��Ӧ����const
	//����ת�����ܻ���������Ч��
	int i = 42;
//	cin << i; //cin�ᱻת����bool��Ȼ���ٱ�ת����int������42λ

#if 0
	//��ʾ������ת���������explicit conversion operator��
	class SmallInt {
		public:
			//�����������Զ�ִ����һ���͵�ת��
			explicit operator int() const { return val; }
			//������Ա����һ�µ�
	};
	SmallInt si = 3;			//��ȷ��SmallInt�Ĺ��캯��������ʾ��
	si + 3;						//���󣺴˴���Ҫ��ʽ������ת��������������������ʽ��
	static_cast<int> (si) + 3;	//��ȷ����ʾ����������ת��
#endif

	//��ҪΪ�ඨ����ͬ������ת����Ҳ��Ҫ�����ж��������Լ���������ת��Դ��ת��Ŀ�����������͵�ת����
	//��ò�Ҫ��������֮�乹����ͬ������ת��
#if 0
	struct B;
	struct A {
		A() = default;
		A(const B&);	//��һ��Bת����A
		//���������ݳ�Ա
	};

	struct B {
		operator A() const;		//��һ��Bת����A
		//�������ݳ�Ա
	};

	A f(const A&);
	B b;
	A a = f(b);	//�����Դ��󣺺�����f(B::operator A())
				//����f(A::A(const B&));

	A a = f(b.operator A());
	A.a2 = f(A(b));
#endif

	//����ƥ�����������ط��� ���ص������Ҳ�����صĺ���

#if 0
	class SmallInt() {
		friend SmallInt operator +(const SmalllInt&, const SmalllInt&);
	public:
		SmallInt(int = 0);						//ת��ԴΪint������ת��
		operator int() const { return val; }	//�����Դ���
	private:
		std::size_t val;
	};

	SmallInt s1, s2;
	SmallInt s3 = s1 + s2;	//ʹ�����ص�+
	int i = s3 + 0;			//�����Դ��� 0->SmallInt or�� s3->int
#endif


	return 0;
}