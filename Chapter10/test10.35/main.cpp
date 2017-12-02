#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "�÷����������г���+�ĵ�" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "û�д��ļ���" << endl;
        exit(1);
    }

    vector<int> vi;
    int v;
    while(in >> v)
        vi.push_back(v);

    for(auto iter = (vi.end() - 1); iter != (vi.begin() - 1); --iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
