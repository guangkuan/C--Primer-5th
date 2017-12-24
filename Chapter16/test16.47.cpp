#include <utility>
#include <iostream>

using std::cout;
using std::endl;

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int& v2)
{
    cout << v1 << " " << ++v2 << endl;
}

void g(int&& i, int& j)
{
    cout << i << " " << j << endl;
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
    f(t2, t1);
}

int main()
{
    int i = 0, j = 0, k = 0, l = 0;
    cout << i << " " << j << " " << k << " " << l << endl;

    f(42, i);//int& 会改变i的值
    cout << i << endl;
    cout << "----------------" << endl;

    flip1(f, j, 42);
    cout << j << endl;
    cout << "----------------" << endl;

    flip2(f, k, 42);
    cout << k << endl;//int&& T会被解释成int型
    cout << "----------------" << endl;

    g(1, i);
    flip(g, i, 42);
    cout << i << endl;//有forward
    cout << "----------------" << endl;

    cout << i << " " << j << " " << k << " " << l << endl;

    return 0;
}
