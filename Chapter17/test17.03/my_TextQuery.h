#ifndef MY_TEXTQUERY_H_INCLUDED
#define MY_TEXTQUERY_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <memory>
#include <map>
#include <tuple>

typedef std::vector<std::string>::size_type line_no ;
typedef std::set<line_no>::const_iterator line_it;
typedef std::tuple<std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>> QueryResult;

class TextQuery{
public:
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    void display_map();

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    static std::string cleanup_str(const std::string&);
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif // MY_TEXTQUERY_H_INCLUDED
