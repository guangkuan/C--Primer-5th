#ifndef MATCHES_H_INCLUDED
#define MATCHES_H_INCLUDED
#include "Sales_data.h"
#include <utility>
#include <vector>

using namespace std;

class matches
{
public:
    matches(vector<Sales_data>::size_type n,
            pair<vector<Sales_data>::const_iterator,
            vector<Sales_data>::const_iterator> f)
            : num(n), first(f.first), last(f.second) {}
    vector<Sales_data>::size_type get_num() const { return num; }
    vector<Sales_data>::const_iterator get_first() const { return first; }
    vector<Sales_data>::const_iterator get_last() const { return last; }

private:
    vector<Sales_data>::size_type num;
    vector<Sales_data>::const_iterator first, last;
};


#endif // MATCHES_H_INCLUDED
