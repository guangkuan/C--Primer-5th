#include "my_TextQuery.h"
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

using std::get;

TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>)
{
    std::string text;
    while(getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while(line >> word)
        {
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}
QueryResult TextQuery::query(const std::string& sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
    os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " "
       << make_plural(get<1>(qr)->size(), "time", "s") << std::endl;
    for(auto num : *get<1>(qr))
        os << "\t(line " << num + 1 << ") "
           << *(get<2>(qr)->begin() + num) << std::endl;
    return os;
}
