#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
    vector<string> text;
    string s;
    cout << "�������ַ�����" << endl;
    while(getline(cin,s))
        text.push_back(s);
    for(auto it = text.begin(); it != text.end(); ++it)/*����ÿ���ַ���*/
    {
        for(auto it2 = it->begin(); it2 != it->end(); it2++)/*����һ���ַ����е�ÿ���ַ�*/
            *it2 = toupper(*it2);/*toupperֻʶ���ַ� ��ʶ���ַ���*/
        cout << *it << endl;
    }
    return 0;
}
