#ifndef EXERCISE_H_
#define EXERCISE_H_

#include <iostream>
#include <string>

class NoDefault
{
public:
	//NoDefault() = default;
	//NoDefault(int i)
	//{
	//	val = i;
	//}

private:
	int val/* = 0*/;
};

class C
{
public:
	NoDefault a;
	//C(int b = 0) : a(b) {}
};

class Debug {
public:
	constexpr Debug(bool b = true) :hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(0){ }
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }


private:
	bool hw;			//Ӳ���������io����
	bool io;			//io����
	bool other;			//��������
};

//��̬���ݳ�Ա
class Account {

public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

double Account::initRate()
{
	return 0.0;
}

//���岢��ʼ��һ����̬��Ա
//��̬������Ա���������ڳ�ʼ�����������Բ���Ҫ������������ò�����ֻ�������ڳ�ʼ������������ʱ���õ�
//���������������ڳ�ʼ��
double Account::interestRate = initRate();

void Account::rate(double newRate)
{
	interestRate = newRate;
}



#endif // !EXERCISE_H_
