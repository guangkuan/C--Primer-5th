/*����ʧ��,ֻ�ܸı���ʼλ�ò��ܸı�֮���*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    while(cin >> iVal)
    {
        vInt.push_back(iVal);
        if(vInt.size() == 0)
        {
            cout << "û���κ����֡�" << endl;
            return -1;
        }
    }
    auto it = vInt.begin();
    if(*it % 2 != 0)
    {
        *it *= 2;
        ++it;
    }
    for(auto &val : vInt)
        cout << val << " ";
    cout << endl;

    return 0;
}
