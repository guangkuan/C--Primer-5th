#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    bool bl = true;
    cout << "������һ���ַ�����" << endl;
    while(cin >> s1)
    {
        if(!isupper(s1[0]))
            continue;
        if(s1 == s2)
        {
            bl = false;
            cout << "������������" << s1 << endl;
            break;
        }
        s2 = s1;
    }
    if(bl)
        cout << "û�г�������������ͬ�ĵ���" << endl;

    return 0;
}
