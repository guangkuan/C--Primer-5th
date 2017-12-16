#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    string s;
    vector<string> vString;
    char cont = 'y';
    cout << "请输入一个词语：" << endl;
    while (cin >> s)
    {
        vString.push_back(s);
        cout << "是否继续（y or n）?" << endl;
        cin >> cont;
        if(cont != 'y' && cont != 'Y')
            break;
        cout << "请输入下个词语：" << endl;
    }
    cout << "转换后的结果是：" << endl;
    for (auto &result : vString)
    {
        for (auto &c : result)
        c = toupper(c);
        cout << result << endl;
    }

    return 0;
}
