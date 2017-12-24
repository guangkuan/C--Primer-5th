#ifndef TSCREEN_H_INCLUDED
#define TSCREEN_H_INCLUDED
#include <string>
#include <iostream>

template <int H, int W> class Screen;

template <int H, int W>
std::ostream& operator<<(std::ostream&, Screen<H, W>&);

template <int H, int W>
std::istream& operator>>(std::istream&, Screen<H, W>&);

template <int H, int W>
class Screen
{
    /*在模板类中声明友元函数，分四种类型：
    1. 不需要模板参数的非模板函数。
    2. 需要模板参数的非模板函数。
    3. 需要模板参数的模板函数，使用类模板参数特化。
    4. 需要模板参数的模板函数，自带模板参数。

    template <typename V>
    class A;
    template <typename V>
    void f3(A<V>& a);
    template <typename T>
    class A
    {
    public:
        friend void f1();
        friend void f2(A<T>& a);
        friend void f3<T>(A<T>& a);
        template <typename U>
        friend void f4(A<U>& a);
    private:
        T v;
    };*/

    friend std::ostream& operator<< <H, W>(std::ostream&, Screen<H, W>&);
    friend std::istream& operator>> <H, W>(std::istream&, Screen<H, W>&);

public:
    Screen(): contents(H * W, ' ') {}
    Screen(char c): contents(H * W, c) {}
//    friend class Window_mgr;
    char get() const
    {
        return contents[cursor];
    }
    inline char get(int, int) const;
    Screen& clear(char = bkground);

private:
    static const char bkground = ' ';

public:
    Screen& move(int r, int c);
    Screen& set(char);
    Screen& set(int, int, char);
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }
    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream& os) const
    {
        os << contents;
    }
    int cursor = 0;
    std::string contents;
};

template <int H, int W>
Screen<H, W>& Screen<H, W>::clear(char c)
{
    contents = std::string(H * W, c);
    return *this;
}

template <int H, int W>
inline Screen<H, W>& Screen<H, W>::move(int r, int c)
{
    int row = r * W;
    cursor = row + c;
    return *this;
}

template <int H, int W>
char Screen<H, W>::get(int r, int c) const
{
    int row = r * W;
    return contents[row + c];
}

template <int H, int W>
inline Screen<H, W>& Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <int H, int W>
std::ostream& operator<<(std::ostream& os, Screen<H, W>& s)
{
    os << s.contents;
    return os;
}

template <int H, int W>
std::istream& operator>>(std::istream& is, Screen<H, W>& s)
{
//    char c;
//    for(int i = 0; i < (H * W); ++i)
//    {
//        is >> c;
//        s.contents[i] = c;
//    }
//    return is;
    std::string t;
    is >> t;
    s.contents = t.substr(0, H * W);
    return is;
}

#endif // TSCREEN_H_INCLUDED
