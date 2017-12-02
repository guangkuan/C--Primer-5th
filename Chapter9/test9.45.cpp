#include <iostream>
#include <vector>
#include <string>

using namespace std;

void tianzhui(string &s, const string &s1, const string &s2)
{
    s.insert(s.begin(), 1, ' ');
    s.insert(s.begin(), s1.begin(), s1.end());/*迭代器作插入位置时,插入形式有(n,c),(b2,e2),(初始化列表)，不能直接插入字符串s1*/
    s.append(" ");
    s.append(s2);
    cout << s;
    cout << endl;
}

int main()
{
    string name, qianzhui, houzhui;
    getline(cin, name);
    cout << name << endl;
    cin >> qianzhui >> houzhui;
    tianzhui(name, qianzhui, houzhui);

    return 0;
}
