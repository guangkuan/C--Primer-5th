#include <iostream>
#include <string>

using namespace std;

int main()
{
    do{
        string s1,s2;
        cout << "�����������ַ�����" << endl;
        cin >> s1 >> s2;
    if(s1.size() < s2.size())
    {
        cout << s1 << endl;
    }
    else if(s1.size() > s2.size())
        cout << s2 << endl;
    if(s1.size() == s2.size())
        cout << "�����ַ������" << endl;
    }
    while(cin);

    return 0;
}
