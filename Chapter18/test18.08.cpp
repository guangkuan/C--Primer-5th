#include <iostream>
#include <exception>

using namespace std;

class MyTest_Base
{
public:
    virtual ~MyTest_Base()
    {
        cout << "��ʼ׼������һ��MyTest_Base���͵Ķ���" << endl;
        try
        {
            throw std::runtime_error("�����������й����׳�һ���쳣�����ԣ�");
        }
        catch(...) {}
    }
    void Func() throw()
    {
        throw std::runtime_error("�����׳�һ���쳣�����ԣ�");
    }
    void Other() {}
};

int main()
{
    MyTest_Base m;
    return 0;
}
