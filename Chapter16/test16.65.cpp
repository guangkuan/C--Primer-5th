#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

template <typename T> string debug_rep(const T& t);
template <typename T> string debug_rep(T* p);
string debug_rep(const string&);
std::string debug_rep(char* p);
std::string debug_rep(const char *p);

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

int main()
{
    string s("hi");
    const string* sp = &s;
    cout << debug_rep(s) << endl << endl;

    cout << debug_rep(&s) << endl;
    cout << "----------------" << endl;

    cout << debug_rep(sp) << endl;
    cout << "----------------" << endl;

    cout << debug_rep("hi world!") << endl;
    cout << "----------------" << endl;

    char a[] = "How are you?";
    char *p = a;
    cout << debug_rep(p) << endl;

    return 0;
}
