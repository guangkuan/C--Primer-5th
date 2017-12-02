#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

bool duibi(const string &word, vector<int> &vInt)
{
    auto pos = find_if(vInt.begin(), vInt.end(), bind(check_size, word, _1));
    cout << *pos << endl;
}

int main()
{
    vector<int> shuzi;
    string yangben;
    cin >> yangben;
    int a;
    while (cin >> a)
        shuzi.push_back(a);
    duibi(yangben, shuzi);

    return 0;
}
