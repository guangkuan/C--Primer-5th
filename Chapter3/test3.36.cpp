#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 5;
    int a[sz],b[sz],i;
    srand((unsigned) time (NULL));
    for(i = 0; i < sz; i++)
        a[i] = rand() % 10;
    cout << "ϵͳ�����Ѿ����ɣ���������²��5�����֣�0~9����" << endl;
    int uVal;
    for(i = 0; i < sz; i++)
        if(cin >> uVal)/*��while��������� ��Ҫ��Ctrl+z��ֹ*/
            b[i] = uVal;
    cout << "ϵͳ���ɵ������ǣ�" << endl;
    for(auto val : a)
        cout << val << " ";
    cout << endl;
    int *p = begin(a),*q = begin(b);
    while(p != end(a) && q != end(b))
    {
        if(*p != *q)
        {
            cout << "�²����" << endl;
        return -1;
        }
    ++p;
    ++q;
    }
    cout << "ȫ���²���ȷ��" << endl;

    return 0;
}
