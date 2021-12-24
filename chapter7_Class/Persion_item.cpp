#include "Persion_item.h"

istream& read(istream& is, Persion& per)
{
	is >> per.strName >> per.strAddress;
	return is;
}

ostream& print(ostream& os, const Persion& per)
{
	os << per.getName() << per.getAddress();
	return os;
}
