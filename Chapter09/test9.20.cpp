#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> ilist{1,2,3,4,5,6,7,8};
    deque<int> idjishu,idoushu;
    auto it = ilist.begin();
    auto it1 = idjishu.begin();
    auto it2 = idoushu.begin();
    for(it = ilist.begin(); it != ilist.end(); ++it)
    {
        if(*it % 2)
        {
            it1 = idjishu.insert(it1,*it);
        }
        else
            it2 = idoushu.insert(it2,*it);
    }
    cout << "奇数列为：" ;
    for(it1 = idjishu.begin(); it1 != idjishu.end(); ++it1)
        cout << *it1 << " ";
    cout << endl;
    cout << "偶数列为：" ;
    for(it2 = idoushu.begin(); it2 != idoushu.end(); ++it2)
        cout << *it2 << " ";
    cout << endl;

    return 0;
}
