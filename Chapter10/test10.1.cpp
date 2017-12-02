#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vInt;
    int a, b;
    cout << "请输入要查询的数字：" << endl;
    cin >> b;
    cout << endl;
    cout << "请输入样本：（用空格隔开并输入crtl~z结尾）" << endl;
    while(cin >> a)
    {
        vInt.push_back(a);
    }

    auto iter = vInt.begin();
    cout << count(vInt.begin(), vInt.end(), b) << endl;

    return 0;
}
