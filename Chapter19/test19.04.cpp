#include <iostream>
#include <typeinfo>

using namespace std;

class A
{
public:
    A() {}
    virtual ~A() {}
};

class B : public A
{
public:
    B() {}
    virtual ~B() {}
};

class C : public B
{
public:
    C() {}
    virtual ~C() {}
};

class D : public B, public A
{
public:
    D() {}
    virtual ~D() {}
};

int main()
{
    A *pa = new C;
    try
    {
        B& pb = dynamic_cast<B&> (*pa);
    }
    catch (std::bad_cast& bc)
    {
        cout << "dynamic_cast failed" << endl;
    }
    cout << "-------------------------1" << endl;

    B *pb = new B;
    try
    {
        C& pc = dynamic_cast<C&> (*pb);
    }
    catch (std::bad_cast& bc)
    {
        cout << "dynamic_cast failed" << endl;
    }
    cout << "-------------------------2" << endl;

//    A *pa = new D;
//    try
//    {
//        B& pb = dynamic_cast<B&> (*pa);
//    }
//    catch (std::bad_cast& bc)
//    {
//        cout << "dynamic_cast failed" << endl;
//    }

    return 0;
}
