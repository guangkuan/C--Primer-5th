#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "������һ�����֣�" << endl; /*����֮��Ҫ�Կո����*/
    while(cin >> iVal)
        vInt.push_back(iVal);
    if(vInt.size() == 0)
    {
        cout << "û������" << endl;
        return -1;
    }
    cout << "��������ĺ������ǣ�" << endl;
    for(decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
    {
        cout << vInt[i] + vInt[i+1] << " ";
        if((i + 2) % 10 == 0)
            cout << endl;
    }
    if(vInt.size() % 2 != 0)
        cout << vInt[vInt.size() - 1];
    return 0;
}
