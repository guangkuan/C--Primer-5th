#include <iostream>

using namespace std;

void jiaohuan(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}
int main()
{
    int a1,b1;
    cin >> a1 >> b1;
    cout << "交换前：a1 = " << a1 << ",b1 = " << b1 << endl;
    jiaohuan(a1,b1);
    cout << "交换之后： a1 = " << a1 << ",b1 = " << b1 << endl;

    return 0;
}
