#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vInt;
    int a, b;
    cout << "������Ҫ��ѯ�����֣�" << endl;
    cin >> b;
    cout << endl;
    cout << "���������������ÿո����������crtl~z��β��" << endl;
    while(cin >> a)
    {
        vInt.push_back(a);
    }

    auto iter = vInt.begin();
    cout << count(vInt.begin(), vInt.end(), b) << endl;

    return 0;
}
