#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "用法：输入运行程序+文档" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "没有打开文件！" << endl;
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
