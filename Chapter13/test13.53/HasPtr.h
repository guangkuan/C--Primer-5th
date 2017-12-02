#ifndef HASPTR_H_INCLUDED
#define HASPTR_H_INCLUDED
#include <string>
#include <algorithm>

using namespace std;

class HasPtr
{
    friend swap(HasPtr&, HasPtr&);

public:
    HasPtr(const string& s = string()): ps(new string(s)), i(0) { cout << "调用构造函数" << endl; }
    HasPtr(const HasPtr& p): ps(new string(*p.ps)), i(p.i) { cout << "调用拷贝构造函数" << endl; }/*为每一个变量保存一个副本*/
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    string& operator*();
    HasPtr& operator=(HasPtr&&) noexcept;
    ~HasPtr();

private:
    string* ps;
    int i;
};

#endif // HASPTR_H_INCLUDED
