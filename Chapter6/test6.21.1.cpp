#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int myCompare(const int val,const int *p)
{
    return (val > *p) ? val : *p;
}
int main()
{
    srand((unsigned) time (NULL));
    int a[10];
    for(auto &i : a)
        i = rand() % 100;
    cout << "������һ������ ";
    int j;
    cin >> j;
    cout << "���������������Ԫ�ؽϴ���ǣ�" << myCompare(j,a) << endl;
    cout << "�����е�ȫ��Ԫ���ǣ�" << endl;
    for(auto i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
