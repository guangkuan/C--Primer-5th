#include "Sales_data.h"
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <cassert>
#include <utility>

using namespace std;

typedef pair<vector<Sales_data>::size_type,
              pair<vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator>> matches;

vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(make_pair(it - files.cbegin(), found));
    }
    return ret;
}

void reportResults(istream& in, ostream& os, const vector<vector<Sales_data>>& files)
{
    string s;
    while (in >> s)
    {
        auto trans = findBook(files, s);
        if (trans.empty())
        {
            cout << s << " not found in any stores " << endl << endl;
            continue;
        }
        for (const auto& store : trans)
            os << "store " << store.first << " sales: "
            << accumulate(store.second.first, store.second.second, Sales_data(s))
            << endl;
        cout << endl;
    }
}

vector<Sales_data> build_store(const string& s)
{
    Sales_data item;
    vector<Sales_data> ret;
    ifstream is(s);
    while (read(is, item))
        ret.push_back(item);
    sort (ret.begin(), ret.end(), compareIsbn);
    return ret;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        cerr << "No sales data offered!" << endl;
        return -1;
    }

    vector<vector<Sales_data>> files;
    for (int cnt = 1; cnt != argc; ++cnt)
        files.push_back(build_store(argv[cnt]));

    ifstream in("books.txt");
    reportResults(in, cout, files);
}
