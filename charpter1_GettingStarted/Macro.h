#ifndef _MACRO_H_
#define _MACRO_H_

#include <iostream>


#define PROBLEM_LABEL(num)	PROB_##num

typedef int(*prob_func)(void);

enum problem_num
{
	PROBLEM_LABEL(3) = 0,
	PROBLEM_LABEL(4),
	PROBLEM_LABEL(9),
	PROBLEM_LABEL(16),
};

extern prob_func prob_arry[];







#endif // !_MACRO_H_

