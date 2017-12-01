#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vInt;
    const int sz = 10;
    srand((unsigned) time (NULL));
    for(int i = 0; i != sz; ++i)
    {
        vInt.push_back(rand() % 100);
        cout << vInt[i] << " ";
    }
    cout << endl;
    for(auto &val : vInt)
        val = (val % 2 != 0) ? val * 2 : val;
    for(auto it = vInt.begin(); it != vInt.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
