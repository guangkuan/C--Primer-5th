#include <iostream>
#include <vector>

using namespace std;

struct X
{
    X() { cout << "A. ���캯�� X()" << endl; }
    X(const X&) { cout << "B. �������캯�� X(const X&)" << endl; }
    X& operator=(const X& rhs) {  cout << "C. ������ֵ����� =(const X&)" << endl; return *this; }
    ~X() { cout << "D. �������� ~X()" << endl; }
};

void f1(X x)
{

}

void f2(X &x)
{

}

int main(int argc, char* argv[])
{
    cout << "1 �ֲ�������" << endl;
    X x;
    cout << endl;

    cout << "2 �����ò������ݣ�" << endl;
    f1(x);
    cout << endl;

    cout << "3 ���ò������ݣ�" << endl;
    f2(x);
    cout << endl;

    cout << "4 ��̬���䣺" << endl;
    X *px = new X;
    cout << endl;

    cout << "5 ��ӵ�������" << endl;
    vector<X> vx;
    cout << "*******************************" << endl;
    vx.push_back(x);/*ĳЩ�����ͻ��������������Ķ���ʹ�ÿ�����ʼ��*/
    cout << endl;

    cout << "6 �ͷŶ�̬�������" << endl;
    delete px;
    cout << endl;

    cout << "7 ��ӳ�ʼ���͸�ֵ��" << endl;
    X y = x;
    cout << "*******************************" << endl;
    y = x;/*���������и�ֵʱ�� ��ʹ�ÿ�����ֵ�����*/
    cout << endl;

    cout << "8 �������" << endl;
    return 0;
}
