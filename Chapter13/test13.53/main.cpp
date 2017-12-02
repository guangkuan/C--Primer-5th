#include <iostream>
#include "HasPtr.h"

using namespace std;

HasPtr::~HasPtr()
{
    delete ps;
}

inline HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    cout << "调用赋值函数1" << endl;
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

HasPtr& HasPtr::operator=(const string& rhs)
{
    cout << "调用赋值函数2" << endl;
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

inline HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept
{
    cout << "调用移动赋值函数" << endl;
    if (this != &rhs)
    {
        delete ps;
        ps = rhs.ps;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}

inline swap(HasPtr& lhs, HasPtr& rhs)
{
    cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(int argc, char* argv[])
{
    HasPtr h("Young and Beautiful");
    HasPtr h1;
    h1 = h;
    HasPtr h2 = std::move(h); // now hp can't be used again, because it refers to null
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "---------------------->" << endl;

    /*HasPtr h3("Young and Beautiful");
    HasPtr h4;
    h4 = h3;
    HasPtr h4("Take him away"); // now hp can't be used again, because it refers to null
    h4 = std::move(h3);
    cout << "h3: " << *h3 << endl;
    cout << "h4: " << *h4 << endl;
    cout << "---------------------->" << endl;*/

    return 0;
}
