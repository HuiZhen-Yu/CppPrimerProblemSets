#include <iostream>
#include <sstream>

using namespace std;

istream& f(istream& in)
{
	int v;
	while (in >> v, !in.eof())//直到遇见文件结束符还停止读取
	{
		if (in.bad())
			throw runtime_error("IO流错误！！");
		if (in.fail())
		{
			cerr << "数据错误，请重试：" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	in.clear();
	return in;
}




int main()
{
	/* IO类型 */
	cout << "请输入一些整数，按control z结束" << endl;
	//f(cin);

	cout << "hi!" << endl;	//输出hi和一个换行，然后刷新缓冲区
	cout << "hi!" << flush;	//输出hi，然后刷新缓冲区，不附加任何字符
	cout << "hi!" << ends;	//输出hi和一个空字符，然后刷新缓冲区

	cout << unitbuf;	//所有输出操作后会立即刷新缓冲区
	//任何输出都立即刷新，无缓冲
	cout << nounitbuf;	//回到正常缓冲模式


	/* 文件流对象 fstream oftream iftream */
	
	//当一个fstream对象离开其作用域的时候，与之关联的文件会自动关闭（close会自动被调用）。在下一步循环中input会再次被创建
	//文件模式 in 读方式；out 写方式；app 操作前定位到文件尾；ate 打开文件后立即定位到文件尾；trunc 截断文件（原来内容会丢失）；binary 二进制方式
	//out默认就是截断方式

	/* string流对象 stringstream istringstream ostringstream */
	string line("Compass Huizhenyu 20 45 23-33 45.234");
	string comp, name, board;
	int num_1, num_2;
	double num_3;
	istringstream Record(line);
	//Record.str(line);
	//Record.clear();
	Record >> comp >> name >> num_1 >> num_2 >> board >> num_3;
	cout << comp << " " << name << " " << num_1 << " " << num_2 << " " << board <<" "<< num_3 << endl;

	


	return 0;
}