#include <iostream>
#include <forward_list>
//#include <string>/*ÈÝÆ÷²»ÓÃ¼Óstring*/

using namespace std;

void test_insert(forward_list<string> &sflst, const string &s1, const string &s2)
{
    auto prev = sflst.before_begin();
    auto curr = sflst.begin();
    bool meicedao = true;

    while(curr != sflst.end())
    {
        if(*curr == s1)
            {
                curr = sflst.insert_after(curr, s2);
                meicedao = false;
            }
        else
            {
                prev = curr;
                ++curr;
            }
    }


    if(meicedao)
    {
        sflst.insert_after(prev, s2);
    }
}


int main()
{
    forward_list<string> yangben{"for", "the", "world", "peace"};
    string ceshi1,ceshi2;
    cin >> ceshi1 >> ceshi2;

    test_insert(yangben, ceshi1, ceshi2);
    auto it = yangben.begin();
    for(it; it != yangben.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
