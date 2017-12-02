#ifndef MY_TEXTQUERY_H_INCLUDED
#define MY_TEXTQUERY_H_INCLUDED
#include <memory>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <fstream>
//#include "my_QueryResult.h"

using namespace std;

class QueryResult;
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(std::ifstream&);
    //QueryResult query(const string&) const;
    void display_map();
private:
    //StrBlob file;
    map<string, shared_ptr<set<line_no>>> wm;
    static string cleanup_str(const string&);
};


#endif // MY_TEXTQUERY_H_INCLUDED
