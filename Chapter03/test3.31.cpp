#include <iostream>

using namespace std;

int main()
{
    const int sz = 10;
    int val1[sz],val2[sz];
    for(int i = 0; i < sz; ++i)
        val1[i] = i;
    for(int j = 0; j < sz; ++j)
        val2[j] = val1[j];
    for(auto a : val2)/*直接输出val是数组地址！*/
        cout << a << " " ;
    cout <<endl;

    return 0;
}
