#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 5;
    int a[sz],b[sz],i;
    srand((unsigned) time (NULL));
    for(i = 0; i < sz; i++)
        a[i] = rand() % 10;
    cout << "系统数据已经生成，请输入你猜测的5个数字（0~9）：" << endl;
    int uVal;
    for(i = 0; i < sz; i++)
        if(cin >> uVal)/*用while程序变慢？ 还要用Ctrl+z截止*/
            b[i] = uVal;
    cout << "系统生成的数据是：" << endl;
    for(auto val : a)
        cout << val << " ";
    cout << endl;
    int *p = begin(a),*q = begin(b);
    while(p != end(a) && q != end(b))
    {
        if(*p != *q)
        {
            cout << "猜测错误。" << endl;
        return -1;
        }
    ++p;
    ++q;
    }
    cout << "全部猜测正确！" << endl;

    return 0;
}
