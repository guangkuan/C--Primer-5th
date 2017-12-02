#include <iostream>
#include <vector>
#include <string>

using namespace std;

void tihuan(string &s, string &oldVal, string &newVal)
{
    auto len = oldVal.size();
    if(!len)
        return;
    auto iter = s.begin();
    while(iter != s.end())
    {
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        while(iter2 != oldVal.end() && *iter1 == *iter2)
        {
            iter1++;
            iter2++;
        }
        if(iter2 == oldVal.end())
        {
            iter = s.erase(iter, iter1);
            if(newVal.size())
                {
                    iter2 = newVal.end();/*由后至前逐个插入newVal中的字符*/
                do
                {
                    iter2--;
                    iter = s.insert(iter, *iter2);
                }
                while(iter2 > newVal.begin());
                }
            iter += newVal.size();
        }
        else
            iter++;
    }
}

int main()
{
    string yangben, ceshi1, ceshi2;
    getline(cin, yangben);
    cout << yangben;
    cout << endl;
    cin >> ceshi1 >> ceshi2;
    tihuan(yangben, ceshi1, ceshi2);
    cout << yangben << endl;

    return 0;
}
