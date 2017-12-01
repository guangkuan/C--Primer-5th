#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    bool bl = true;
    cout << "请输入一串字符串：" << endl;
    while(cin >> s1)
    {
        if(!isupper(s1[0]))
            continue;
        if(s1 == s2)
        {
            bl = false;
            cout << "出现连续两串" << s1 << endl;
            break;
        }
        s2 = s1;
    }
    if(bl)
        cout << "没有出现连续两串相同的单词" << endl;

    return 0;
}
