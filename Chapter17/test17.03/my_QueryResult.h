#ifndef MY_QUERYRESULT_H_INCLUDED
#define MY_QUERYRESULT_H_INCLUDED
#include <memory>
#include <string>
#include <vector>
#include <set>

class QueryResult{
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    typedef std::vector<std::string>::size_type line_no;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) :
        sought(s), lines(p), file(f) { }

    std::set<line_no>::iterator begin() const { return lines->begin();}
    std::set<line_no>::iterator end() const { return lines->end();}
    std::shared_ptr<std::vector<std::string>> get_file() const { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


#endif // MY_QUERYRESULT_H_INCLUDED
