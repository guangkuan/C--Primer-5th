#include <iostream>

using namespace std;

void reset(int &a)
{
    a = 0;
}
int main()
{
    int i = 42;
    reset(i);
    cout << "i = " << i << endl;

    return 0;
}
