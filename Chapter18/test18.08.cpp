#include <iostream>
#include <exception>

using namespace std;

class MyTest_Base
{
public:
    virtual ~MyTest_Base()
    {
        cout << "开始准备销毁一个MyTest_Base类型的对象" << endl;
        try
        {
            throw std::runtime_error("在析构函数中故意抛出一个异常，测试！");
        }
        catch(...) {}
    }
    void Func() throw()
    {
        throw std::runtime_error("故意抛出一个异常，测试！");
    }
    void Other() {}
};

int main()
{
    MyTest_Base m;
    return 0;
}
