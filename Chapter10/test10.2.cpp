#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<string> vString;
    string s1, s2;
    cout << "����Ҫ�ҵ��ַ���" << endl;
    cin >> s2;
    cout << endl;

    cout << "����������" << endl;
    while(cin >> s1)
    {
        vString.push_back(s1);
    }

    cout << count(vString.begin(), vString.end(), s2) << endl;

    return 0;
}
