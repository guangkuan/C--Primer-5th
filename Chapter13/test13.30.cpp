/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class HasPtr
{
    friend swap(HasPtr&, HasPtr&);

public:
    HasPtr(const string& s = string()): ps(new string(s)), i(0), use(new size_t(1)) { }
    HasPtr(const HasPtr& p): ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    string& operator*();
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
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
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class HasPtr
{
    friend swap(HasPtr&, HasPtr&);

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

inline swap(HasPtr& lhs, HasPtr& rhs)
{
    cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(int argc, char* argv[])
{
    HasPtr h("oooooo");
    HasPtr h2(h);
    HasPtr h3 = h;
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    cout << "---------------------->" << endl;
    h2 = "xxxxxx";
    h3 = "======";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    cout << "---------------------->" << endl;
    swap(h2, h3);
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    cout << "---------------------->" << endl;
}
