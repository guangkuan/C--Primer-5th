#include <iostream>

using namespace std;

unsigned myCnt()
{
    static unsigned iCnt = -1;
    ++iCnt;
    return iCnt;
}
int main()
{
    cout << "�����������ַ���س���������" << endl;
    char ch;
    while(cin >> ch)
    {
        cout << "����myCnt()ִ�еĴ����ǣ�" <<myCnt() << endl;
    }
    return 0;
}
