#ifndef MAKE_PLURAL_H_INCLUDED
#define MAKE_PLURAL_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}


#endif // MAKE_PLURAL_H_INCLUDED
