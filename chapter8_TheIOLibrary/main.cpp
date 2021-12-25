#include <iostream>
#include <sstream>

using namespace std;

istream& f(istream& in)
{
	int v;
	while (in >> v, !in.eof())//ֱ�������ļ���������ֹͣ��ȡ
	{
		if (in.bad())
			throw runtime_error("IO�����󣡣�");
		if (in.fail())
		{
			cerr << "���ݴ��������ԣ�" << endl;
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
	/* IO���� */
	cout << "������һЩ��������control z����" << endl;
	//f(cin);

	cout << "hi!" << endl;	//���hi��һ�����У�Ȼ��ˢ�»�����
	cout << "hi!" << flush;	//���hi��Ȼ��ˢ�»��������������κ��ַ�
	cout << "hi!" << ends;	//���hi��һ�����ַ���Ȼ��ˢ�»�����

	cout << unitbuf;	//������������������ˢ�»�����
	//�κ����������ˢ�£��޻���
	cout << nounitbuf;	//�ص���������ģʽ


	/* �ļ������� fstream oftream iftream */
	
	//��һ��fstream�����뿪���������ʱ����֮�������ļ����Զ��رգ�close���Զ������ã�������һ��ѭ����input���ٴα�����
	//�ļ�ģʽ in ����ʽ��out д��ʽ��app ����ǰ��λ���ļ�β��ate ���ļ���������λ���ļ�β��trunc �ض��ļ���ԭ�����ݻᶪʧ����binary �����Ʒ�ʽ
	//outĬ�Ͼ��ǽضϷ�ʽ

	/* string������ stringstream istringstream ostringstream */
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