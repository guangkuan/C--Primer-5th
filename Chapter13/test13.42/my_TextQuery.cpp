#include "my_TextQuery.h"
#include "StrVec.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <cstddef>
#include <cctype>
#include <cstring>
#include <utility>

using namespace std;

TextQuery::TextQuery(ifstream& is): file(new StrVec)
{
    string text;
    while (getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            word = cleanup_str(word);
            auto& lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

string TextQuery::cleanup_str(const string& word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it)
    {
        if (!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

QueryResult TextQuery::query(const string& sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(cleanup_str(sought));

    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

string make_plural(size_t sz, const string s1, const string s2)
{
    return (sz > 1) ? s1 + s2 : s1;
}

ostream &print(ostream& os, const QueryResult& qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;

    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << "): " << *(qr.file->begin() + num) << endl;

    return os;
}

void TextQuery::display_map()
{
    auto iter = wm.cbegin(), iter_end = wm.cend();

    for (; iter != iter_end; ++iter)
    {
        cout << "word: " << iter->first << " {";
        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(), loc_iter_end = text_locs->cend();

        while (loc_iter != loc_iter_end)
        {
            cout << *loc_iter;

            if (++loc_iter != loc_iter_end)
                cout << ", ";
        }
        cout << "}\n";
    }
    cout << endl;
}
