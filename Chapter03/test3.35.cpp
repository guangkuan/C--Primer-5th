#include <iostream>

using namespace std;

int main()
{
    const int sz = 10;
    int val[sz];
    cout << "��ʼ״̬������������ǣ�" << endl;
    for(int i = 0; i < sz; ++i)
        val[i] = i;
    for(auto a : val)/*ֱ�����val�������ַ��*/
        cout << a << " " ;
    cout <<endl;
    int *p = begin(val);
    while(p != end(val))
    {
        *p = 0;
        ++p;
    }
    cout << "�޸ĺ�����������ǣ�" << endl;
    for(auto b : val)
        cout << b << " ";
    cout << endl;
    return 0;
}
