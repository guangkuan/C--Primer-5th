#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family)
{
    if (families.find(family) == families.end())
        families[family];
}

void add_child_birth(map<string, vector<pair<string, string>>> &families, const string &family, const string &child, const string &birth)
{
    families[family].push_back(pair<string, string>(child, birth));
}

int main(int arc, char argv[])
{
    map<string, vector<pair<string, string>>> families;

    add_family(families, "��");
    add_child_birth(families, "��", "ǿ", "98.04.26");
    add_child_birth(families, "��", "��", "94.05.14");
    add_child_birth(families, "��", "��", "95.09.24");
    add_family(families, "��");

    for (auto f : families)
    {
        cout << f.first << "�ҵĺ���: " << endl;
        for (auto c : f.second)
            cout << c.first << " �ĳ��������ǣ�" << c.second << endl;
        cout << endl;
    }

    return 0;
}
