#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt1;
    vector<int> vInt2;
    for(int i = 0; i < 10; ++i)
        vInt1.push_back(i);
    for(int j = 0; j < 10; ++j)
        vInt2.push_back(vInt1[j]);
    for(auto it : vInt2)
        cout << it << " ";
    cout << endl;

    return 0;
}
