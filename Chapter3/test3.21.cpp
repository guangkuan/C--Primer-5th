#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
    vector<int> v1,v2(10),v3(10,42),v4{10},v5{10,42};
    vector<string> v6{10},v7{10,"hi"};
    if(v1.cbegin() != v1.cend())
    {
        cout << "输出v1：" << endl;
        for (auto a = v1.cbegin(); a != v1.cend(); ++a)
        cout << *a << endl;
    }
    if(v2.cbegin() != v2.cend())
    {
        cout << "输出v2：" << endl;
        for (auto b = v2.cbegin(); b != v2.cend(); ++b)
        cout << *b ;
        cout << endl;
    }
    if(v3.cbegin() != v3.cend())
    {
        cout << "输出v3：" << endl;
        for (auto c = v3.cbegin(); c != v3.cend(); ++c)
        cout << *c ;
        cout << endl;
    }
    if(v4.cbegin() != v4.cend())
    {
        cout << "输出v4：" << endl;
        for (auto d = v4.cbegin(); d != v4.cend(); ++d)
        cout << *d ;
        cout << endl;
    }
    if(v5.cbegin() != v5.cend())
    {
        cout << "输出v5：" << endl;
        for (auto e = v5.cbegin(); e != v5.cend(); ++e)
        cout << *e ;
        cout << endl;
    }
    if(v6.cbegin() != v6.cend())
    {
        cout << "输出v6：" << endl;
        for (auto e = v6.cbegin(); e != v6.cend(); ++e)
        cout << *e ;
        cout << endl;
    }
    if(v7.cbegin() != v7.cend())
    {
        cout << "输出v7：" << endl;
        for (auto f = v7.cbegin(); f != v7.cend(); ++f)
        cout << *f ;
        cout << endl;
    }
    return 0;
}
