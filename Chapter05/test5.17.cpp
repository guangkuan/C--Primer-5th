#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {0,1,1,2};
    vector<int> v2 = {0,1,1,2,3,5,8};
    vector<int> v3 = {3,5,8};
    vector<int> v4 = {3,5,0,9,2,7};
    auto it1 = v1.cbegin();
    auto it2 = v2.cbegin();
    auto it3 = v3.cbegin();
    auto it4 = v4.cbegin();
    while(it1 != v1.end() && it2 != v2.end())
    {
        if(*it1 != *it2)
        {
            cout << "v1��v2֮�䲻����ǰ׺��ϵ��" << endl;
            break;
        }
        ++it1;
        ++it2;
    }
    if(it1 == v1.end())
    {
        cout << "v1��v2��ǰ׺��" << endl;
    }
    if(it2 == v2.end())
    {
        cout << "v2��v1��ǰ׺��" << endl;
    }

    return 0;
}
