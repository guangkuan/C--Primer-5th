#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> vUS(11);
    auto it = vUS.begin();
    int iVal,i = 0;
    cout << "请输入一组乘积（0~100）：" << endl;
    while(cin >> iVal)
        if(iVal < 101)
        {
            ++*(it + iVal / 10);/*将对应分段的位置加1*/
            ++i;
        }
    cout << "总计输入了" << i << "个成绩" << endl;
    cout << "各分段的人数分布式（成绩从低到高）：" << endl;
    for(it = vUS.begin(); it != vUS.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
    return 0;
}
