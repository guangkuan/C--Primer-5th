#ifndef MY_QUERYRESULT_H_INCLUDED
#define MY_QUERYRESULT_H_INCLUDED
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <set>
#include "my_StrBlob.h"

using namespace std;

class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    typedef vector<string>::size_type line_no;
    typedef set<line_no>::const_iterator line_it;
    QueryResult(string s, shared_ptr<set<line_no>> p, StrBlob f): sought(s), lines(p), file(f) { }
    set<line_no>::size_type size() const { return lines->size(); }
    line_it begin() const { return lines->cbegin(); }
    line_it end() const { return lines->cend(); }
    StrBlob get_file() { return file; }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    StrBlob file;
};

ostream& print(ostream&, const QueryResult&);

#endif // MY_QUERYRESULT_H_INCLUDED
