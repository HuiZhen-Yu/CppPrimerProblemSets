#ifndef SCREEN_ITEM_H_
#define SCREEN_ITEM_H_

#include <iostream>
#include <string>
#include <vector>

using std::istream;
using std::ostream;
using std::string;
using std::vector;


class Screen {
	//Window_mgr�ĳ�Ա���Է���Screen���˽�в���
	friend class Window_mgr;

	//friend void Window_mgr::clear(ScreenIndex);
public:
	typedef string::size_type pos;
	//using pos = string::size_type;
	//����ָ�����ݳ�Ա���һ�㲻��ʹ��Ĭ�ϵĿ����͸��Ʋ��������������ݺͳ�Ա�����������͵����ܸ���
	Screen() = default;	//��ΪScreen������һ�����캯�������Ա������Ǳ����
	//cursor�����ڳ�ʼ��Ϊ0
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}

	char get() const { return contents[cursor]; }	//��ȡ��괦���ַ�����ʽ����
	char get(pos ht, pos wd) const;		//��ʽ����
	Screen& move(pos r, pos c);			//����֮�����ó�����
	void some_member() const;

	Screen& set(char);
	Screen& set(pos, pos, char);
	pos size() const;

	//�ǳ����汾�ĺ������ڳ�������ʹ�����õ�
	//��Ҫ���ݶ����Ƿ���const������display����
	Screen& display(ostream& os)
	{	do_display(os);	return *this;	}

	const Screen& display(ostream& os) const
	{	do_display(os);	return *this;	}

private:
	//�ú���������ʾScreen������
	void do_display(ostream& os) const { os << contents; }

	pos cursor = 0;
	pos height = 0, width = 0;
	//mutableʹ������ʹ��һ��const������Ҳ���Ա��޸�
	mutable size_t access_ctr = 0;	
	string contents;
};

//inline������ԱӦ�ú��ඨ����ͬһ��ͷ�ļ���
inline	//�����ں����Ķ��崦ָ��inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;	//�����е�λ��
	cursor = row + c;		//�����ڽ�����ƶ���ָ������
	return *this;			//����ֵ����ʽ���ض���
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;		//�����е�λ��
	return contents[row + c];	//���ظ����е��ַ�
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;//���õ�ǰ�������λ�õ���ֵ
	return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;//����ָ��λ�õ���ֵ
	return *this;
}

class Window_mgr {
public:
	//������ÿ����Ļ�ı��
	using ScreenIndex = vector<Screen>::size_type;
	//���ձ�Ž�ָ����Screen����Ϊ�հ�
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	//���Window_mgr׷�ٵ�Screen
	//Ĭ������£�һ��Window_mgr����һ����׼�ߴ�Ŀհ�Screen
	vector <Screen> Screens{ Screen(24, 80, ' ') };

};

#endif