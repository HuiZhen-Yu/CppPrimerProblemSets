#pragma once
#include <string>
#include <memory>
#include <utility>

using std::string;
using std::size_t;
using std::allocator;
using std::pair;

class HasPtr_val
{
	friend void swap(HasPtr_val&, HasPtr_val&);
public:
	HasPtr_val(const string& s = string()) :
		ps(new string(s)), i(0) {}
	//��psָ���string��ÿ��HasPtr�������Լ��Ŀ���
	HasPtr_val(const HasPtr_val& p) :
		ps(new string(*p.ps)), i(p.i) {}
	HasPtr_val& operator = (const HasPtr_val&);
	HasPtr_val& operator = (HasPtr_val);
	~HasPtr_val() { delete ps; }

private:
	string* ps;
	int i;
};

class HasPtr_Ptr
{
public:
	//���캯�������µ�string���µļ�����������������Ϊ1
	HasPtr_Ptr(const string& s = string()) :
		ps(new string(s)), i(0), use(new size_t(1)) {}
	//�������캯�����������ݳ�Ա��������������
	HasPtr_Ptr(const HasPtr_Ptr& p) :
		ps(p.ps), i(p.i), use(p.use) {	++* use;	}
	HasPtr_Ptr& operator=(const HasPtr_Ptr&);

	~HasPtr_Ptr();

private:
	string* ps;
	int i;
	size_t* use;	//	��¼�ɶ��ٹ����*ps��Ա

};

inline void swap(HasPtr_val& lhs, HasPtr_val& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}


class StrVec
{
public:
	StrVec() :		//allocator��Ա����Ĭ�ϳ�ʼ��
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);					//�������캯��
	StrVec(StrVec&&) noexcept;						//�ƶ����캯��
	StrVec& operator = (const StrVec&);		//������ֵ�����
	StrVec& operator = (StrVec&&) noexcept;	//�ƶ���ֵ�����
	~StrVec();								//��������
	void push_back(const string&);			//����Ԫ��
	void push_back(string &&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }

private:
	allocator<string> alloc;	//����Ԫ��
	//���Ԫ�صĺ�����ʹ��
	void chk_n_alloc()
	{	if (size() == capacity()) reallocate();	}
	//���ߺ������������Ĺ��캯������ֵ����������������
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();						//����Ԫ�ز��ͷ��ڴ�
	void reallocate();					//��ø����ڴ沢�������е�Ԫ��
	string* elements;					//ָ��������Ԫ�ص�ָ��
	string* first_free;					//ָ�������һ������Ԫ�ص�ָ��
	string* cap;						//ָ������β��λ�õ�ָ��
};

