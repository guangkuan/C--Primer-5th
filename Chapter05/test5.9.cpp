#include <iostream>

using namespace std;

int main()
{
    char ch;
    int i = 0;
    while(cin >> ch)
    {
        if(ch == 'a' || ch == 'A')
            ++i;
            else if(ch == 'e' || ch == 'E')
            ++i;
            else if(ch == 'i' || ch == 'I')
            ++i;
            else if(ch == 'o' || ch == 'O')
            ++i;
            else if(ch == 'u' || ch == 'U')
            ++i;
    }

    cout << i << endl;

    return 0;
}
