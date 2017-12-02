#include <iostream>
#include "myStrBlob.h"

using namespace std;

int main(int argc, char* argv[])
{
    StrBlob b1;/*b1��b2�����ڴ�b2ɾ����b1��������������*/
    {
        StrBlob b2 = { "Word", "of", "Warcraft" };
        b1 = b2;/*������ֵ*/
        cout << "b1��СΪ" << b1.size() << endl;
        cout << "b1��βԪ��Ϊ" << b1.front() << " " << b1.back() << endl;
        cout << endl;

        b2.push_back("III");/*push��Ա��Զ���Ԫ�ؽ��п�����ʼ��*/
        cout << "b2��СΪ" << b2.size() << endl;
        cout << "b2��βԪ��Ϊ" << b2.front() << " " << b2.back() << endl;
        cout << endl;
    }

    cout << "b1��СΪ" << b1.size() << endl;
    cout << "b1��βԪ��Ϊ" << b1.front() << " " << b1.back() << endl;
    cout << "----------------------------->" << endl;

    StrBlob b3 = b1;/*��������*/
    b3.push_back("ova");
    cout << "b3��СΪ" << b3.size() << endl;
    cout << "b3��βԪ��Ϊ" << b3.front() << " " << b3.back() << endl;
    cout << "b3��ȫ��Ԫ�أ�" << endl;
    for (auto it = b3.begin(); neq(it, b3.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << endl;

    cout << "b1��СΪ" << b1.size() << endl;
    cout << "b1��ȫ��Ԫ�أ�" << endl;
    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << "----------------------------->" << endl;

    StrBlob b4 = b3;
    cout << "b4��ȫ��Ԫ�أ�" << endl;
    for (auto it = b4.begin(); neq(it, b4.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << endl;
    b4 = b1;
    cout << "b4��ȫ��Ԫ�أ�" << endl;
    for (auto it = b4.begin(); neq(it, b4.end()); it.incr())
        cout << it.deref() << " ";
    cout << endl;
    cout << "----------------------------->" << endl;

    return 0;
}
