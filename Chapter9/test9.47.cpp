#include <iostream>
#include <string>

using namespace std;

void chaxun(string &s, const string &chars)
{
    cout << "��" << s << "�в���" << chars << "���ַ�" << endl;
    string::size_type pos = 0;
    while((pos = s.find_first_not_of(chars, pos)) != string::npos)
    {
        cout << "pos: " << pos << ",char: " << s[pos] << endl;
        ++pos;
    }
}

int main()
{
    string yangben;
    getline(cin, yangben);
    cout << yangben << endl;
    cout << "���������ַ�" << endl;
    chaxun(yangben, "0123456789");
    cout << endl << " " << endl;
    chaxun(yangben,"abcdefghijklmnopqrstuvwxyz\
           ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    return 0;
}
