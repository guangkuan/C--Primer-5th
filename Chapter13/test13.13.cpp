#include <iostream>
#include <vector>

using namespace std;

struct X
{
    X() { cout << "A. 构造函数 X()" << endl; }
    X(const X&) { cout << "B. 拷贝构造函数 X(const X&)" << endl; }
    X& operator=(const X& rhs) {  cout << "C. 拷贝赋值运算符 =(const X&)" << endl; return *this; }
    ~X() { cout << "D. 析构函数 ~X()" << endl; }
};

void f1(X x)
{

}

void f2(X &x)
{

}

int main(int argc, char* argv[])
{
    cout << "1 局部变量：" << endl;
    X x;
    cout << endl;

    cout << "2 非引用参数传递：" << endl;
    f1(x);
    cout << endl;

    cout << "3 引用参数传递：" << endl;
    f2(x);
    cout << endl;

    cout << "4 动态分配：" << endl;
    X *px = new X;
    cout << endl;

    cout << "5 添加到容器：" << endl;
    vector<X> vx;
    cout << "*******************************" << endl;
    vx.push_back(x);/*某些类类型还会对它们所分配的对象使用拷贝初始化*/
    cout << endl;

    cout << "6 释放动态分配对象：" << endl;
    delete px;
    cout << endl;

    cout << "7 间接初始化和赋值：" << endl;
    X y = x;
    cout << "*******************************" << endl;
    y = x;/*对类对象进行赋值时， 会使用拷贝赋值运算符*/
    cout << endl;

    cout << "8 程序结束" << endl;
    return 0;
}
