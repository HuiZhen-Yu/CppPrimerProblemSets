#include "Screen_item.h"

void Screen::some_member() const
{
	//����һ������ֵ�����ڼ�¼��Ա���������õĴ���
	++access_ctr;	
	/* �ó�Ա��Ҫ��ɵ��������� */
}

Screen::pos Screen::size() const
{
	return height * width;
}

void Window_mgr::clear(ScreenIndex i)
{
	//s��һ��Screen�����ã�ָ��������Ҫ��յ��Ǹ���Ļ
	Screen& s = Screens[i];
	//��ѡ����Screen����Ϊ�հ�
	s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
	Screens.push_back(s);
	return Screens.size() - 1;
}






