#include <iostream>
#include <vector>
#include <string>

using namespace std;

void tuozhan(string &s, const string &qianzhui, const string &houzhui)
{
    auto iter = s.begin();
    s.insert(iter, 1, ' ');
    s.insert(iter, qianzhui.begin(), qianzhui.end());
    s.insert(s.size(), 1, ' ');
    auto iter1 = s.end();

    if(houzhui.size())
    {
        auto iter2 = houzhui.end();
        do
            {
                --iter2;
                iter1 = s.insert(iter1, *iter2);
            }
        while(iter2 > houzhui.begin());
    }
}

int main()
{
    string name, qianzhui, houzhui;
    getline(cin, name);
    cout << name << endl;
    cin >> qianzhui >> houzhui;
    tuozhan(name, qianzhui, houzhui);
    cout << name;
    cout << endl;

    return 0;
}
