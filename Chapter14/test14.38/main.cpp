#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "StrLenIs.h"

using namespace std;

int main()
{
    vector<string> vec;
    readStr(cin, vec);
    const int minLen = 1;
    const int maxLen = 10;
    for (int i = minLen; i <= maxLen; i++)
    {
        StrLenIs slenIs(i);
        cout << "len: " << i << ", cnt: " << count_if (vec.begin(), vec.end(), slenIs) << endl;
    }

    return 0;
}
