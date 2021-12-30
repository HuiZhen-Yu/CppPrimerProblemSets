#include "HasPtr_item.h"


HasPtr_val& HasPtr_val::operator=(const HasPtr_val& rhs)
{
	auto newp = new string(*rhs.ps);	//�ײ�string
	delete ps;	//�ͷž��ڴ�
	ps = newp;	//���Ҳ�������󿽱����ݵ�������
	i = rhs.i;
	return *this;	//���ر�����
}

HasPtr_val& HasPtr_val::operator=(HasPtr_val rhs)
{
	//��������������;ֲ�����rhs������
	swap(*this, rhs);
	return *this;
}


HasPtr_Ptr& HasPtr_Ptr::operator=(const HasPtr_Ptr& rhs)
{
	++* rhs.use;	//�����Ҳ��������������ü���
	if (-- * use == 0) {	//�ݼ�����������ü���
		delete ps;			//���û�������û�
		delete use;			//�ͷű��������ĳ�Ա
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}


HasPtr_Ptr::~HasPtr_Ptr()
{
	if (-- * use == 0)	//������ü�����Ϊ0
	{
		delete ps;		//�ͷ�string�ڴ�
		delete use;		//�ͷż������ڴ�
	}
}

StrVec::StrVec(const StrVec& s)
{
	//����alloc_n_copy����ռ���������s��һ�����Ԫ��
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec&& s) noexcept		//�ƶ�������Ӧ�׳��쳣
//��Ա��ʼ�����ӹ�s�е���Դ
	:elements(s.elements),first_free(first_free),cap(s.cap)
{
	//��s����������״̬--�����������������ǰ�ȫ��
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	//����alloc_n_copy�ڴ���䣬��С��rhs��Ԫ��ռ�ÿռ�һ����
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec& StrVec::operator = (StrVec&& rhs) noexcept
{
	//��⵽ֱ�Ӹ�ֵ
	if (this != &rhs)
	{
		free();			//�ͷ�����Ԫ��
		elements = rhs.elements;	//��rhs�ӹ���Դ
		first_free = rhs.first_free;
		cap = rhs.cap;
		//��rhs���ڿ�����״̬
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}


void StrVec::push_back(const string& s)
{
	chk_n_alloc();		//ȷ���ɿռ�������Ԫ��
	//��first_freeָ���Ԫ���й���s�ĸ���
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string&& s)
{
	chk_n_alloc();		//ȷ���ɿռ�������Ԫ��
		//��first_freeָ���Ԫ���й���s�ĸ���
	alloc.construct(first_free++, std::move(s));
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string* b, const string* e)
{
	//����ռ䱣�������Χ�еĶ�Ԫ��
	auto data = alloc.allocate(e - b);
	//��ʼ��������һ��pair����pair��data��unitialized_copy�ķ���ֵ����
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	//���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ0������ʲôҲ����
	if (elements) {
		//��������Ԫ��
		for (auto p = first_free; p != elements;/* �� */)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	//���ǽ����䵱ǰ��С�����Ŀռ�
	auto newcapacity = size() ? 2 * size() : 1;
	//�������ڴ�
	auto newdata = alloc.allocate(newcapacity);
	//�����ݴӾ��ڴ��ƶ������ڴ�
	auto dest = newdata;	//ָ������������һ������λ��
	auto elem = elements;	//ָ�����������һ��Ԫ��
	for (size_t i = 0;i != size();++i)
		alloc.construct(dest++, std::move(*elem++));
	//���ַ�ʽ����
#if 0
	auto first = alloc.allocate(newcapacity);
	//�ƶ�Ԫ��
	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
#endif

	free();			//һ����������ƶ�Ԫ�ؾ��ͷž��ڴ�ռ�
	//�������ǵ����ݽṹ��ִ����Ԫ��
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

StrVec::~StrVec()
{
	free();
}
