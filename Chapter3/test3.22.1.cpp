/*依次输出text的每一行知道遇到第一个空白行为止*/
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
/*直接使用string遍历会出现错误 empty不起作用 可能是在string中迭代器每次只指向一个字符而非字符串*/
