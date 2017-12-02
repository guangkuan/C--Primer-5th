#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void add_child(multimap<string, string> &families, const string &family, const string &child)
{
    families.insert({family, child});
}

int main(int argc, char *argv[])
{
    multimap<string, string> families;

    add_child(families, "张", "强");
    add_child(families, "王", "五");
    add_child(families, "张", "刚");

    for (const auto &f : families)
        cout << f.first << "家的孩子： " << f.second << endl;

    return 0;
}
