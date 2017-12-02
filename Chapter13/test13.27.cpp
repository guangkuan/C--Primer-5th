#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
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

int main(int argc, char* argv[])
{
    HasPtr h("oooooo");
    HasPtr h2 = h;
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "---------------->" << endl;
    h = "xxxxx";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;

    return 0;
}
