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
	//Window_mgr的成员可以访问Screen类的私有部分
	friend class Window_mgr;

	//friend void Window_mgr::clear(ScreenIndex);
public:
	typedef string::size_type pos;
	//using pos = string::size_type;
	//含有指针数据成员类的一般不宜使用默认的拷贝和复制操作，如果类的数据和成员都是内置类型的则不受干扰
	Screen() = default;	//因为Screen有另外一个构造函数，所以本函数是必须的
	//cursor被类内初始化为0
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}

	char get() const { return contents[cursor]; }	//读取光标处的字符，隐式内联
	char get(pos ht, pos wd) const;		//显式内联
	Screen& move(pos r, pos c);			//能在之后被设置成内联
	void some_member() const;

	Screen& set(char);
	Screen& set(pos, pos, char);
	pos size() const;

	//非常量版本的函数对于常量对象使不可用的
	//需要根据对象是否是const重载了display函数
	Screen& display(ostream& os)
	{	do_display(os);	return *this;	}

	const Screen& display(ostream& os) const
	{	do_display(os);	return *this;	}

private:
	//该函数负责显示Screen的内容
	void do_display(ostream& os) const { os << contents; }

	pos cursor = 0;
	pos height = 0, width = 0;
	//mutable使变量即使在一个const对象内也可以被修改
	mutable size_t access_ctr = 0;	
	string contents;
};

//inline函数成员应该和类定义在同一个头文件中
inline	//可以在函数的定义处指定inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;	//计算行的位置
	cursor = row + c;		//在行内将光标移动到指定的列
	return *this;			//以左值的形式返回对象
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;		//计算行的位置
	return contents[row + c];	//返回给定列的字符
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;//设置当前光标所在位置的新值
	return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;//设置指定位置的新值
	return *this;
}

class Window_mgr {
public:
	//窗口中每个屏幕的编号
	using ScreenIndex = vector<Screen>::size_type;
	//按照标号将指定的Screen重置为空白
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	//这个Window_mgr追踪的Screen
	//默认情况下，一个Window_mgr包含一个保准尺寸的空白Screen
	vector <Screen> Screens{ Screen(24, 80, ' ') };

};

#endif