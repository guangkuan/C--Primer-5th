#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<char *> slist = {"for" "the" "world" "peace"};
    vector<string> svec;
    svec.assign(slist.cbegin(), slist.cend());
    for(auto it = svec.begin(); it != svec.end() && !it->empty(); ++it)
        cout << *it << endl;

    return 0;
}
