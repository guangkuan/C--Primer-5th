#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    string s;
    vector<string> vString;
    char cont = 'y';
    cout << "������һ�����" << endl;
    while (cin >> s)
    {
        vString.push_back(s);
        cout << "�Ƿ������y or n��?" << endl;
        cin >> cont;
        if(cont != 'y' && cont != 'Y')
            break;
        cout << "�������¸����" << endl;
    }
    cout << "ת����Ľ���ǣ�" << endl;
    for (auto &result : vString)
    {
        for (auto &c : result)
        c = toupper(c);
        cout << result << endl;
    }

    return 0;
}
