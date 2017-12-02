#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string& s = string()): ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& p): ps(new string(*p.ps)), i(p.i) { }/*为每一个变量保存一个副本*/
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    string& operator*();
    ~HasPtr();

private:
    string* ps;
    int i;
};

HasPtr::~HasPtr()
{
    delete ps;
}

inline HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

HasPtr& HasPtr::operator=(const string& rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, char* argv[])
{
    HasPtr h("hi sucker!");
    cout << "h: " << *h << endl;
    cout << "--------------------" << endl;
    HasPtr h2(h);
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "--------------------" << endl;
    HasPtr h3 = h;
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    cout << "--------------------" << endl;
    h2 = "hi buster!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    h3 = "hi brute!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;

    return 0;
}
