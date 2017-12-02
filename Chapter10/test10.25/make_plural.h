#ifndef MAKE_PLURAL_H_INCLUDED
#define MAKE_PLURAL_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

string make_plural(size_t sz, const string s1, const string s2)
{
    return (sz > 1) ? s1 + s2 : s1;
}

#endif // MAKE_PLURAL_H_INCLUDED
