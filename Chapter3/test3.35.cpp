#include <iostream>

using namespace std;

int main()
{
    const int sz = 10;
    int val[sz];
    cout << "初始状态的数组的内容是：" << endl;
    for(int i = 0; i < sz; ++i)
        val[i] = i;
    for(auto a : val)/*直接输出val是数组地址！*/
        cout << a << " " ;
    cout <<endl;
    int *p = begin(val);
    while(p != end(val))
    {
        *p = 0;
        ++p;
    }
    cout << "修改后数组的内容是：" << endl;
    for(auto b : val)
        cout << b << " ";
    cout << endl;
    return 0;
}
