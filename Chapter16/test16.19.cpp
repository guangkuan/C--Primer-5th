#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename C>
void print1(const C& c)
{
    for (typename C::size_type i = 0; i < c.size(); i++)
        cout << c.at(i) << " ";
    cout << endl;
}

template <typename D>
void print2(const D& d)
{
    for (auto i = d.begin(); i != d.end(); i++)
        cout << *i << " ";
    cout << endl;
}

int main()
{
    string s = "Hello!";
    print1(s);
    print2(s);

    vector<int> vi = {0, 2, 4, 6, 8};
    print1(vi);
    print2(vi);

    list<string> ls = { "Hel", "lo", "!" };
    print2(ls);

    return 0;
}
