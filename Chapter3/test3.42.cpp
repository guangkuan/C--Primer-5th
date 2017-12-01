#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 10;
    int a[sz];
    vector<int> vInt;
    srand((unsigned) time (NULL));
    for(int i = 0; i < sz; ++i)
    {
        vInt.push_back(rand() % 100);
            cout << vInt[i] << " ";
    }
    cout << endl;
    auto it = vInt.begin();
    for(auto &val : a)
    {
        val = *it;
        cout << val << " ";
        ++it;
    }
    cout << endl;

    return 0;
}
