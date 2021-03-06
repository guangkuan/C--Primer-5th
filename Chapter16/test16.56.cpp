#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

template <typename T> string debug_rep(const T& t);
template <typename T> string debug_rep(T* p);
string debug_rep(const string&);
string debug_rep(char* p);
string debug_rep(const char *p);

template <typename T>
string debug_rep(const T& t)
{
    ostringstream ret;
    ret << t;
    cout << "use const T&" << endl;
    return ret.str();
}

template <typename T>
string debug_rep(T* p)
{
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << "null pointer";
    cout << "use T*" << endl;
    return ret.str();
}

string debug_rep(const string& s)
{
    cout << "use string&" << endl;
    return '"' + s + '"';
}

string debug_rep(const char* p)
{
    cout << "use const char*" << endl;
    return debug_rep(string(p));
}

string debug_rep(char* p)
{
    cout << "use char*" << endl;
    return debug_rep(string(p));
}

template <typename T>
ostream& print(ostream& os, const T& t)
{
    return os << t << endl;
}

template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

template<typename... Args>
ostream& errorMsg(std::ostream& os, const Args... rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(cout, 1, 2, 3, 4, 9.0f, "sss", "alan");
    return 0;
}
