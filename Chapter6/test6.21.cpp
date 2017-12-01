/*自编*/
#include <iostream>

using namespace std;

int compare(int a,int *cp)
{
    if(a > *cp)
       {
           cout << a << "大于" << *cp << endl;
           return a;
       }
    else if(a < *cp)
        {
            cout << a << "小于" << *cp << endl;
            return *cp;
        }
    else if(a == *cp)
        {cout << "二者相等" << endl;
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
