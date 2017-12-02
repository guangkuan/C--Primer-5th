#ifndef MY_QUERYRESULT_H_INCLUDED
#define MY_QUERYRESULT_H_INCLUDED
#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <set>
#include "StrVec.h"

using namespace std;

class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    typedef std::size_t line_no;
    typedef set<line_no>::const_iterator line_it;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<StrVec> f): sought(s), lines(p), file(f) { }
    set<line_no>::size_type size() const { return lines->size(); }
    line_it begin() const { return lines->cbegin(); }
    line_it end() const { return lines->cend(); }
    shared_ptr<StrVec> get_file() { return file; }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<StrVec> file;
};

ostream& print(ostream&, const QueryResult&);



#endif // MY_QUERYRESULT_H_INCLUDED
