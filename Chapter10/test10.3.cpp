#include <iostream>
#include <vector>
//#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> vInt;
    int a;
    while(cin >> a)
    {
        vInt.push_back(a);
    }

    cout << accumulate(vInt.begin(), vInt.end(), 0) << endl;

    return 0;
}
