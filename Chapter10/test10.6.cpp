#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> vInt;
    int a;
    while(cin >> a)
        vInt.push_back(a);
    fill_n(vInt.begin(), vInt.size(), 0);
    for(auto iter = vInt.begin(); iter != vInt.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
