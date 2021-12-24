#include "Screen_item.h"

void Screen::some_member() const
{
	//保存一个计数值，用于记录成员函数被调用的次数
	++access_ctr;	
	/* 该成员需要完成的其他动作 */
}

Screen::pos Screen::size() const
{
	return height * width;
}

void Window_mgr::clear(ScreenIndex i)
{
	//s是一个Screen的引用，指向我们想要清空的那个屏幕
	Screen& s = Screens[i];
	//将选定的Screen重置为空白
	s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
	Screens.push_back(s);
	return Screens.size() - 1;
}






