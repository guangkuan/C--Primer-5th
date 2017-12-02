#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool bijiao(vector<int> &ivec, list<int> &ilist)
{
    if(ilist.size() != ivec.size())
        return false;
    auto it1 = ilist.begin();
    auto it2 = ivec.begin();
    for(;it1 != ilist.end(); ++it1, ++it2)
        if(*it1 != *it2)
            return false;
    return true;
}

int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7};
    list<int> ilist = {1,2,3,4,5,6,7};
    list<int> ilist1 = {1,2,3,4,5};
    list<int> ilist2 = {1,2,3,4,5,6,8};
    list<int> ilist3 = {1,2,3,4,5,7,6};

    cout << bijiao(ivec, ilist) << endl;
    cout << bijiao(ivec, ilist1) << endl;
    cout << bijiao(ivec, ilist2) << endl;
    cout << bijiao(ivec, ilist3) << endl;

    return 0;
}
