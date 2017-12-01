#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> v1,v2(10),v3(10,42),v4{10},v5{10,42};
    vector<string> v6{10},v7{10,"hi"};
    for (auto a : v1)
        cout << a;
    cout << endl;
    for (auto b : v2)
        cout << b;
    cout << endl;
    for (auto c : v3)
        cout << c;
    cout << endl;
    for (auto d : v4)
        cout << d;
    cout << endl;
    for (auto e : v5)
        cout << e;
    cout << endl;
    for (auto f : v6)
        cout << f;
    cout << endl;
    for (auto g : v7)
        cout << g;
    cout << endl;
    return 0;
}
