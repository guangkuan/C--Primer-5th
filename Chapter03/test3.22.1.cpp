/*�������text��ÿһ��֪��������һ���հ���Ϊֹ*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> text;
    string s;
    while(getline(cin,s))
        text.push_back(s);
    for(auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
        cout << *it << endl;
    return 0;
}
/*ֱ��ʹ��string��������ִ��� empty�������� ��������string�е�����ÿ��ָֻ��һ���ַ������ַ���*/
