#ifndef BLOB_ITEM_H_
#define	BLOB_ITEM_H_

#include <string>
#include <vector>
#include <memory>


class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	//���Ӻ�ɾ��Ԫ��
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();
	//Ԫ�ط���
	std::string& front();
	std::string& back();
	const std::string& front() const ;
	const std::string& back() const ;

private:
	std::shared_ptr<std::vector<std::string>> data;
	//���data[i]���Ϸ������׳�һ���쳣
	void check(size_type i, const std::string& msg) const;
};





#endif // !BLOB_ITEM_H_
