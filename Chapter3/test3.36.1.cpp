#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 5;
    int i;
    vector<int> a,b;
    srand((unsigned) time (NULL));
    for(i = 0; i < sz; i++)
        a.push_back(rand() % 10);
    cout << "随机序列已生成，请开始你的表演" << endl;
    cout << "你的幸运数字是：" << endl;
    int uVal;
    for(i = 0; i < sz; i++)
        if(cin >> uVal)
            b.push_back(uVal);
    cout << "真正的谜底是：" << endl;
    for(auto val : a)
        cout << val << " ";
    cout << endl;
    cout << "而你的答案" << endl;
    for(auto val : b)
        cout << val << " ";
    cout << endl;
    auto it1 = a.begin(),it2 = b.begin();
    while (it1 != a.cend() && it2 != b.cend())
    {
        if(*it1 != *it2)
        {
            cout << "猜错了，智障。" << endl;
            return -1;
        }
        ++it1;
        ++it2;
    }
    cout << "走狗屎运了。" << endl;

    return 0;
}
