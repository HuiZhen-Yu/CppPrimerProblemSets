#ifndef PERSION_ITEM
#define PERSION_ITEM

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

class Persion
{
	friend istream& read(istream& is, Persion& per);

public:
	Persion() = default;
	Persion(const string& name, const string& add)
	{
		strName = name;
		strAddress = add;
	}
	explicit Persion(istream& is) { is >> this->strName >> this->strAddress; }

public:
	string getName()const { return strName; }
	string getAddress()const { return strAddress; }

private:
	string strName;
	string strAddress;
};


istream& read(istream& is, const Persion& per);
ostream& print(ostream& os, const Persion& per);




#endif // !PERSION_ITEM

