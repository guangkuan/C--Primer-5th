/*�Ա�*/
#include <iostream>

using namespace std;

int compare(int a,int *cp)
{
    if(a > *cp)
       {
           cout << a << "����" << *cp << endl;
           return a;
       }
    else if(a < *cp)
        {
            cout << a << "С��" << *cp << endl;
            return *cp;
        }
    else if(a == *cp)
        {cout << "�������" << endl;
        return -1;}
}
int main()
{
    int i,j;
    cin >> i >> j;
    int *p = &j;
    compare(i,p);

    return 0;
}
