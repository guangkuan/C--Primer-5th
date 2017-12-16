#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string s = "Keep out !";
    for (auto &c: s)
    {
        c='X';
    }
    cout << c << endl;
    return 0;
}
