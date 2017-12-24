#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <iostream>

using namespace std;

struct base
{
    base(string szNm): basename(szNm) {}
    string name()
    {
        cout << "调用基类name" << endl;
        return basename;
    }
    virtual void print(ostream& os)
    {
        os << basename;
        os << "调用基类虚函数" << endl;
    }

private:
    string basename;
};

struct derived : public base
{
    derived(string szName, int iVal): base(szName), mem(iVal) {}
    void print(ostream& os)
    {
        base::print(os);
        os << "--" << mem;
        os << "调用派生类类虚函数" << endl;
    }

private:
    int mem;
};


#endif // BASE_H_INCLUDED
