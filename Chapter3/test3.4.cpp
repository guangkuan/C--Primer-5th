#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1,s2;
    cout << "��������������" << endl;
    cin >> s1 >> s2;
    auto length1 = s1.size();
    auto length2 = s2.size();
    if (length1 == length2)
        cout << "������һ��" << endl;
    else if (length1 > length2)
        cout << "s1>s2" << endl;
    else
        cout << "s1<s2" << endl;
    return 0;
}
