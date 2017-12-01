#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    vector<int> vInt;
    int vIna;
    cout << "输入一组数字：" << endl;
    while(cin >> vIna)
        vInt.push_back(vIna);
    if(vInt.size() == 0)
    {
        cout << "没有任何数字。" << endl;
        return -1;
    }
    cout << "首位和依次是：" << endl;
    for(decltype(vInt.size())i = 0; i < vInt.size() / 2; ++i)
    {
        cout << vInt[i] + vInt[vInt.size() - i - 1] << " " ;
        if((i + 1) % 5 == 0)
            cout << endl;
    }
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() / 2];

    return 0;
}
