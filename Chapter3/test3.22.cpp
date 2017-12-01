#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
    vector<string> text;
    string s;
    cout << "请输入字符串：" << endl;
    while(getline(cin,s))
        text.push_back(s);
    for(auto it = text.begin(); it != text.end(); ++it)/*遍历每行字符串*/
    {
        for(auto it2 = it->begin(); it2 != it->end(); it2++)/*遍历一行字符串中的每个字符*/
            *it2 = toupper(*it2);/*toupper只识别字符 不识别字符串*/
        cout << *it << endl;
    }
    return 0;
}
