#include "my_TextQuery.h"
//#include "make_plural.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using namespace std;

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


int main(int argc, char* argv[])
{
    ifstream in (argv[1]);
    if (!in)
    {
        cout << "文件无法打开！" << endl;
        exit(1);
    }

    display_map
    return 0;
}
