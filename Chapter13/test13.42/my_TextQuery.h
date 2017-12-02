#ifndef MY_TEXTQUERY_H_INCLUDED
#define MY_TEXTQUERY_H_INCLUDED
#include <memory>
#include <map>
#include <string>
#include <set>
#include <fstream>
#include "my_QueryResult.h"
#include "StrVec.h"

using namespace std;

class QueryResult;
class TextQuery
{
public:
    using line_no = size_t;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    void display_map();
private:
    shared_ptr<StrVec> file;
    map<string, shared_ptr<set<line_no>>> wm;
    static string cleanup_str(const string&);
};



#endif // MY_TEXTQUERY_H_INCLUDED
