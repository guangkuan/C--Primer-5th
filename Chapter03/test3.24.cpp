#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "������һ�����֣�" << endl;
    while(cin >> iVal)
        vInt.push_back(iVal);
    if(vInt.size() == 0)
    {
        cout << "û���κ����֡�" << endl;
        return -1;
    }
    for(auto it = vInt.begin(); it != vInt.end() - 1; it += 2)
    {
        *it = *it + *(it + 1);
        cout << *it << " ";
        if((it - vInt.begin() + 2) % 10 == 0)
        cout << endl;
    }
    if(vInt.size() % 2 != 0)
        cout << *(vInt.end() - 1);

    return 0;
}
