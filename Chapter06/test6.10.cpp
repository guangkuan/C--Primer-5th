#include <iostream>

using namespace std;

void mySWAP(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
    p = 0;
}
int main()
{
    int a,b;
    cin >> a >> b;
    int *r = &a,*s = &b;
    cout << "交换之前: a = " << a << ",b = " << b << endl;
    cout << r << "   " << *r << endl;
    mySWAP(r,s);
    cout << "交换之后: a = " << a << ",b = " << b << endl;
    cout << r << "   " << *r << endl;

    return 0;
}
