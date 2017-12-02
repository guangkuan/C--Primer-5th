#include <iostream>
#include <vector>
#include <algorithm>
#include "intCompare.h"

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 2, 1};
    const int oldValue = 2;
    const int newValue = 200;
    IntCompare icmp(oldValue);
    std::replace_if(vec.begin(), vec.end(), icmp, newValue);
    for (auto& v : vec)
        cout << v << " ";
    cout << endl;

    return 0;
}
