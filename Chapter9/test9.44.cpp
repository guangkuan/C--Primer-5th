#include <iostream>
#include <vector>
#include <string>

using namespace std;

void tihuan(string &s, string &oldVal, string &newVal)
{
    string::size_type pos = 0;
    while((pos = s.find(oldVal, pos)) != string::npos)
    {
        s.replace(pos, oldVal.size(), newVal);
        pos += newVal.size();
    }
}

int main()
{
    string yangben, ceshi1, ceshi2;
    getline(cin, yangben);
    cout << yangben;
    cout << endl;
    cin >> ceshi1 >> ceshi2;
    tihuan(yangben, ceshi1, ceshi2);
    cout << yangben << endl;

    return 0;
}
