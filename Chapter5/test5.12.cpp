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
			break;/*这个break结束的是while语句，不然不会实现本题效果，她是两个一读不管两个以上的连接是什么*/
		}
		break;
		}
	}
	cout << "ff有" << ffcnt << "个" << endl
        << "fl有" << flcnt << "个" << endl
		<< "fi有" << ficnt << "个" << endl;

	return 0;
}
