#ifndef ERRORMSG_H_INCLUDED
#define ERRORMSG_H_INCLUDED
#include <sstream>

using std::cout;
using std::endl;
using std::string;

template <typename T>


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


#endif // ERRORMSG_H_INCLUDED
