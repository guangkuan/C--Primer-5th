#include <iostream>
#include <string>

using namespace std;

void chaxun(string &s, const string &chars)
{
    cout << "在" << s << "中查找" << chars << "中字符" << endl;
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
    cout << "查找所有字符" << endl;
    chaxun(yangben, "0123456789");
    cout << endl << " " << endl;
    chaxun(yangben,"abcdefghijklmnopqrstuvwxyz\
           ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    return 0;
}
