#include<iostream>

using namespace std;

int main()
{
	char ch;
	int ffcnt= 0, flcnt= 0, ficnt= 0;
	while (cin >> ch)
	{
		switch (ch)
		{
		case'f':
		    while (cin >> ch)
		{
			switch (ch)
			{
			    case'f':
			    ++ffcnt;
				break;
			case'l':
			    ++flcnt;
				break;
			case'i':
			    ++ficnt;
				break;
			}
			break;/*���break��������while��䣬��Ȼ����ʵ�ֱ���Ч������������һ�������������ϵ�������ʲô*/
		}
		break;
		}
	}
	cout << "ff��" << ffcnt << "��" << endl
        << "fl��" << flcnt << "��" << endl
		<< "fi��" << ficnt << "��" << endl;

	return 0;
}
