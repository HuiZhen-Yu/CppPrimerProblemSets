#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <stdexcept> 
#include "Blob_item.h"

using namespace std;

/* ��̬�ڴ� 
* 
* ��ĿǰΪֹ����ֻ�õ���̬�ڴ���ջ�ڴ�
* ��̬�ڴ���������ֲ�static������static���ݳ�Ա���Լ��������κκ���֮��ı���
* ջ�ڴ��������涨�庯���ڵķ�static����
* �����ھ�̬��ջ�ڴ��еĶ����ɱ������Զ����������١�����ջ���󣬽����䶨��ĳ��������ʱ�Ŵ��ڣ�static������ʹ��ǰ���䣬�ڳ������ʱ����
* 
* ���˾�̬�ڴ��ջ�ڴ棬ÿ������ӵ��һ���ڴ�ء��ⲿ���ڴ汻��Ϊ���ɿռ䣨free store����ѣ�heap��
* �����ö����洢��̬���䣨dynamically allocate���Ķ���--������Щ�ڳ�������ʱ����Ķ���
* ��̬������������ɳ��������ƣ�Ҳ����˵������̬������ʹ�õ�ʱ�����ǵĴ��������ʾ���������ǡ�
* 
*/

vector<int>* new_vector()
{
	return new(nothrow) vector<int>;
}

shared_ptr<vector<int>> new_vector_s()
{
	return make_shared<vector<int>>();
}

void read_inV(vector<int> *pv)
{
	int v;
	while (cin >> v)
		pv->push_back(v);
}

void read_inV_s(shared_ptr<vector<int>> spv)
{
	int v;
	while (cin >> v)
		spv->push_back(v);
}

void print_ints(vector<int>* pv)
{
	for (const auto v : *pv)
		cout << v << " ";
	cout << endl;
}

void print_ints_s(shared_ptr<vector<int>> spv)
{
	for (const auto v : *spv)
		cout << v << " ";
	cout << endl;
}
int main()
{
	/* ��̬�ڴ���ֻ��ָ�� */
	//Ϊ�˸��õ�ʹ�ö�̬�ڴ棬�µı�׼���ṩ����������ָ�루smart pointer������������̬�ڴ����
	//shared_ptr: ������ָ��ָ��ͬһ����	; unique_ptr����ռ��ָ��Ķ���; ��׼�⻹������һ��weak_ptr�İ����࣬����һ�������ã�ָ��shared_ptr������Ķ���

#if 0
	//����vector������ָ��Ҳ��ģ�壬�����Ǵ�������ָ���ʱ��Ҳ��Ҫ�����������Ϣ��ָ�����ָ��ĵ�����
	shared_ptr<string> p1;	//shared_ptr ָ�� string
	shared_ptr<list<int>> p2;	//shared_ptrָ�� int��list

	if (p1 && p1->empty())
		*p1 = "hi";	//���p1ָ��һ����string��������p1����һ����ֵ����string

	//�ȫ�ķ����ʹ�ö�̬�ڴ�ķ�ʽʱ����һ������make_shared�ı�׼�⺯�����˺����ڶ�̬�ڴ��з���һ�����󲢳�ʼ����������ָ��˶����shared_ptr��
	shared_ptr<int> p3 = make_shared<int>(42); 
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>();
#endif
	/* shared_ptr�Ŀ����͸�ֵ */
	//�����п������߸�ֵ����ʱ��ÿ��shared_ptr�����¼�ж��ٸ�����shared_ptrָ����ͬ�Ķ��󡣣�����ʼ������һ����ָ�룩
	//���ǿ�����Ϊÿ��shared_ptr����һ�������ļ�������ͨ������Ϊ���ü�����reference count����
	//���ۺ�ʱ���ǿ���һ��shared_ptr����������������������Ǹ�shared_ptr����һ����ֵ����shared_ptr�����٣��뿪�����򣩼������ͻ�ݼ���

	//shared_ptr�Զ�����������Ķ���ͨ����������ʵ�ֵģ������仹���Զ��ͷ���صĶ��ڴ�
	//�������������ͬ״̬��ʱ��ͻ��õ���̬�ڴ����
#if 0
	vector <int> a;
	a.push_back(1);
	try {
		a.at(1);
	}
	catch (std::out_of_range exc) {
		std::cerr << exc.what() << " Line:" << __LINE__ << " File:" << __FILE__ << endl;
	}
	return EXIT_SUCCESS;
#endif

#if 0
	StrBlob b1;
	{
		StrBlob b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;
	
	const StrBlob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;
#endif

	/* ֱ�ӹ����ڴ� */
	//new �����ڴ棬delete�ͷ�new������ڴ�
	//�Լ�ֱ�ӹ����ڴ������ʹ������ָ����಻ͬ�����ǲ���������Զ��󿽱�����ֵ�����ٲ������κ�Ĭ�϶���
#if 0
	int* pi = new int{1024};
	int* pi1 = new int;	//δ����ֵ
	int* pi2 = new int();//��ʼ��Ϊ0
	const int* pci = new const int(1024);
	string* ps = new string(10, '9');
	vector<int>* pv = new vector<int>{ 0,1,2,3,4,5,6,7,8,9 };

	auto p1 = new auto(12);
	//auto p2 = new auto{12, 13};//����ֻ���е�һ��ʼ����
	int* p11 = new int;	//�������ʧ�ܣ�new�׳�std::bad_alloc
	int* p2 = new (nothrow) int;	//�������ʧ�ܣ��򷵻ؿ�ָ�룬��������ʽ��newΪ��λnew��placement new��

	//�ͷŶ�̬�ڴ� ͨ��delete���ʽ��delete expression��������̬�ڴ�黹��ϵͳ��delete���ʽ����һ��ָ�룬ָ��������Ҫ�ͷŵĵط�
	delete pi;		//pi������ָ��һ����̬�ڴ������ڴ棬������һ����ָ��
	//deleteָ���������������ٸ�����ָ��ָ��Ķ����ͷŶ�Ӧ���ڴ�
	//const�����ֵ���ܸı䣬���ǿռ���Ա�����
	//������ָ�루����������ָ�룩����Ķ�̬�ڴ��ڱ���ʽ���ͷ�ǰһֱ�����ڣ��ظ�delete���ܻ��ƻ����ɿռ䣬delete֮��ָ��ͱ��������˵�Ŀ���ָ�루dangling pointer��
	//������delete֮����nullptrָ��ָ��
#endif

#if 0
	vector<int>* pv = new_vector();
	if (!pv)
	{
		cerr << "�ڴ治�㣡" << endl;
		return -1;
	}

	read_inV(pv);
	print_ints(pv);

	delete pv;
	pv = nullptr;

	auto spv = new_vector_s();
	read_inV_s(spv);
	print_ints_s(spv);

#endif

	//shared_ptr��new���ʹ��
	//shared_ptr<int> p1 = new int(1024);	//���󣬱���ʹ��ֱ�ӳ�ʼ����ʽ
	shared_ptr<int> p1(new int(1024));
	//ʹ������ָ��������һ������ָ�����Ϊ��Σ�գ���Ϊ���ǲ�֪������ʲôʱ��ᱻ����
	//��Ҫʹ��get��ʼ����һ������ָ�����Ϊ����ָ�븳ֵ��ʹ��get���ص�ָ��Ĵ��벻��delete��ָ�루get������ָ��ķ���Ȩ�޴��ݸ����룬��ֻ����ȷ�����벻��deleteָ�������²���ʹ��get��
	//reset����һ���µ�ָ�븳��shared_ptr��uniqueһ�����ʹ�� p414

	//���ʹ������ָ�����new֮��delete֮ǰ���������쳣�����ڴ治�ᱻ�ͷ�
	//ͨ��shared_ptr���������Լ����ͷŲ����������Ǵ���һ��shared_ptr��ʱ�򣬿��Դ���һ����ѡ��ָ��ɾ���������Ĳ���
	//void end_connection(connection *p) { disconnect(*p); }
	//void f(destination &d /* �������� */) 
	//{ connection c = connect(&d);shared_ptr<connection> p(&c, end_connection);
	//	ʹ�����ӣ���f�˳���ʱ��connection�ᱻ��ȷ�ر�
	// }

	//unique_ptr ĳ��ʱ��ֻ����һ��umique_ptrָ��һ���������󡣵�unique_ptr������ʱ������ָ��Ķ���Ҳ������
	//������i����һ��unique_ptr��ʱ����Ҫ����󶨵�һ��newָ���ϣ���ʼ���������ֱ�ӳ�ʼ������ʽ
	

	//weak_ptr��һ�ֲ�������ָ����������ڵ�����ָ�룬��ָ����һ��shared_ptr����Ķ��󣬽�weak_ptr�󶨵�shared_ptr����ı����ü�����
	//���ǲ���ֱ�ӵ���weak_ptr����Ҫ��lock

	/* ��̬���� */
	//��ʼ��
	//��allocator���������ǽ�����ͳ�ʼ������
	int* pia = new int[10];
	int* pia2 = new int[10]();	//ȫΪ��
	int* pia3 = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };//�����������Ŀ���Ͳ���bad_array_new_length��ͷ�ļ�new�У�
	string* psa = new string[10];

	delete [] pia;
	delete [] pia2;
	delete [] pia3;
	delete [] psa;

	//�ͷţ�Ϊ���ͷŶ�̬���飬delete��ָ��ǰ����һ���շ����Ŷ�
	typedef int arrT[42];
	int* p = new arrT;
	delete[]p;		//�������Ǳ���ģ���Ϊ���ǵ����������һ������

	//����new���������unique_ptr�汾
	//upָ��һ������10��δ��ʼ��int������
	unique_ptr<int[]> up(new int[10]);
	for (size_t i = 0;i != 10;++i)
		up[i] = i;		//	Ϊÿ��Ԫ�ظ���һ����ֵ
	for (size_t i = 0;i != 10;++i)
		cout << up[i] << " ";
	cout << endl;
	up.release();	//�Զ���delete[]������ָ��

	/* allocator�ࣨģ�壩 */
	//������memory��ͷ�ļ��У����������ǽ��ڴ����Ͷ�������뿪�������ṩһ�����͸�֪���ڴ���䷽ʽ����������ڴ���ԭʼ�ġ�δ�����

	allocator<string> alloc;	//���Է���string��allocator����
	auto const p_1 = alloc.allocate(10);	
	auto q = p_1;
	alloc.construct(q++);	//���ַ���
	alloc.construct(q++, 10, 'c');	//*qΪ"cccccccccc"
	alloc.construct(q++, "hi");		//*qΪhi

	while (q != p_1)
		alloc.destroy(--q);	//�ͷ����������string

	//Ԫ�����ٺ��ͷ��ڴ�ͨ��deallocate����ɣ�
	alloc.deallocate(p_1, 10);

	//cout << *(--q) << endl;

	return 0;
}